//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	printf("ù��° ���ڸ� �Է��Ͻÿ�:");	// �Է� �ȳ� �޽��� ���
	int x;
	scanf("%d", &x);			// �ϳ��� ������ �޾Ƽ� x�� ����

	printf("�ι�° ���ڸ� �Է��Ͻÿ�:");	// �Է� �ȳ� �޽��� ���
	int y;
	scanf("%d", &y);			// �ϳ��� ������ �޾Ƽ� x�� ����

	int sum = x + y;			// ���� 2���� ���Ѵ�.
	printf("�μ��� ��: %d", sum);		// sum�� ���� 10���� ���·� ���

	return 0;			// 0�� �ܺη� ��ȯ
}
