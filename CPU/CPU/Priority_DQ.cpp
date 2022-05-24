//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//struct Priority
//{
//	//ten tien trinh ,burst time,den vao luc nao,cho bao lau,hoan thanh tai thoi diem nao, tg xu li lan dau 
//	char id_proccess[10];
//	int burst_time, arrial_time, priority, burst_avg, tg_ht,finish_time;
//	int check;
//
//}S[10];
//void inbang(Priority s[], int n)
//{
//	float waiting_time = 0;
//	float finish_time = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		s[i].burst_avg = s[i].tg_ht - s[i].burst_avg - s[i].arrial_time;
//		waiting_time += s[i].burst_avg;
//		s[i].finish_time = s[i].tg_ht - s[i].arrial_time;
//		finish_time += s[i].finish_time;
//	}
//	printf("\nid\t\t input\t  priority\twaiting time\tfinish time\t complete\n");
//	for (int i = 1; i <= n; i++)
//	{
//		printf("%-12s%9d%8d%15d%17d%15d\n", s[i].id_proccess, s[i].arrial_time, s[i].priority,s[i].burst_avg, s[i].finish_time, s[i].tg_ht);
//	}
//	printf("\nthoi gian cho trung binh: %.2f\n", waiting_time / n);
//	printf("thoi gian hoan thanh trung binh: %.2f", finish_time / n);
//}
//int main() {
//	//doc quyen
//	//nhap so tien trinh
//	int n;
//	
//	float Waiting_time = 0;
//	float finish_time = 0;	
//	int check = 1;
//	printf("hay nhap so tien trinh: ");
//	scanf("%d", &n);
//	for (int i = 1; i <=n; i++)
//	{
//		printf("nhap ma tien trinh: ");
//		rewind(stdin);
//		gets_s(S[i].id_proccess);
//		printf("nhap tg xu li: ");
//		scanf("%d", &S[i].burst_time);
//		S[i].burst_avg = S[i].burst_time;
//		printf("nhap tg den: ");
//		scanf("%d", &S[i].arrial_time);
//		printf("nhap uu tien: ");
//		scanf("%d", &S[i].priority);
//		//check de danh dau chua xu li
//		S[i].check = 1;
//	}
//	//tao bien check de kiem tra xem thang nao vo truoc
//	
//	for (int i = 2; i <=n; i++)
//	{
//		//neu thoi gian den bang nhau ma burst time khac nhau thi so sanh
//		if (S[check].arrial_time == S[i].arrial_time) {
//
//			if (S[check].priority > S[i].priority) {
//				check = i;
//			}
//		}
//		//khac thoi gian vo
//		if (S[check].arrial_time > S[i].arrial_time) {
//				check = i;
//		}
//	}
//	//xu li nguoi nho nhat dau tien
//	S[check].tg_ht = S[check].burst_time;
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
//					if (kt > S[j].priority)
//					{
//						kt = S[j].priority;
//						index = j;
//					}
//				}
//			}
//			S[index].tg_ht = S[check].tg_ht + S[index].burst_time;
//			S[index].check = 0;
//			//cho bien check bang thang hoan thanh truoc no
//			check = index;
//	}
//
//	inbang(S, n);
//}