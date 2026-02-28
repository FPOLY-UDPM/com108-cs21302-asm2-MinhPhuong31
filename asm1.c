/******************************************************************************
 * Họ và tên: [Trần Minh Phương]
 * MSSV:      [PS33274]
 * Lớp:       [CS21301]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void chucNang1()
{
    int x;
    printf("Nhap so nguyen x: ");
    scanf("%d", &x);

    printf("So %d la so nguyen.\n", x);

    if (x < 2)
    {
        printf("%d khong phai la so nguyen to.\n", x);
    }
    else
    {
        int laNguyenTo = 1;
        for (int i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
            {
                laNguyenTo = 0;
                break;
            }
        }
        if (laNguyenTo)
            printf("%d la so nguyen to.\n", x);
        else
            printf("%d khong phai la so nguyen to.\n", x);
    }

    if (x < 0)
    {
        printf("%d khong phai la so chinh phuong.\n", x);
    }
    else
    {
        int can = sqrt(x);
        if (can * can == x)
            printf("%d la so chinh phuong.\n", x);
        else
            printf("%d khong phai la so chinh phuong.\n", x);
    }
}

void chucNang2()
{
    int x, y;
    printf("Nhap so thu nhat: ");
    scanf("%d", &x);
    printf("Nhap so thu hai: ");
    scanf("%d", &y);

    int a = x, b = y;

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    int ucln = a;
    int bcnn = (x * y) / ucln;

    printf("Uoc chung lon nhat: %d\n", ucln);
    printf("Boi chung nho nhat: %d\n", bcnn);
}

void chucNang3()
{
    int gioBatDau, gioKetThuc;

    printf("Nhap gio bat dau (12-23): ");
    scanf("%d", &gioBatDau);

    printf("Nhap gio ket thuc (12-23): ");
    scanf("%d", &gioKetThuc);

    if (gioBatDau < 12 || gioKetThuc > 23 || gioBatDau >= gioKetThuc)
    {
        printf("Gio nhap khong hop le.\n");
        return;
    }

    int soGio = gioKetThuc - gioBatDau;
    float tien = 0;

    if (soGio <= 3)
    {
        tien = soGio * 150000;
    }
    else
    {
        tien = 3 * 150000 + (soGio - 3) * 150000 * 0.7;
    }

    if (gioBatDau >= 14 && gioBatDau <= 17)
    {
        tien = tien * 0.9;
    }

    printf("So tien can thanh toan: %.0f VND\n", tien);
}

void chucNang4()
{
    int kwh;
    float tien = 0;

    printf("Nhap so kWh dien su dung: ");
    scanf("%d", &kwh);

    if (kwh < 0)
    {
        printf("So kWh khong hop le.\n");
        return;
    }

    if (kwh <= 50)
    {
        tien = kwh * 1678;
    }
    else if (kwh <= 100)
    {
        tien = 50 * 1678 + (kwh - 50) * 1734;
    }
    else if (kwh <= 200)
    {
        tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
    }
    else if (kwh <= 300)
    {
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
    }
    else if (kwh <= 400)
    {
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
    }
    else
    {
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;
    }

    printf("So tien dien can tra: %.0f VND\n", tien);
}

void chucNang5()
{
    int soTien;

    printf("Nhap so tien can doi: ");
    scanf("%d", &soTien);

    if (soTien <= 0)
    {
        printf("So tien khong hop le.\n");
        return;
    }

    int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int soTo;

    printf("Cac menh gia duoc doi:\n");

    for (int i = 0; i < 9; i++)
    {
        if (soTien >= menhGia[i])
        {
            soTo = soTien / menhGia[i];
            printf("%d to %d\n", soTo, menhGia[i]);
            soTien = soTien % menhGia[i];
        }
    }
}

void chucNang6()
{
    double tienVay;

    printf("Nhap so tien muon vay: ");
    scanf("%lf", &tienVay);

    if (tienVay <= 0)
    {
        printf("So tien vay khong hop le.\n");
        return;
    }

    int kyHan = 12;
    double laiSuat = 0.05;
    double gocHangThang = tienVay / kyHan;
    double duNo = tienVay;

    printf("\nKy han | Lai phai tra | Goc phai tra | Tong phai tra | So tien con lai\n");

    for (int i = 1; i <= kyHan; i++)
    {
        double lai = duNo * laiSuat;
        double tong = lai + gocHangThang;
        duNo -= gocHangThang;

        if (duNo < 0)
            duNo = 0;

        printf("%6d | %12.0f | %13.0f | %13.0f | %14.0f\n",
               i, lai, gocHangThang, tong, duNo);
    }
}

void chucNang7()
{
    double giaXe = 500000000;
    double phanTramVay;

    printf("Nhap phan tram vay (VD 80): ");
    scanf("%lf", &phanTramVay);

    if (phanTramVay <= 0 || phanTramVay > 100)
    {
        printf("Phan tram khong hop le.\n");
        return;
    }

    double tienVay = giaXe * phanTramVay / 100;
    double tienTraTruoc = giaXe - tienVay;

    int soThang = 24 * 12;
    double laiSuatThang = 0.072 / 12;

    double gocHangThang = tienVay / soThang;
    double duNo = tienVay;

    printf("\nTien tra truoc: %.0f VND\n", tienTraTruoc);
    printf("Tien phai tra hang thang:\n");

    for (int i = 1; i <= soThang; i++)
    {
        double lai = duNo * laiSuatThang;
        double tong = gocHangThang + lai;
        duNo -= gocHangThang;
        if (duNo < 0)
            duNo = 0;

        printf("Thang %3d: %.0f VND\n", i, tong);
    }
}

#include <string.h>

struct SinhVien
{
    char hoTen[100];
    float diem;
};

void chucNang8()
{
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();

    struct SinhVien ds[n], temp;

    for (int i = 0; i < n; i++)
    {
        printf("\nSinh vien thu %d\n", i + 1);

        printf("Nhap ho ten: ");
        fgets(ds[i].hoTen, sizeof(ds[i].hoTen), stdin);
        ds[i].hoTen[strcspn(ds[i].hoTen, "\n")] = 0;

        printf("Nhap diem: ");
        scanf("%f", &ds[i].diem);
        getchar();
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ds[i].diem < ds[j].diem)
            {
                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    printf("\nDanh sach sinh vien sau khi sap xep:\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nHo ten: %s\n", ds[i].hoTen);
        printf("Diem: %.2f\n", ds[i].diem);

        if (ds[i].diem >= 9)
            printf("Hoc luc: Xuat sac\n");
        else if (ds[i].diem >= 8)
            printf("Hoc luc: Gioi\n");
        else if (ds[i].diem >= 6.5)
            printf("Hoc luc: Kha\n");
        else if (ds[i].diem >= 5)
            printf("Hoc luc: Trung binh\n");
        else
            printf("Hoc luc: Yeu\n");
    }
}

void chucNang9()
{
    int so1, so2;
    int heThong1, heThong2;

    printf("Nhap so thu nhat (1-15): ");
    scanf("%d", &so1);

    printf("Nhap so thu hai (1-15): ");
    scanf("%d", &so2);

    if (so1 < 1 || so1 > 15 || so2 < 1 || so2 > 15 || so1 == so2)
    {
        printf("So nhap khong hop le.\n");
        return;
    }

    heThong1 = rand() % 15 + 1;

    do
    {
        heThong2 = rand() % 15 + 1;
    } while (heThong2 == heThong1);

    printf("\nSo he thong: %02d - %02d\n", heThong1, heThong2);

    int trung = 0;

    if (so1 == heThong1 || so1 == heThong2)
        trung++;
    if (so2 == heThong1 || so2 == heThong2)
        trung++;

    if (trung == 2)
    {
        printf("Chuc mung ban da trung giai nhat!\n");
    }
    else if (trung == 1)
    {
        printf("Chuc mung ban da trung giai nhi!\n");
    }
    else
    {
        printf("Chuc ban may man lan sau!\n");
    }
}

int UCLN(int a, int b)
{
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

void rutGon(int *tu, int *mau)
{
    int ucln = UCLN(abs(*tu), abs(*mau));
    *tu /= ucln;
    *mau /= ucln;

    if (*mau < 0)
    {
        *tu = -*tu;
        *mau = -*mau;
    }
}

void chucNang10()
{
    int tu1, mau1, tu2, mau2;

    printf("Nhap phan so thu 1 (tu mau): ");
    scanf("%d %d", &tu1, &mau1);

    printf("Nhap phan so thu 2 (tu mau): ");
    scanf("%d %d", &tu2, &mau2);

    if (mau1 == 0 || mau2 == 0)
    {
        printf("Mau so khong duoc bang 0.\n");
        return;
    }

    int tongTu = tu1 * mau2 + tu2 * mau1;
    int tongMau = mau1 * mau2;

    int hieuTu = tu1 * mau2 - tu2 * mau1;
    int hieuMau = mau1 * mau2;

    int tichTu = tu1 * tu2;
    int tichMau = mau1 * mau2;

    int thuongTu = tu1 * mau2;
    int thuongMau = mau1 * tu2;

    rutGon(&tongTu, &tongMau);
    rutGon(&hieuTu, &hieuMau);
    rutGon(&tichTu, &tichMau);
    rutGon(&thuongTu, &thuongMau);

    printf("\nTong: %d/%d\n", tongTu, tongMau);
    printf("Hieu: %d/%d\n", hieuTu, hieuMau);
    printf("Tich: %d/%d\n", tichTu, tichMau);
    printf("Thuong: %d/%d\n", thuongTu, thuongMau);
}

int main()
{
    int chonChucNang;

    do
    {
        printf("Chon chuc nang:\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim Uoc so chung va boi so chung cua 2 so\n");
        printf("3. Tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chonChucNang);

        switch (chonChucNang)
        {
        case 1:
            // Gọi hàm kiểm tra số nguyên
            printf("DA CHON CHUC NANG 1: KIEM TRA SO NGUYEN\n");
            chucNang1();
            break;
        case 2:
            // Gọi hàm tìm Ước số chung và bội số chung
            printf("DA CHON CHUC NANG 2: TIM UOC SO CHUNG VA BOI SO CHUNG CUA 2 SO\n");
            chucNang2();
            break;
        case 3:
            // Gọi hàm tính tiền cho quán Karaoke
            printf("DA CHON CHUC NANG 3: TINH TIEN CHO QUAN KARAOKE\n");
            chucNang3();
            break;
        case 4:
            // Gọi hàm tính tiền điện
            printf("DA CHON CHUC NANG 4: TINH TIEN DIEN\n");
            chucNang4();
            break;
        case 5:
            // Gọi hàm đổi tiền
            printf("DA CHON CHUC NANG 5: DOI TIEN\n");
            chucNang5();
            break;
        case 6:
            // Gọi hàm tính lãi suất vay ngân hàng
            printf("DA CHON CHUC NANG 6: TINH LAI SUAT VAY NGAN HANG VAY TRA GOP\n");
            chucNang6();
            break;
        case 7:
            // Gọi hàm vay tiền mua xe
            printf("DA CHON CHUC NANG 7: VAY TIEN MUA XE\n");
            chucNang7();
            break;
        case 8:
            // Gọi hàm sắp xếp thông tin sinh viên
            printf("DA CHON CHUC NANG 8: SAP XEP THONG TIN SINH VIEN\n");
            chucNang8();
            break;
        case 9:
            // Gọi hàm game FPOLY-LOTT
            printf("DA CHON CHUC NANG 9: GAME FPOLY-LOTT\n");
            chucNang9();
            break;
        case 10:
            // Gọi hàm tính toán phân số
            printf("DA CHON CHUC NANG 10: TINH TOAN PHAN SO\n");
            chucNang10();
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (chonChucNang != 0);

    return 0;
}