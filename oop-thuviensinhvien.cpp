#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class LopSinhVien {
private:
    int MaSV;
    string HoTen;
    string NgaySinh;
    string DiaChi;
    int SoDT;
    static int nextMaSV;
public:
    LopSinhVien() {
        MaSV = nextMaSV++;
        HoTen = "0";
        NgaySinh = "0";
        DiaChi = "0";
        SoDT = 0;
    }

    LopSinhVien(int nMaSV, string nHoTen, string nNgaySinh, string nDiaChi, int nSoDT) {
        MaSV = nMaSV;
        HoTen = nHoTen;
        NgaySinh = nNgaySinh;
        DiaChi = nDiaChi;
        SoDT = nSoDT;
    }

    int getMaSV() const {
        return this->MaSV;
    }

    string getHoTen() const {
        return this->HoTen;
    }

    string getNgaySinh() const {
        return this->NgaySinh;
    }

    string getDiaChi() const {
        return this->DiaChi;
    }

    int getSoDT() const {
        return this->SoDT;
    }

    void nhapLopSinhVien() {
        cin.ignore();
        cout << "\tNhap Ho Ten: ";
        getline(cin, HoTen);
        cout << "\tNhap Ngay Sinh: ";
        getline(cin, NgaySinh);
        cout << "\tNhap Dia Chi: ";
        getline(cin, DiaChi);
        cout << "\tNhap SoDT: ";
        cin >> SoDT;
    }

    void xuatLopSinhVien() const {
        cout << setw(15) << left << MaSV << setw(15) << left
		 << HoTen << setw(15) << left << NgaySinh<< setw(15)
		 << left <<DiaChi<< setw(15) << left <<SoDT << endl;
    }
};
int LopSinhVien::nextMaSV = 100;

class LopSach {
private:
    int MaSach;
    string TenSach;
    string TacGia;
    int NamXB;
    string TheLoai;
    static int nextMaSach;

public:
    LopSach() {
        MaSach = nextMaSach++;
        TenSach = "0";
        TacGia = "0";
        NamXB = 0;
        TheLoai = "0";
    }

    LopSach(int nMaSach, string nTenSach, string nTacGia, int nNamXB, string nTheLoai) {
        MaSach = nMaSach;
        TenSach = nTenSach;
        TacGia = nTacGia;
        NamXB = nNamXB;
        TheLoai = nTheLoai;
    }

    int getMaSach() const {
        return this->MaSach;
    }

    string getTenSach() const {
        return this->TenSach;
    }

    string getTacGia() const {
        return this->TacGia;
    }

    int getNamXB() const {
        return this->NamXB;
    }

    string getTheLoai() const {
        return this->TheLoai;
    }

    void nhapLopSach() {
        cout << "\tNhap Ten Sach: ";
        getline(cin, TenSach);
        cout << "\tNhap Tac Gia: ";
        getline(cin, TacGia);
        cout << "\tNhap Nam Xuat Ban: ";
        cin >> NamXB;
        cin.ignore();
        cout << "\tNhap The Loai: ";
        getline(cin, TheLoai);
    }

    void xuatLopSach() const {
        cout << setw(15) << left << MaSach << setw(15) << left
		 << TenSach << setw(15) << left << TacGia << setw(15)
		 << left <<NamXB<< setw(15) << left <<TheLoai << endl;

    }
};
int LopSach::nextMaSach = 100;

class BangQuanLyThuVien {
private:
    vector<pair<LopSinhVien, LopSach>> danhsachmuon;

public:
    vector<LopSinhVien> DanhSachSV;
    vector<LopSach> DanhSachSach;

    void BangNhapSV() {
        int m;
        cout << "So sinh vien can nhap: ";
        cin >> m;
        DanhSachSV.reserve(m); // Reserving space to avoid reallocation
        for (int i = 0; i < m; i++) {
            cout << "Thong tin sinh vien thu " << i + 1 << ": " << endl;
            LopSinhVien sv;
            sv.nhapLopSinhVien();
            DanhSachSV.push_back(sv);
        }
    }

    void XuatDanhSachSV() {
        cout << "--------------------------------"<<endl;
        cout << "DANH SACH SINH VIEN : " << endl;
        cout << "--------------------------------"<<endl;;
        cout << left << setw(15) << "MaSV" << setw(15) << "Ho ten" << setw(15)
		<< "Ngay sinh" << setw(15) << "Dia Chi" << setw(15) << "SoDT" << endl;
        for (int i = 0; i < DanhSachSV.size(); i++) {
            DanhSachSV[i].xuatLopSinhVien();
        }
    }

    void BangNhapSach() {
        int n;
        cout << "So sach can nhap: ";
        cin >> n;
        cin.ignore();
        DanhSachSach.reserve(n); // Reserving space to avoid reallocation
        for (int i = 0; i < n; i++) {
            cout << "Thong tin sach "<< i + 1 << ": " << endl;
            LopSach sach;
            sach.nhapLopSach();
            DanhSachSach.push_back(sach);
        }
    }


    void XuatDanhSachSach() {
        cout << "--------------------------------"<<endl;
        cout << "DANH SACH SACH " << endl;
        cout << "--------------------------------"<<endl;
        cout << setw(15) << left << "Ma Sach" << setw(15) << left << "Ten Sach" << setw(15)
		<< left << "Tac Gia" << setw(15) << left <<"Nam XB"<< setw(15) << left <<"The Loai" << endl;
        for (int i = 0; i < DanhSachSach.size(); i++) {
            DanhSachSach[i].xuatLopSach();
        }
    }


