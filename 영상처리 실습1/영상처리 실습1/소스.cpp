#pragma warning (disable: 4996)
#include <stdio.h>

void main() {
	int i, j;
	unsigned char Orglmg[512][512];

	//��ũ���� �������� �б�
	FILE* infile = fopen("coin.raw", "rb");
	if (infile == NULL) {
		printf("File open error!!");
		return;
	}

	fread(Orglmg, sizeof(char), 512 * 512, infile);
	fclose(infile);

	//�������� ���� ����ó��
	for (i = 0; i < 512; i++) {
		for (j = 0; j < 512; j++) {
			Orglmg[i][j] = 55 - Orglmg[i][j];    //255�� -200�� �߽��ϴ�
		}
	}

	//�ϵ��ũ�� �������� ����
	FILE* outfile = fopen("coin-200_inv.raw", "wb");
	fwrite(Orglmg, sizeof(char), 512 * 512, outfile);
	fclose(outfile);

}