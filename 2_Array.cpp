#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
void menu();
void nhapMang1Chieu(int a[], int& n);
void xuatMang1Chieu(int a[], int n);
int giaTriLonNhat(int a[], int n);
int giaTriNhoNhat(int a[], int n);
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
			xuatMang1Chieu(arr, soPhanTu);
			printf("\nGia tri lon nhat: %d", giaTriLonNhat(arr, soPhanTu));
			printf("\nGia tri nho nhat: %d", giaTriNhoNhat(arr, soPhanTu));
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
	printf("3. Tim gia tri lon nhat/ nho nhat trong mang\n");
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
int giaTriLonNhat(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (max < a[i])
			max = a[i];
	return max;
}
int giaTriNhoNhat(int a[], int n)
{
	int min = a[0];
	for (int i = 1; i < n; i++)
		if (min > a[i])
			min = a[i];
	return min;
}