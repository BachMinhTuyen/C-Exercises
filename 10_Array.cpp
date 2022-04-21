#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
void menu();
void nhapMang1Chieu(int a[], int& n);
void nhapMang1Chieu_NgauNhien(int a[], int& n);
void xuatMang1Chieu(int a[], int n);
void xoaPhanTuTaiViTriK(int a[], int& n, int k);
void xoaPhanTuGiaTriX(int a[], int& n, int x);
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
			int k;
			do
			{
				printf(">> Nhap vi tri k: "); scanf_s("%d", &k);
				if (k < 0 || k >= soPhanTu)
					printf("Loi: Vui long nhap lai vi tri k\n");
			} while (k < 0 || k >= soPhanTu);
			printf("\n===Truoc khi xoa: ");
			xuatMang1Chieu(arr, soPhanTu);
			xoaPhanTuTaiViTriK(arr, soPhanTu, k);
			printf("\n=====Sau khi xoa: ");
			xuatMang1Chieu(arr, soPhanTu);
			break;
		case 5:
			int x;
			printf(">> Nhap gia tri x: "); scanf_s("%d", &x);
			printf("\n===Truoc khi xoa: ");
			xuatMang1Chieu(arr, soPhanTu);
			xoaPhanTuGiaTriX(arr, soPhanTu, x);
			printf("\n=====Sau khi xoa: ");
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
	printf("4. Xoa mot phan tu tai vi tri thu k cua mang\n");
	printf("5. Xoa tat ca cac phan tu co gia tri x trong mang\n");
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
void xoaPhanTuTaiViTriK(int a[], int& n, int k)
{
	for (int i = k; i < n; i++)
		a[i] = a[i + 1];
	n--;
}
void xoaPhanTuGiaTriX(int a[], int& n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			for (int j = i; j < n; j++)
			{
				a[j] = a[j + 1];
			}
			i--;//sau khi xoá thì cần kiểm tra lại giá trị tại vị trí vừa xoá
			n--;
		}
	}
}