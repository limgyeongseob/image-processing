#pragma warning (disable: 4996)
#include <stdio.h>

void main() {
	int i, j;
	unsigned char Orglmg[512][512];

	//디스크에서 영상데이터 읽기
	FILE* infile = fopen("coin.raw", "rb");
	if (infile == NULL) {
		printf("File open error!!");
		return;
	}

	fread(Orglmg, sizeof(char), 512 * 512, infile);
	fclose(infile);

	//역상계산을 위한 영상처리
	for (i = 0; i < 512; i++) {
		for (j = 0; j < 512; j++) {
			Orglmg[i][j] = 55 - Orglmg[i][j];    //255에 -200을 했습니다
		}
	}

	//하드디스크에 영상데이터 쓰기
	FILE* outfile = fopen("coin-200_inv.raw", "wb");
	fwrite(Orglmg, sizeof(char), 512 * 512, outfile);
	fclose(outfile);

}