//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//struct SJF
//{
//	//ten tien trinh ,burst time,den vao luc nao,cho bao lau,hoan thanh tai thoi diem nao, tg xu li lan dau 
//	char ID_Proccess[10];
//	int Burst_time, Arrial_Time, burst_avg, tg_ht, finish_time;
//	int check;
//
//}S[10];
//void Xoa(int a[], int& n, int vt) {
//	for (int i = vt+1; i < n; i++)
//	{
//		a[i - 1] = a[i];
//	}
//	n--;
//}
//void inbang(SJF s[], int n)
//{
//	float waiting_time = 0;
//	float finish_time = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		s[i].burst_avg = s[i].tg_ht - s[i].burst_avg - s[i].Arrial_Time;
//		waiting_time += s[i].burst_avg;
//		s[i].finish_time = s[i].tg_ht - s[i].Arrial_Time;
//		finish_time += s[i].finish_time;
//	}
//	printf("\nid\t\t input\t  priority\twaiting time\tfinish time\t complete\n");
//	for (int i = 1; i <= n; i++)
//	{
//		printf("%-12s%9d%8d%15d%17d%15d\n", s[i].ID_Proccess, s[i].Arrial_Time, 0,s[i].burst_avg, s[i].finish_time, s[i].tg_ht);
//	}
//	printf("\nthoi gian cho trung binh: %.2f\n", waiting_time / n);
//	printf("thoi gian hoan thanh trung binh: %.2f", finish_time / n);
//}
//int main() {
//	//doc quyen
//	//nhap so tien trinh
//	int n,sum=0;
//	printf("hay nhap so tien trinh: ");
//	scanf("%d", &n);
//	for (int i = 1; i <=n; i++)
//	{
//		printf("nhap ma tien trinh: ");
//		rewind(stdin);
//		gets_s(S[i].ID_Proccess);
//		printf("nhap tg xu li: ");
//		scanf("%d", &S[i].Burst_time);
//		S[i].burst_avg = S[i].Burst_time;
//		printf("nhap tg den: ");
//		scanf("%d", &S[i].Arrial_Time);
//		//check de danh dau chua xu li
//		//sum de tong don vi hoan thanh tien trinh
//		sum += S[i].Burst_time+S[i].Arrial_Time;
//		S[i].check = 1;
//	}
//	//
//	int check = 999999;
//	for (int i = 1; i <=n ; i++)
//	{
//		if (S[i].Arrial_Time < check)check = S[i].Arrial_Time;
//	}
//	//tao mang de luu tru nhung thanh phan can duoc xu li
//	int a[10];
//	int count = 0;
//	for (int i = check; i < sum ; i++)
//	{
//		for (int j = 1; j <=n ; j++)
//		{
//			//bo vao mang tien trinh can duoc xu li neu no vo dung vao thoi gian bang i
//			if (S[j].Arrial_Time==i&& S[j].check)
//			{
//				a[count] = j;
//				//mang tang them 1 don vi
//				count++;
//			}
//		}
//		//tao ra bien min de tim ra xem ai co burst time nho nhat de chay
//			
//	int min = 0;
//		for (int j = 0; j < count; j++)
//		{
//			if (S[a[min]].Burst_time> S[a[j]].Burst_time)
//			{
//				min = j;
//			}
//		}
//		//giam di 1 don vi
//		S[a[min]].Burst_time -= 1;
//		//neu burst time da hoan thanh(bang o) thi ngung lai
//		if (S[a[min]].Burst_time == 0) {
//			//thoi gian hoan thanh = i+1
//			S[a[min]].tg_ht = i+1;
//			//check =0 de biet no da hoan thanh r
//			S[a[min]].check = 0;
//			//xoa ra khooi mang de khoi so sanh nua vi da hoan thanh r
//			Xoa(a, count, min);
//		}
//		
//	}
//	//
//	inbang(S, n);
//}