    void muonSach() {
    int maSV;
    cout << "Nhap MaSV de muon sach: ";
    cin >> maSV;

    auto itSV = find_if(DanhSachSV.begin(), DanhSachSV.end(),
        [maSV](const LopSinhVien& sv) { return sv.getMaSV() == maSV; });

    if (itSV != DanhSachSV.end()) {
        int soLuongSachMuon;
        cout << "Nhap so luong sach muon: ";
        cin >> soLuongSachMuon;

        for(int i=0;i<soLuongSachMuon;i++){
            int maSach;
            cout<<"Nhap Ma Sach muon thu "<<i+1<<": ";
            cin>>maSach;

            auto itSach = find_if(danhsachmuon.begin(), danhsachmuon.end(),
                [maSach, maSV](const pair<LopSinhVien, LopSach>& muon) {
                    return muon.second.getMaSach() == maSach && muon.first.getMaSV() == maSV;
                });

            if (itSach == danhsachmuon.end()) {
                auto itSachDanhSach = find_if(DanhSachSach.begin(), DanhSachSach.end(),
                    [maSach](const LopSach& sach) { return sach.getMaSach() == maSach; });

                if (itSachDanhSach != DanhSachSach.end()) {
                    danhsachmuon.push_back(make_pair(*itSV, *itSachDanhSach));
                    cout << "DA MUON SACH THANH CONG!" << endl;
                } else {
                    cout << "Khong tim thay sach co ma " << maSach << endl;
                }
            } else {
                cout << "Sinh vien da muon sach nay truoc do." << endl;
            }
        }
        } else {
            cout << "Khong tim thay sinh vien co ma " << maSV << endl;
        }
    }


    void InThongTinMuonSach() {
        int maSV;
        cout << "Nhap MaSV de xem thong tin muon sach: ";
        cin >> maSV;

        auto it = find_if(danhsachmuon.begin(), danhsachmuon.end(),
            [maSV](const pair<LopSinhVien, LopSach>& muon) { return muon.first.getMaSV() == maSV; });

        if (it != danhsachmuon.end()) {
            cout << "Thong tin muon sach cua sinh vien MaSV " << maSV << ":" << endl;
            cout << "Ho Ten: " << it->first.getHoTen() << endl;
                    
            cout << "--------------------------------"<<endl;
            cout << "DANH SACH SACH DA MUON:" << endl;
            cout << "--------------------------------"<<endl;
            cout << setw(15) << left << "Ma Sach" << setw(15) << left << "Ten Sach" << setw(15) 
			<< left << "Tac Gia" << setw(15) << left <<"Nam XB"<< setw(15) << left <<"The Loai" << endl;
            for (const auto& muon : danhsachmuon) {
                if (muon.first.getMaSV() == maSV) {
                    muon.second.xuatLopSach();
                }
            }
        } else {
            cout << "Khong tim thay sinh vien co ma " << maSV << " trong danh sach muon sach." << endl;
        }
    }

    void traSach() {
        int maSV;
    cout << "Nhap MaSV de tra sach: ";
    cin >> maSV;

    auto it = find_if(danhsachmuon.begin(), danhsachmuon.end(),
        [maSV](const pair<LopSinhVien, LopSach>& muon) { return muon.first.getMaSV() == maSV; });

    if (it != danhsachmuon.end()) {
        int soLuongSachTra;
        cout << "Nhap so luong sach tra: ";
        cin >> soLuongSachTra;

        for (int i = 0; i < soLuongSachTra; ++i) {
            int maSach;
            cout << "Nhap Ma Sach tra lan " << i + 1 << ": ";
            cin >> maSach;

            auto itSach = find_if(danhsachmuon.begin(), danhsachmuon.end(),
                [maSach, maSV](const pair<LopSinhVien, LopSach>& muon) {
                    return muon.second.getMaSach() == maSach && muon.first.getMaSV() == maSV;
                });

            if (itSach != danhsachmuon.end()) {
                danhsachmuon.erase(itSach);
                cout << "Da tra sach co ma " << maSach << " thanh cong!" << endl;
            } else {
                cout << "Khong tim thay sach co ma " << maSach << " hoac sinh vien chua muon sach." << endl;
            }
        }
    } else {
        cout << "Khong tim thay sinh vien co ma " << maSV << " trong danh sach muon sach." << endl;
    }
    }
};

int main() {
    BangQuanLyThuVien BangMuon;
    int choice;
    
    cout<<"HE THONG QUAN LI THU VIEN SINH VIEN"<<endl<<endl;

    do {
        cout << "1. Nhap danh sach sinh vien." << endl;
        cout << "2. Nhap danh sach sach." << endl;
        cout << "3. Thong Tin SV." << endl;
        cout << "4. Thong Tin Sach." << endl;
        cout << "5. Tao phieu muon sach." << endl;
        cout << "6. Tra cuu thong tin phieu muon sach." << endl;
        cout << "7. Tra Sach." << endl;
        cout << "0. Thoat." << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            BangMuon.BangNhapSV();
            break;
        case 2:
            BangMuon.BangNhapSach();
            break;
        case 3:
            BangMuon.XuatDanhSachSV();
            break;
        case 4:
            BangMuon.XuatDanhSachSach();
            break;
        case 5:
            BangMuon.muonSach();
            break;
        case 6:
            BangMuon.InThongTinMuonSach();
            break;
        case 7:
            BangMuon.traSach();
            break;
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}
