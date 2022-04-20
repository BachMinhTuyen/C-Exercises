#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
void menu();
void nhapMang1Chieu(int a[], int& n);
void xuatMang1Chieu(int a[], int n);
int LinearSearch(int a[], int n, int x);
void swap(int& a, int& b);
void InterchangeSort_TangDan(int a[], int n);
int BinarySearch(int a[], int n, int x);
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
			int x;
			xuatMang1Chieu(arr, soPhanTu);
			printf("\n>> Nhap so cam tim: ");
			scanf_s("%d", &x);
			if (LinearSearch(arr, soPhanTu, x) == -1)
				printf("Khong co gia tri can tim trong mang\n");
			else
				printf("So %d nam o vi tri %d trong mang\n", x, LinearSearch(arr, soPhanTu, x));
			break;
		case 4:
			int y;
			InterchangeSort_TangDan(arr, soPhanTu);
			xuatMang1Chieu(arr, soPhanTu);
			printf("\n>> Nhap gia tri can tim: ");
			scanf_s("%d", &y);
			if (BinarySearch(arr, soPhanTu, y) == -1)
			{
				printf("Khong co gia tri can tim trong mang\n");
			}
			else
			{
				printf("So %d nam o vi tri %d trong mang\n", y, BinarySearch(arr, soPhanTu, y));
			}
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
	printf("3. Tim kiem x trong mang theo giai thuat Linear Search\n");
	printf("4. Tim kiem x trong mang theo giai thuat Binary Search\n");
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
int LinearSearch(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return i;
	return -1;
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
//Mảng cần được sắp xếp tăng dần trước khi tìm kiếm bằng hàm Binary Search
int BinarySearch(int a[], int n, int x)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == x)
			return mid;
		else if (a[mid] < x)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}