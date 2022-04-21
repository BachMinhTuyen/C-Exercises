#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
void menu();
void nhapMang1Chieu(int a[], int& n);
void nhapMang1Chieu_NgauNhien(int a[], int& n);
void xuatMang1Chieu(int a[], int n);
void themPhanTuVaoViTriK(int a[], int& n, int k, int x);
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
			nhapMang1Chieu_NgauNhien(arr, soPhanTu);
			printf("Mang vua nhap:\n");
			xuatMang1Chieu(arr, soPhanTu);
			break;
		case 3:
			printf("Mang vua nhap:\n");
			xuatMang1Chieu(arr, soPhanTu);
			break;
		case 4:
			int k, x;
			do
			{
				printf(">> Nhap vi tri k: "); scanf_s("%d", &k);
				if (k < 0 || k > soPhanTu)
					printf("Loi: Vui long nhap lai vi tri k\n");
			} while (k < 0 || k > soPhanTu);
			printf(">> Nhap gia tri x: "); scanf_s("%d", &x);
			printf("\n===Truoc khi them: ");
			xuatMang1Chieu(arr, soPhanTu);
			themPhanTuVaoViTriK(arr, soPhanTu, k, x);
			printf("\n=====Sau khi them: ");
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
	printf("2. Nhap mang 1 chieu ngau nhien\n");
	printf("3. Xuat mang 1 chieu\n");
	printf("4. Them mot phan tu x vao vi tri thu k cua mang\n");
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
void nhapMang1Chieu_NgauNhien(int a[], int& n)
{
	srand(time(0));
	do {
		printf(">> Nhap so luong phan tu n (n > 0): "); scanf_s("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < n; i++)
	{
		//random từ a tới b:  a + rand() % b - a + 1
		a[i] = rand() % 101;//random từ 0 tới 100
	}
}
void xuatMang1Chieu(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%5d", a[i]);
}
void themPhanTuVaoViTriK(int a[], int& n, int k, int x)
{
	for (int i = n; i > k; i--)
		a[i] = a[i - 1];
	a[k] = x;//thêm phần tử x vào vị trí k
	n++;
}