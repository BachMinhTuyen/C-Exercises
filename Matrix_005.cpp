#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MAXROW 100
#define MAXCOL 100
void menu();
void taoMang2Chieu(int a[][MAXCOL], int& n);
void taoMang2Chieu_NgauNhien(int a[][MAXCOL], int& n);
void xuatMang2Chieu(int a[][MAXCOL], int n);
int tinhTong_DuongCheoChinh(int a[][MAXCOL], int n);
int tinhTong_DuongCheoPhu(int a[][MAXCOL], int n);

int main()
{
	int arr[MAXROW][MAXCOL], n, luaChon;
	for (;;)
	{
		system("cls");//làm sạch (xoá) màn hình
		menu();
		printf(">> Nhap lua chon: "); scanf_s("%d", &luaChon);
		if (luaChon == 0)break;
		switch (luaChon)
		{
		case 1:
			taoMang2Chieu(arr, n);
			printf("Mang 2 chieu vua nhap:\n");
			xuatMang2Chieu(arr, n);
			break;
		case 2:
			taoMang2Chieu_NgauNhien(arr, n);
			printf("Mang 2 chieu vua tao:\n");
			xuatMang2Chieu(arr, n);
			break;
		case 3:
			printf("Mang 2 chieu vua tao:\n");
			xuatMang2Chieu(arr, n);
			break;
		case 4:
			printf("Tong cua duong cheo chinh: %d\n", tinhTong_DuongCheoChinh(arr, n));
			break;
		case 5:
			printf("Tong cua duong cheo phu: %d\n", tinhTong_DuongCheoPhu(arr, n));
			break;

		default:printf("Khong hop le! Vui long lua chon lai!\n");
			break;
		}
		_getch();
	}
	return 0;
}
void menu()
{
	printf("0. Thoat chuong trinh\n");
	printf("1. Tao va xuat mang 2 chieu\n");
	printf("2. Tao mang 2 chieu ngau nhien\n");
	printf("3. Xuat mang 2 chieu\n");
	printf("4. Tinh tong duong cheo chinh\n");
	printf("5. Tinh tong duong cheo phu\n");
}
void taoMang2Chieu(int a[][MAXCOL], int& n)
{
	do
	{
		printf(">> Nhap n :"); scanf_s("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("a[%d][%d]=", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}
}
void taoMang2Chieu_NgauNhien(int a[][MAXCOL], int& n)
{
	srand(time(0));
	do
	{
		printf(">> Nhap n :"); scanf_s("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 101;//random từ 0 tới 100
			//random từ a -> b:  a + rand() % b - a + 1;
		}
	}
}
void xuatMang2Chieu(int a[][MAXCOL], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}
int tinhTong_DuongCheoChinh(int a[][MAXCOL], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
		tong += a[i][i];
	return tong;
}
int tinhTong_DuongCheoPhu(int a[][MAXCOL], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
		tong += a[i][n - 1 - i];
	return tong;
}