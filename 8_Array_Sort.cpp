#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
void menu();
void nhapMang1Chieu(int a[], int& n);
void nhapMang1Chieu_NgauNhien(int a[], int& n);
void xuatMang1Chieu(int a[], int n);
void swap(int& a, int& b);
void InterchangeSort_TangDan(int a[], int n);
void InterchangeSort_GiamDan(int a[], int n);
void SelectionSort_TangDan(int a[], int n);
void SelectionSort_GiamDan(int a[], int n);
void QuickSort_TangDan(int a[], int Left, int Right);
void QuickSort_GiamDan(int a[], int Left, int Right);
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
			InterchangeSort_TangDan(arr, soPhanTu);
			printf("\n=====Mang sap xep tang dan:\n");
			xuatMang1Chieu(arr, soPhanTu);
			InterchangeSort_GiamDan(arr, soPhanTu);
			printf("\n=====Mang sap xep giam dan:\n");
			xuatMang1Chieu(arr, soPhanTu);
			break;
		case 5:
			SelectionSort_TangDan(arr, soPhanTu);
			printf("\n=====Mang sap xep tang dan:\n");
			xuatMang1Chieu(arr, soPhanTu);
			SelectionSort_GiamDan(arr, soPhanTu);
			printf("\n=====Mang sap xep giam dan:\n");
			xuatMang1Chieu(arr, soPhanTu);
			break;
		case 6:
			QuickSort_TangDan(arr, 0, soPhanTu - 1);
			printf("\n=====Mang sap xep tang dan:\n");
			xuatMang1Chieu(arr, soPhanTu);
			QuickSort_GiamDan(arr, 0, soPhanTu - 1);
			printf("\n=====Mang sap xep giam dan:\n");
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
	printf("4. Sap xep mang tang/giam dan theo giai thuat Interchange Sort\n");
	printf("5. Sap xep mang tang/giam dan theo giai thuat Selection Sort\n");
	printf("6. Sap xep mang tang/giam dan theo giai thuat Quick Sort\n");
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
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void InterchangeSort_TangDan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)	
		for (int j = i + 1; j < n; j++)	
			if (a[i] > a[j])		
				swap(a[i], a[j]);	
}
void InterchangeSort_GiamDan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j])
				swap(a[i], a[j]);
}
void SelectionSort_TangDan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
		}
		swap(a[min], a[i]);
	}
}
void SelectionSort_GiamDan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[max] < a[j])
			{
				max = j;
			}
		}
		swap(a[max], a[i]);
	}
}
void QuickSort_TangDan(int a[], int Left, int Right)
{
	if (Left >= Right) return;
	int i = Left, j = Right, Mid = (Left + Right) / 2;
	int x = a[Mid];
	do {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			if (i < j)
				swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i < j);
	QuickSort_TangDan(a, Left, j);
	QuickSort_TangDan(a, i, Right);
}
void QuickSort_GiamDan(int a[], int Left, int Right)
{
	if (Left >= Right) return;
	int i = Left, j = Right, Mid = (Left + Right) / 2;
	int x = a[Mid];
	do {
		while (a[i] > x) i++;
		while (a[j] < x) j--;
		if (i <= j)
		{
			if (i < j)
				swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i < j);
	QuickSort_GiamDan(a, Left, j);
	QuickSort_GiamDan(a, i, Right);
}