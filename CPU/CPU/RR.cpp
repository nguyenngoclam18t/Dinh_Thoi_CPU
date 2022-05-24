#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct Roundrobin
{
	//ten tien trinh ,burst time,den vao luc nao,cho bao lau,hoan thanh tai thoi diem nao, tg xu li lan dau 
	char ID_Proccess[10]; 
	int Burst_time, Arrial_Time, burst_avg, tg_ht, finish_time;
	int check;
	int check_join;

}S[10];
void hoan_vi(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void Xoa(int a[], int& n, int vt) {
	for (int i = vt+1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	n--;
}
void Swap(int a[], int &n) {
	for (int i = 0; i < n-1; i++)
	{
		hoan_vi(a[i], a[i + 1]);
	}
}
void inbang(Roundrobin s[], int n)
{
	float waiting_time = 0;
	float finish_time = 0;
	for (int i = 1; i <= n; i++)
	{
		s[i].burst_avg = s[i].tg_ht - s[i].burst_avg - s[i].Arrial_Time;
		waiting_time += s[i].burst_avg;
		s[i].finish_time = s[i].tg_ht - s[i].Arrial_Time;
		finish_time += s[i].finish_time;
	}
	printf("\nid\t\t input\t  priority\twaiting time\tfinish time\t complete\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%-12s%9d%8d%15d%17d%15d\n", s[i].ID_Proccess, s[i].Arrial_Time, 0, s[i].burst_avg, s[i].finish_time, s[i].tg_ht);
	}
	printf("\nthoi gian cho trung binh: %.2f\n", waiting_time / n);
	printf("thoi gian hoan thanh trung binh: %.2f", finish_time / n);
}
int main() {
	//doc quyen
	//nhap so tien trinh
	int n,sum=0;
	printf("hay nhap so tien trinh: ");
	scanf("%d", &n);
	for (int i = 1; i <=n; i++)
	{
		printf("nhap ma tien trinh: ");
		rewind(stdin);
		gets_s(S[i].ID_Proccess);
		printf("nhap tg xu li: ");
		scanf("%d", &S[i].Burst_time);
		S[i].burst_avg = S[i].Burst_time;
		printf("nhap tg den: ");
		scanf("%d", &S[i].Arrial_Time);
		sum += S[i].Arrial_Time + S[i].Burst_time;
		//check de danh dau chua xu li
		S[i].check = 1;
		S[i].check_join = 1;
	}
	int quantum;
	printf("nhap quantum: ");
	scanf("%d",&quantum);
	//
	 int check = 999999;
	for (int i = 1; i <=n ; i++)
	{
		if (S[i].Arrial_Time < check)check = S[i].Arrial_Time;
	}
	//
	
	//
	int a[10];
	int count=0;
	int kt = 0;
	for (int i = check; i < sum; )
	{
		for (int j = 1; j <= n; j++)
		{
			if (S[j].Arrial_Time <= i && S[j].check_join) {
				S[j].check_join = 0;
				a[count] = j;
				count++;
			}
		}
		if (kt)
		{
			Swap(a, count);
			if (count != 1) {
				for (int j = 0; j < count; j++)
				{
					if (S[a[j]].Arrial_Time == i) {
						hoan_vi(a[count - 1], a[count - 2]);
						break;
					}
				}
			}
		}
		
		
		if (S[a[0]].Burst_time <= quantum&&count!=0) {
			i += S[a[0]].Burst_time;
			S[a[0]].Burst_time = 0;
			S[a[0]].check = 0;
			S[a[0]].tg_ht = i;
			Xoa(a, count, 0);
			kt = 0;
		}
		else if(S[a[0]].Burst_time > quantum){
			i += quantum;
			S[a[0]].Burst_time -= quantum;
			kt = 1;
		}
		else if (count==0)
		{
			break;
		}
	}

	inbang(S, n);
}