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
//		printf("%-12s%9d%8d%15d%17d%15d\n", s[i].ID_Proccess, s[i].Arrial_Time, 0, s[i].burst_avg, s[i].finish_time, s[i].tg_ht);
//	}
//	printf("\nthoi gian cho trung binh: %.2f\n", waiting_time / n);
//	printf("thoi gian hoan thanh trung binh: %.2f", finish_time / n);
//}
//
//
//int main() {
//	//doc quyen
//	//nhap so tien trinh
//	int n;
// int b[10];
//int dem = 1;
//	printf("hay nhap so tien trinh: ");
//	scanf("%d", &n);
//	for (int i = 1; i <=n; i++)
//	{
//		printf("nhap ma tien trinh: ");
//				rewind(stdin);
//				gets_s(S[i].ID_Proccess);
//		printf("nhap tg xu li: ");
//		scanf("%d", &S[i].Burst_time);
//		S[i].burst_avg = S[i].Burst_time;
//		printf("nhap tg den: ");
//		scanf("%d", &S[i].Arrial_Time);
//		//check de danh dau chua xu li
//		S[i].check = 1;
//	}
//	//tao bien check de kiem tra xem thang nao vo truoc
//	int check=1;
//	for (int i = 2; i <=n; i++)
//	{
//		//neu thoi gian den bang nhau ma burst time khac nhau thi so sanh
//		if (S[check].Arrial_Time == S[i].Arrial_Time) {
//
//			if (S[check].Burst_time > S[i].Burst_time) {
//				check = i;
//			}
//		}
//		//khac thoi gian vo
//		if (S[check].Arrial_Time > S[i].Arrial_Time) {
//				check = i;
//		}
//	}
//	//xu li nguoi nho nhat dau tien
//	S[check].tg_ht = S[check].Burst_time+ S[check].Arrial_Time;
//	S[check].check = 0;
//	//
//	int kt;
//	for (int i = 1; i <n; i++)
//	{
//		//tao kt and index de tim xem ai chay truoc voi do uu tien
//			kt = 999999999;
//			int index=0;
//			for (int j = 1; j <=n; j++)
//			{
//				if (S[j].check)
//				{
//					if (kt > S[j].Burst_time)
//					{
//						kt = S[j].Burst_time;
//						index = j;
//					}
//				}
//			}
//			S[index].tg_ht = S[check].tg_ht + S[index].Burst_time;
//			S[index].check = 0;
//			//cho bien check bang thang hoan thanh truoc no
//			check = index;
//	}
//	inbang(S, n);
//}