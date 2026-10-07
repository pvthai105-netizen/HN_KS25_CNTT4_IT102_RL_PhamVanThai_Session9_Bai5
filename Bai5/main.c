#include <stdio.h>
#include <string.h>

struct VeMayBay {
    char maDatCho[10];
    char tenHanhKhach[50];
    int hangVe;
    float khoiLuongHanhLy;
    double tongTienVe;
};

int main(void) {
    struct VeMayBay danhSachVe[100];
    int soLuong = 0;
    int luaChon;
    int i, j;
    int viTri;
    int found;
    int hangVeMoi;
    char maPNR[10];
    float khoiLuongMoi;
    double giaVe;
    double phuPhi;
    double tongDoanhThu;
    int viTriCaoNhat;

    do {
        printf("\n================ HE THONG QUAN LY VE MAY BAY ================\n");
        printf("1. Them moi ve may bay (Create)\n");
        printf("2. Hien thi danh sach ve may bay (Read)\n");
        printf("3. Cap nhat hang ve va hanh ly theo ma PNR (Update)\n");
        printf("4. Huy / Xoa ve may bay theo ma PNR (Delete)\n");
        printf("5. Thong ke tong doanh thu va ve co tien cao nhat\n");
        printf("6. Thoat chuong trinh\n");
        printf("==============================================================\n");
        printf("Lua chon cua ban (1-6): ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                printf("\n--- THEM MOI VE MAY BAY ---\n");

                if (soLuong >= 100) {
                    printf("LOI: Danh sach ve da den gioi han toi da (100)!\n");
                    break;
                }

                printf("Nhap ma PNR dat cho: ");
                scanf("%9s", maPNR);

                found = 0;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(danhSachVe[i].maDatCho, maPNR) == 0) {
                        found = 1;
                        break;
                    }
                }

                if (found == 1) {
                    printf("LOI: Ma PNR %s da ton tai trong he thong!\n", maPNR);
                    break;
                }

                strcpy(danhSachVe[soLuong].maDatCho, maPNR);

                while (getchar() != '\n');

                printf("Nhap ho ten hanh khach: ");
                fgets(danhSachVe[soLuong].tenHanhKhach,
                      sizeof(danhSachVe[soLuong].tenHanhKhach), stdin);

                danhSachVe[soLuong].tenHanhKhach[
                    strcspn(danhSachVe[soLuong].tenHanhKhach, "\n")
                ] = '\0';

                do {
                    printf("Nhap hang ve (1-Eco, 2-Deluxe, 3-Business): ");
                    scanf("%d", &danhSachVe[soLuong].hangVe);

                    if (danhSachVe[soLuong].hangVe < 1 ||
                        danhSachVe[soLuong].hangVe > 3) {
                        printf("Hang ve khong hop le! Vui long nhap lai.\n");
                    }
                } while (danhSachVe[soLuong].hangVe < 1 ||
                         danhSachVe[soLuong].hangVe > 3);

                do {
                    printf("Nhap khoi luong hanh ly ky gui (kg): ");
                    scanf("%f", &danhSachVe[soLuong].khoiLuongHanhLy);

                    if (danhSachVe[soLuong].khoiLuongHanhLy < 0) {
                        printf("Khoi luong hanh ly khong duoc am!\n");
                    }
                } while (danhSachVe[soLuong].khoiLuongHanhLy < 0);

                /* Tinh gia ve co ban */
                if (danhSachVe[soLuong].hangVe == 1) {
                    giaVe = 1200000;
                } else if (danhSachVe[soLuong].hangVe == 2) {
                    giaVe = 2500000;
                } else {
                    giaVe = 5000000;
                }

                /* Tinh phu phi hanh ly */
                if (danhSachVe[soLuong].hangVe == 3) {
                    phuPhi = 0;
                } else if (danhSachVe[soLuong].khoiLuongHanhLy <= 7.0f) {
                    phuPhi = 0;
                } else {
                    phuPhi =
                        (danhSachVe[soLuong].khoiLuongHanhLy - 7.0f) * 50000;
                }

                danhSachVe[soLuong].tongTienVe = giaVe + phuPhi;

                printf("--> Them moi ve may bay thanh cong! Tong tien ve: %.0lf VND.\n",
                       danhSachVe[soLuong].tongTienVe);

                soLuong++;
                break;

            case 2:
                printf("\n--- DANH SACH VE MAY BAY ---\n");

                if (soLuong == 0) {
                    printf("Hien tai chua co ve may bay nao trong he thong.\n");
                    break;
                }

                printf("--------------------------------------------------------------------------------\n");
                printf("%-5s %-10s %-22s %-12s %12s %18s\n",
                       "STT", "Ma PNR", "Ho Ten Hanh Khach",
                       "Hang Ve", "Hanh Ly (kg)", "Tong Tien (VND)");
                printf("--------------------------------------------------------------------------------\n");

                for (i = 0; i < soLuong; i++) {
                    if (danhSachVe[i].hangVe == 1) {
                        printf("%-5d %-10s %-22s %-12s %12.1f %18.0lf\n",
                               i + 1,
                               danhSachVe[i].maDatCho,
                               danhSachVe[i].tenHanhKhach,
                               "Eco",
                               danhSachVe[i].khoiLuongHanhLy,
                               danhSachVe[i].tongTienVe);
                    } else if (danhSachVe[i].hangVe == 2) {
                        printf("%-5d %-10s %-22s %-12s %12.1f %18.0lf\n",
                               i + 1,
                               danhSachVe[i].maDatCho,
                               danhSachVe[i].tenHanhKhach,
                               "Deluxe",
                               danhSachVe[i].khoiLuongHanhLy,
                               danhSachVe[i].tongTienVe);
                    } else {
                        printf("%-5d %-10s %-22s %-12s %12.1f %18.0lf\n",
                               i + 1,
                               danhSachVe[i].maDatCho,
                               danhSachVe[i].tenHanhKhach,
                               "Business",
                               danhSachVe[i].khoiLuongHanhLy,
                               danhSachVe[i].tongTienVe);
                    }
                }

                printf("--------------------------------------------------------------------------------\n");
                break;

            case 3:
                printf("\n--- CAP NHAT VE MAY BAY ---\n");

                if (soLuong == 0) {
                    printf("Hien tai chua co ve may bay nao trong he thong.\n");
                    break;
                }

                printf("Nhap ma PNR can cap nhat: ");
                scanf("%9s", maPNR);

                found = 0;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(danhSachVe[i].maDatCho, maPNR) == 0) {
                        found = 1;
                        viTri = i;
                        break;
                    }
                }

                if (found == 0) {
                    printf("LOI: Khong tim thay ve may bay co ma PNR %s!\n",
                           maPNR);
                    break;
                }

                do {
                    printf("Nhap hang ve moi (1-Eco, 2-Deluxe, 3-Business): ");
                    scanf("%d", &hangVeMoi);

                    if (hangVeMoi < 1 || hangVeMoi > 3) {
                        printf("Hang ve khong hop le! Vui long nhap lai.\n");
                    }
                } while (hangVeMoi < 1 || hangVeMoi > 3);

                do {
                    printf("Nhap khoi luong hanh ly moi (kg): ");
                    scanf("%f", &khoiLuongMoi);

                    if (khoiLuongMoi < 0) {
                        printf("Khoi luong hanh ly khong duoc am!\n");
                    }
                } while (khoiLuongMoi < 0);

                danhSachVe[viTri].hangVe = hangVeMoi;
                danhSachVe[viTri].khoiLuongHanhLy = khoiLuongMoi;

                if (hangVeMoi == 1) {
                    giaVe = 1200000;
                } else if (hangVeMoi == 2) {
                    giaVe = 2500000;
                } else {
                    giaVe = 5000000;
                }

                if (hangVeMoi == 3) {
                    phuPhi = 0;
                } else if (khoiLuongMoi <= 7.0f) {
                    phuPhi = 0;
                } else {
                    phuPhi = (khoiLuongMoi - 7.0f) * 50000;
                }

                danhSachVe[viTri].tongTienVe = giaVe + phuPhi;

                printf("Cap nhat thanh cong! Tong tien ve moi: %.0lf VND\n",
                       danhSachVe[viTri].tongTienVe);
                break;

            case 4:
                printf("\n--- HUY / XOA VE MAY BAY ---\n");

                if (soLuong == 0) {
                    printf("Hien tai chua co ve may bay nao trong he thong.\n");
                    break;
                }

                printf("Nhap ma PNR can huy xoa: ");
                scanf("%9s", maPNR);

                found = 0;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(danhSachVe[i].maDatCho, maPNR) == 0) {
                        found = 1;
                        viTri = i;
                        break;
                    }
                }

                if (found == 0) {
                    printf("LOI: Khong tim thay ve may bay co ma PNR %s!\n",
                           maPNR);
                    break;
                }

                for (j = viTri; j < soLuong - 1; j++) {
                    danhSachVe[j] = danhSachVe[j + 1];
                }

                soLuong--;

                printf("Da huy va xoa ve [%s] thanh cong!\n", maPNR);
                break;

            case 5:
                printf("\n--- THONG KE FINTECH & DOANH THU ---\n");

                if (soLuong == 0) {
                    printf("Hien tai chua co ve may bay nao trong he thong.\n");
                    break;
                }

                tongDoanhThu = 0;
                viTriCaoNhat = 0;

                for (i = 0; i < soLuong; i++) {
                    tongDoanhThu += danhSachVe[i].tongTienVe;

                    if (danhSachVe[i].tongTienVe >
                        danhSachVe[viTriCaoNhat].tongTienVe) {
                        viTriCaoNhat = i;
                    }
                }

                printf("Tong doanh thu cac ve hien tai: %.0lf VND\n",
                       tongDoanhThu);

                printf("Thong tin ve co tong tien cao nhat:\n");
                printf("- Ma PNR: %s\n",
                       danhSachVe[viTriCaoNhat].maDatCho);
                printf("- Hanh khach: %s\n",
                       danhSachVe[viTriCaoNhat].tenHanhKhach);
                printf("- Tong tien: %.0lf VND\n",
                       danhSachVe[viTriCaoNhat].tongTienVe);
                break;

            case 6:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long chon tu 1 den 6.\n");
        }

    } while (luaChon != 6);

    return 0;
}
