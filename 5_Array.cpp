#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
void menu();
void nhapMang1Chieu(int a[], int& n);
void xuatMang1Chieu(int a[], int n);
void swap(int& a, int& b);
void daoNguoc(int a[], int n);
int main()
{
	int arr[MAX], soPhanTu, luaChon;
	for (;;)
	{
		system("cls");//làm sạch (xoá) màn hình
		menu();
		printf(">> Nhap lua chon: "); scanf_s("%d", &luaChon);
		if (luaChon == 0)break;
		switch (luaChon)
		{
		case 1:
			nhapMang1Chieu(arr, soPhanTu);
			printf("Mang vua nhap:\n");
			xuatMang1Chieu(arr, soPhanTu);
			break;
		case 2:
			printf("Mang vua nhap:\n");
			xuatMang1Chieu(arr, soPhanTu);
			break;
		case 3:
			printf("\n===== Truoc khi dao nguoc mang =====\n");
			xuatMang1Chieu(arr, soPhanTu);
			daoNguoc(arr, soPhanTu);
			printf("\n===== Sau khi dao nguoc mang =====\n");
			xuatMang1Chieu(arr, soPhanTu);
			break;
		default:printf("Vui long lua chon lai!\n");
			break;
		}
		_getch();
	}
	return 0;
}
void menu()
{
	printf("0. Thoat chuong trinh\n");
	printf("1. Nhap mang 1 chieu\n");
	printf("2. Xuat mang 1 chieu\n");
	printf("3. Dao nguoc mang\n");
}
void nhapMang1Chieu(int a[], int& n)
{
	do {
		printf(">> Nhap so luong phan tu n (n > 0): "); scanf_s("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < n; i++)
	{
		printf("a[%d]= ", i);
		scanf_s("%d", &a[i]);
	}
}
void xuatMang1Chieu(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%5d", a[i]);
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void daoNguoc(int a[], int n)
{
	/*Tạo vòng lặp để hoán đổi số đầu với số cuối trong mảng
	 và thu dần khoảng cách về giữa mảng*/
	for (int i = 0; i < n / 2; i++)
		swap(a[i], a[n - 1 - i]);
}