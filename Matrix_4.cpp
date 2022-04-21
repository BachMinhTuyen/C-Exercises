#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MAXROW 100
#define MAXCOL 100
void menu();
void taoMang2Chieu(int a[][MAXCOL], int& m, int& n);
void taoMang2Chieu_NgauNhien(int a[][MAXCOL], int& m, int& n);
void xuatMang2Chieu(int a[][MAXCOL], int m, int n);
int tinhTongMotDong(int a[][MAXCOL], int dong, int cot);
int dongTongMax(int a[][MAXCOL], int dong, int cot);
int main()
{
	int arr[MAXROW][MAXCOL], dong, cot, luaChon;
	for (;;)
	{
		system("cls");//làm sạch (xoá) màn hình
		menu();
		printf(">> Nhap lua chon: "); scanf_s("%d", &luaChon);
		if (luaChon == 0)break;
		switch (luaChon)
		{
		case 1:
			taoMang2Chieu(arr, dong, cot);
			printf("Mang 2 chieu vua nhap:\n");
			xuatMang2Chieu(arr, dong, cot);
			break;
		case 2:
			taoMang2Chieu_NgauNhien(arr, dong, cot);
			printf("Mang 2 chieu vua tao:\n");
			xuatMang2Chieu(arr, dong, cot);
			break;
		case 3:
			xuatMang2Chieu(arr, dong, cot);
			break;
		case 4:
			xuatMang2Chieu(arr, dong, cot);
			printf("\nDong (0 -> %d) co tong lon nhat la dong %d", dong - 1,dongTongMax(arr, dong, cot));
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
	printf("4. Dong nao co tong lon nhat trong mang\n");
}
void taoMang2Chieu(int a[][MAXCOL], int& m, int& n)
{
	do
	{
		printf(">> Nhap m (dong):"); scanf_s("%d", &m);
	} while (m <= 0);
	do
	{
		printf(">> Nhap n (cot):"); scanf_s("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("a[%d][%d]=", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}
}
void taoMang2Chieu_NgauNhien(int a[][MAXCOL], int& m, int& n)
{
	srand(time(0));
	do
	{
		printf(">> Nhap m (dong):"); scanf_s("%d", &m);
	} while (m <= 0);
	do
	{
		printf(">> Nhap n (cot):"); scanf_s("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 101;//random từ 0 tới 100
			//random từ a -> b:  a + rand() % b - a + 1;
		}
	}
}
void xuatMang2Chieu(int a[][MAXCOL], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}
int tinhTongMotDong(int a[][MAXCOL], int dong, int cot)
{
	int tong = 0;
	for (int j = 0; j < cot; j++)
		tong += a[dong][j];
	return tong;
}
int dongTongMax(int a[][MAXCOL], int dong, int cot)
{
	int viTriDong = 0, max = tinhTongMotDong(a, 0, cot);
	for (int i = 1; i < dong; i++)
		if (max < tinhTongMotDong(a, i, cot))
		{
			max = tinhTongMotDong(a, i, cot);
			viTriDong = i;
		}
	return viTriDong;
}