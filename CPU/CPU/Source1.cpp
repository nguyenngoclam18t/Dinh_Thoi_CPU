#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
	int pid;
	int tgthucthi;
	int tgxuly;
	int tgcho;
}tientrinh;

void tinhtgcho(tientrinh p[], int n);
void sapxep(tientrinh p[], int n);
void tinhtgxuly(tientrinh p[], int n);
void inbang(tientrinh p[], int n);
void bieudogantt(tientrinh p[], int n);

int tongtgcho;
int tongtgxuly;
double tgchotb;
double tgxulytb;

void tinhtgcho(tientrinh p[], int n)
{
	int i;
	tongtgcho = 0;
	p[0].tgcho = 0;
	for (i = 1; i < n; i++)
	{
		p[i].tgcho = p[i - 1].tgcho + p[i - 1].tgthucthi;
		tongtgcho += p[i].tgcho;
	}
}

void tinhtgxuly(tientrinh p[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		p[i].tgxuly = p[i].tgcho + p[i].tgthucthi;
		tongtgxuly += p[i].tgxuly;
	}
}

void sapxep(tientrinh p[], int n)
{
	int i, j;
	tientrinh temp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (p[j].tgthucthi > p[j + 1].tgthucthi)
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

void inbang(tientrinh p[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		puts("*-------*--------------------*---------------*----------------*");
		puts("|  PID  | Thoi gian thuc thi | Thoi gian cho | Thoi gian xu ly|");
		puts("*-------*--------------------*---------------*----------------*");
		for (i = 0; i < n; i++)
		{
			printf("|  %2d   |       %2d           |        %2d      |      %2d      |\n"
				, p[i].pid, p[i].tgthucthi, p[i].tgcho, p[i].tgxuly);
			puts("*-------*--------------------*---------------*----------------*");
		}
	}
}

void bieudogantt(tientrinh p[], int n)
{
	int i, j;
	//In dong dau
	printf(" ");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < p[i].tgthucthi; j++)
			printf("--");
		printf(" ");
	}
	printf("\n|");
	//In PID
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < p[i].tgthucthi - 1; j++)
			printf(" ");
		printf("P%d", p[i].pid);
		for (j = 0; j < p[i].tgthucthi - 1; j++)
			printf(" ");
		printf("|");
	}
	printf("\n");

	//In dong cuoi
	printf(" ");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < p[i].tgthucthi; j++)
			printf("--");
		printf(" ");
	}
	printf("\n");
	//In thoi gian xu ly
	printf("0");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < p[i].tgthucthi; j++)
			printf("  ");
		if (p[i].tgxuly > 9) printf("\b");
		printf("%d", p[i].tgxuly);
	}
	printf("\n");
}

int main()
{

	tientrinh p[MAX];
	int i, j, n;
	printf("Moi nhap  vao so tien trinh: ");
	scanf("%d", &n);
	printf("Nhap vao thoi gian thuc thi cua moi tien trinh: \n");
	for (i = 0; i < n; i++)
	{
		printf("Tien trinh P[%d]: ", i + 1);
		scanf("%d", &p[i].tgthucthi);
		p[i].pid = i + 1;
	}
	sapxep(p, n);
	tinhtgcho(p, n);
	tinhtgxuly(p, n);
	inbang(p, n);

	tgxulytb = (double)((double)(tongtgxuly) / (double)n);
	tgchotb = (double)((double)(tongtgcho) / (double)n);

	printf("Thoi gian xu ly trung binh: %.2lf\n", tgxulytb);
	printf("Thoi gian cho trung binh: %.2lf\n", tgchotb);

	puts(" ");
	puts("\t\t BIEU DO GANTT");
	bieudogantt(p, n);
	return 0;
}
