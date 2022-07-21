#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAX 100

void nhapMang(double* arr, int& soPhanTu)
{
	printf("Nhap so phan tu toi da: ");
	scanf_s("%d", &soPhanTu);
	//arr = new double[soPhanTu];
	for (int i = 0; i < soPhanTu; i++)
	{
		printf("A[%d] = ", i);
		scanf_s("%lf", arr + i);
	}
}
void taoMangNgauNhien(double*& arr, int& soPhanTu)
{
    printf("Nhap so phan tu: ");
    scanf_s("%d", &soPhanTu);
    //arr = new double[soPhanTu];
    srand(time(0));
    for (int i = 0; i < soPhanTu; i++)
    {
		//random từ a tới b là: a + rand() % b - a + 1 
		//random từ 0.1 đến 100.00
        *(arr + i) = (10 + rand() % 9991) * 0.01;
    }
}
void xuatMang(double* arr, int soPhanTu)
{
    for (int i = 0; i < soPhanTu; i++)
    {
        printf("%.2lf\t", *(arr + i));
    }
}
int kiemTraSoNguyenTo(int n)
{
	if (n < 2)
	{
		return 0;// trả về không phải là số nguyên tố
	}
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return 0;// trả về không phải là số nguyên tố
		}
	}
	return 1;//trả về là số nguyên tố
}
void inSoNguyenTo(double* arr, int soPhanTu)
{

	for (int i = 0; i < soPhanTu; i++)
	{
		int temp = *(arr + i);//ép kiểu dữ liệu double --> int (lấy phần nguyên)
		if (kiemTraSoNguyenTo(temp) == 1)
		{
			printf("%5d", temp);
		}
	}
}
void inPhanThapPhan(double* arr, int soPhanTu)
{
	for (int i = 0; i < soPhanTu; i++)
	{
		int n = 2;
		double temp = *(arr + i) - (int)*(arr + i);		
		do
		{			
			temp *= 10;
			int result = (int)temp;
			printf("%d", result);
			temp -= result;
			n--;
		} while (n > 0);
		printf("\t");
	}
}
bool kiemTraNguyenCo2(double a)
{
	int p = a;
	while (p > 0)
	{
		if ((p % 10) == 2)
			return true;
		else
			p /= 10;
	}
}
int demSoPhanTuPhanNguyenChua2(double* arr, int soPhanTu)
{
	int dem = 0;
	for (int i = 0; i < soPhanTu; i++)
		if (kiemTraNguyenCo2(*(arr + i)) == true)
			dem++;
	return dem;
}
void xoaPhanTu(double* arr, int& soPhanTu, int viTriXoa)
{
	for (int j = viTriXoa; j < soPhanTu; j++)
	{
		*(arr + j) = *(arr + j + 1);
	}
	soPhanTu--;
}
void xoaPhanTuPhanNguyenLe(double* arr, int& soPhanTu)
{
	for (int i = 0; i < soPhanTu; i++)
	{
		int temp = *(arr + i);
		if (temp % 2 != 0)
		{
			/*for (int j = i; j < soPhanTu; j++)
			{
				*(arr + j) = *(arr + j + 1);
			}
			soPhanTu--;*/
			xoaPhanTu(arr, soPhanTu, i);
			i--;//Kiểm tra lại phần tử tại vị trí vừa xoá
		}
	}
}
int demPhanTuX(double* arr, int soPhanTu, double x)
{
	int dem = 0;
	for (int i = 0; i < soPhanTu; i++)
		if (*(arr + i) == x)
			dem++;	
	try
	{
		if (dem != 0)
			printf("Co %d phan tu can tim\n", dem);
		else
			throw "Khong co phan tu cam tim";
	}
	catch (const char *str)
	{
		printf("Loi: %s\n", str);
	}
}
int timViTriMax(double* arr, int soPhanTu)
{
	double max = *arr;
	int viTriMax = 0;
	for (int i = 0; i < soPhanTu; i++)
	{
		if (max < *(arr + i))
		{
			max = *(arr + i);
			viTriMax = i;
		}
	}
	return viTriMax;
}
int timViTriMin(double* arr, int soPhanTu)
{
	double min = *arr;
	int viTriMin = 0;
	for (int i = 0; i < soPhanTu; i++)
	{
		if (min > *(arr + i))
		{
			min = *(arr + i);
			viTriMin = i;
		}
	}
	return viTriMin;
}
void xoaPhanTuMaxMin(double* arr, int& soPhanTu)
{
	int viTriMax, viTriMin;
	viTriMax = timViTriMax(arr, soPhanTu);
	xoaPhanTu(arr, soPhanTu, viTriMax);
	
	viTriMin = timViTriMin(arr, soPhanTu);
	xoaPhanTu(arr, soPhanTu, viTriMin);
}
void themPhanTuSauMax(double* arr, int& soPhanTu, int viTriMax, double giaTriPhanTu)
{
	for (int i = soPhanTu - 1; i > viTriMax; i--)
	{
		*(arr + i + 1) = *(arr + i);
	}
	soPhanTu++;
	*(arr + viTriMax + 1) = giaTriPhanTu;
}
void themPhanTuTruocMin(double* arr, int& soPhanTu,int viTriMin, double giaTriPhanTu)
{
	for (int i = soPhanTu - 1; i >= viTriMin; i--)
	{
		*(arr + i + 1) = *(arr + i);
	}
	soPhanTu++;
	*(arr + viTriMin) = giaTriPhanTu;
}
void menu()
{
	printf("0. Thoat chuong trinh!\n");
	printf("1. Bai 1: Mang 1 chieu dang con tro\n");

}
void menuB1()
{
	printf("0. Quay lai\n");
	printf("1. Tao mang 1 chieu dang con tro\n");
	printf("2. Tao mang 1 chieu ngau nhien dang con tro\n");
	printf("3. Xuat mang 1 chieu\n");
	printf("4. Xuat phan nguyen la so nguyen to\n");
	printf("5. Xuat cac phan thap phan (sau dau phay)\n");
	printf("6. Dem phan tu co phan nguyen chua chu so 2\n");
	printf("7. Xoa phan tu co phan nguyen la so le\n");
	printf("8. Co bao nhieu phan tu X trong mang\n");
	printf("9. Xoa phan tu max/ min\n");
	printf("10. Them phan tu vao sau so lon nhat MAX\n");
	printf("11. Them phan tu vao truoc so nho nhat MIN\n");
}
int main()
{
	double* arr = new double[MAX];
	double temp;
	int soPhanTu, viTri;
	int luaChon, Bai1;
	for (;;)
	{
		system("cls");
		menu();
		printf(">> Nhap lua chon: "); scanf_s("%d", &luaChon);
		if (luaChon == 0)break;
		switch (luaChon)
		{
		case 1:
			for (;;)
			{
				system("cls");
				menuB1();
				printf(">> Nhap lua chon: "); scanf_s("%d", &Bai1);
				if (Bai1 == 0)break;
				switch (Bai1)
				{
				case 1:
					nhapMang(arr, soPhanTu);
					printf("\nMang vua nhap:\n");
					xuatMang(arr, soPhanTu);
					break;
				case 2:
					taoMangNgauNhien(arr, soPhanTu);
					printf("\nMang vua tao ngau nhien:\n");
					xuatMang(arr, soPhanTu);
					break;
				case 3:
					printf("\nMang vua tao:\n");
					xuatMang(arr, soPhanTu);
					break;
				case 4:
					printf("\nMang vua nhap:\n");
					xuatMang(arr, soPhanTu);
					printf("\nCac phan nguyen la so nguyen to: ");
					inSoNguyenTo(arr, soPhanTu);
					break;
				case 5:
					printf("\nMang ban dau:\n");
					xuatMang(arr, soPhanTu);
					printf("\nCac phan thap phan sau dau phay la:\n");
					inPhanThapPhan(arr, soPhanTu);
					break;
				case 6:
					printf("Co %d phan tu chua chu so 2 o phan nguyen\n", demSoPhanTuPhanNguyenChua2(arr, soPhanTu));
					break;
				case 7:
					printf("Truoc khi xoa\n");
					xuatMang(arr, soPhanTu);
					xoaPhanTuPhanNguyenLe(arr, soPhanTu);
					printf("\nSau khi da xoa cac phan tu co chu so le\n");
					xuatMang(arr, soPhanTu);
					break;
				case 8:					
					printf("Nhap phan tu X can tim: ");
					scanf_s("%lf", &temp);
					demPhanTuX(arr, soPhanTu, temp);
					break;
				case 9:
					printf("Truoc khi xoa\n");
					xuatMang(arr, soPhanTu);
					xoaPhanTuMaxMin(arr, soPhanTu);
					printf("\nSau khi da xoa phan tu max, min\n");
					xuatMang(arr, soPhanTu);
					break;
				case 10:
					printf("Nhap phan tu can chen: ");
					scanf_s("%lf", &temp);
					viTri = timViTriMax(arr, soPhanTu);
					printf("\nTruoc khi them\n");
					xuatMang(arr, soPhanTu);
					themPhanTuSauMax(arr, soPhanTu, viTri, temp);
					printf("\nSau khi them phan tu\n");
					xuatMang(arr, soPhanTu);
					break;
				case 11:
					printf("Nhap phan tu can chen: ");
					scanf_s("%lf", &temp);
					viTri = timViTriMin(arr, soPhanTu);
					printf("\nTruoc khi them\n");
					xuatMang(arr, soPhanTu);
					themPhanTuTruocMin(arr, soPhanTu, viTri, temp);
					printf("\nSau khi them phan tu\n");
					xuatMang(arr, soPhanTu);
					break;
				default:printf("Khong hop le! Vui long lua chon lai!\n");
					break;
				}
				_getch();
			}
			break;
		case 2:

			break;
		default:printf("Khong hop le! Vui long lua chon lai!\n");
			break;
		}
		_getch();
	}
	return 0;
}