//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//struct Priority
//{
//	//ten tien trinh ,burst time,den vao luc nao,cho bao lau,hoan thanh tai thoi diem nao, tg xu li lan dau 
//	char id_proccess[10];
//	int burst_time, arrial_time, priority, burst_avg, tg_ht,finish_time;
//	int check;
//
//}s[10];
//void xoa(int a[], int& n, int vt) {
//	for (int i = vt+1; i < n; i++)
//	{
//		a[i - 1] = a[i];
//	}
//	n--;
//}
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
//	int n,sum=0;
//	printf("hay nhap so tien trinh: ");
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		printf("nhap ma tien trinh: ");
//		rewind(stdin);
//		gets_s(s[i].id_proccess);
//		printf("nhap tg xu li: ");
//		scanf("%d", &s[i].burst_time);
//		s[i].burst_avg = s[i].burst_time;
//		printf("nhap tg den: ");
//		scanf("%d", &s[i].arrial_time);
//		printf("nhap uu tien: ");
//		scanf("%d", &s[i].priority);
//		sum += s[i].burst_time + s[i].arrial_time;
//		//check de danh dau chua xu li
//		s[i].check = 1;
//	}
//	/*tao bien check de kiem tra xem thang nao vo truoc*/
//	int check = 999999;
//	for (int i = 1; i <=n ; i++)
//	{
//		if (s[i].arrial_time < check)check = s[i].arrial_time;
//	}
//	
//	//tao mang
//	int a[10];
//	int count = 0;
//
//	for (int i = check; i < sum ; i++)
//	{
//		for (int j = 1; j <=n ; j++)
//		{
//			if (s[j].arrial_time==i&& s[j].check)
//			{
//				a[count] = j;
//				count++;
//			}
//		}
//		int min = 0;
//		for (int j = 0; j < count; j++)
//		{
//			if (s[a[min]].priority> s[a[j]].priority)
//			{
//				min = j;
//			}
//		}
//		s[a[min]].burst_time -= 1;
//		if (s[a[min]].burst_time == 0) {
//			s[a[min]].tg_ht = i+1;
//			s[a[min]].check = 0;
//			xoa(a, count, min);
//		}
//	}
//
//	inbang(s, n);
//}