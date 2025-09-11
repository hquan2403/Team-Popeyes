#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <set>
using namespace std;

const double HocPhi1TC  = 450000;
const double HocPhiEvening = 4000000;
const double PhuPhiTaiLieu = 50000;

class SV{
	private:
		string Masinhvien;
		string Hoten;
		string Date;
		string Nganh;
		string Gmail;
	public:
		// construct , coppy construct , destruct
		
		SV(
			string _Masinhvien= "1234",
			string _Hoten="quandepzai",
			string _Date="1/1/2000",
			string _Nganh="CNTT",
			string _Gmail="ElonMusk@gmail.com"
		){
			Masinhvien=_Masinhvien;
			Hoten = chuanHoaTen(_Hoten);    
			Date = chuanHoaNS(_Date);
			Nganh=_Nganh;
			Gmail=taoGmail(Hoten, Masinhvien);
		}
		
		SV(const SV &k){
			Masinhvien=k.Masinhvien;
			Hoten=k.Hoten;
			Date=k.Date;
			Nganh=k.Nganh;
			Gmail=k.Gmail;
		}
		
		~SV(){}
		
		
		string taoGmail (string hoten, string masinhvien) {
			string gmail = "";
			for(char c : hoten) {
				if(c != ' ') {
					gmail += tolower(c);
				}
			}
			gmail += "_" + masinhvien;
			gmail += "@gmail.hcmue.edu.vn";
			return gmail;
		}
		
		// Hàm chuẩn hóa tên
		string chuanHoaTen (string s) {
			stringstream ss(s); 
			string res = "";
			string x;
			while(ss>>x) {
				x[0] = toupper(x[0]);
				for(int i = 1; i < x.size(); i++) {
					x[i] = tolower(x[i]);
				}	
				res += x + " ";
			}
			res.pop_back(); 
			return res;
		}
		
		// Kiểm tra năm nhuận
		bool NamNhuan(int nam) {
			return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
		}
		
		// Kiểm tra ngày
		bool Ngay(int ngay, int thang, int nam) {
			if(nam < 1900 || nam > 2100 || thang < 1 || thang > 12 || ngay < 1) {
				return false;
			}
			int ngayTrongThang[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
			if(thang == 2 && NamNhuan(nam)) {
				return ngay <= 29;
			}
			return ngay <= ngayTrongThang[thang];
		}
		// Hàm chuẩn hóa ngày sinh
		string chuanHoaNS(const string& s) {
			int ngay, thang , nam;
			char sep1, sep2;
			
			// Nhập đúng định dạng dd/mm/yyyy
			stringstream ss1(s);
			if(ss1 >> ngay >> sep1 >> thang >> sep2 >> nam) {
				string thua;
				if (sep1 != '/' || sep2 != '/' || (ss1 >> thua)) {
        			return "";
    			}
				if(!Ngay(ngay, thang, nam)) {
					return "";
				}
				stringstream kq;
				kq << setw(2) << setfill('0') << ngay << "/" << setw(2) << setfill('0') << thang << "/" << nam;
       			return kq.str();
			}
        	// Nhập không gạch (3052006 hay 300052006)
			string s_clean = s;
    		for (char& c : s_clean) {
       			if (!isdigit(c)){
        			return "";
				} 
    		}
    		if (s_clean.length() == 8) {
    			// Giả sử là dd mm yyyy
        		ngay = stoi(s_clean.substr(0, 2));
       			thang = stoi(s_clean.substr(2, 2));
       			nam = stoi(s_clean.substr(4, 4));
   			} else if (s_clean.length() == 7) {
   				// Giả sử là d mm yyyy hoặc dd m yyyy
       			int d1 = stoi(s_clean.substr(0, 1));
        		int m1 = stoi(s_clean.substr(1, 2));
        		int y1 = stoi(s_clean.substr(3, 4));
        		if(Ngay(d1, m1, y1)) {
        			ngay = d1; thang = m1; nam = y1;
				} else {
					int d2 = stoi(s_clean.substr(0, 2));
					int m2 = stoi(s_clean.substr(2, 1));
					int y2 = stoi(s_clean.substr(3, 4));
				 	if (Ngay(d2, m2, y2)) {
						ngay = d2; thang = m2; nam = y2;
					} else {
						return "";
					}	
				}	
    		} 	else {
       				return "";
    			}
    		if (!Ngay(ngay, thang, nam)) {
        		return "";
    		}
    		stringstream kq;
    		kq << setw(2) << setfill('0') << ngay << "/" << setw(2) << setfill('0') << thang << "/" << nam;
    		return kq.str();
		}
		
		// get
		
		string getMasinhvien(){ return Masinhvien;}
		string getHoten(){ return Hoten;}
		string getDate(){return Date;}
		string getNganh(){return Nganh;}
		string getGmail(){return Gmail;}
		virtual string getLoai()=0;
		
		// set
		
		void setMasinhvien(string a=" "){ 
			Masinhvien=a;
			Gmail = taoGmail(Hoten, Masinhvien);
		}
		void setHoten(string a = " ") {
		    Hoten = chuanHoaTen(a);
		    Gmail = taoGmail(Hoten, Masinhvien);
		}
		void setDate(string a=" "){Date=a;}
		void setNganh(string a=" "){Nganh=a;}
		void setGmail(string a=" "){Gmail=a;}
		
		friend istream& operator >> (istream& is, SV &a){
			cout<<"Ma sinh vien: "<<a.Masinhvien<<endl;
			cout<<"Nhap ho ten: ";
			getline(is,a.Hoten);
			a.Hoten = a.chuanHoaTen(a.Hoten);
			cout<<"Nhap ngay sinh: ";
			getline(is,a.Date);
			a.Date = a.chuanHoaNS(a.Date);
			cout<<"Nhap Nganh: ";
			getline(is,a.Nganh);
			a.Gmail = a.taoGmail(a.Hoten, a.Masinhvien);
			return is;
		}
		
		virtual long long TinhHocPhi()=0;
		
		friend ostream& operator << (ostream& out, SV &a){
			out<<". Loai sinh vien: "<<a.getLoai()<<endl;
			out<<"Ma sinh vien: "<<a.getMasinhvien()<<endl;
			out<<"Ho ten: "<<a.getHoten()<<endl;
			out<<"Ngay sinh: "<<a.getDate()<<endl;
			out<<"Nganh: "<<a.getNganh()<<endl;
			out<<"Gmail: "<<a.getGmail()<<endl;
			return out;
		}
		
		string formatTien(long long soTien) const {
		    if (soTien < 0) return "-" + formatTien(-soTien);
		    if (soTien < 1000000) {
		        return to_string(soTien) + " dong";
		    }
		    long long trieu = soTien / 1000000;
		    long long le = (soTien % 1000000) / 1000; // Lấy phần nghìn
		    if (le == 0) {
		        return to_string(trieu) + "tr";
		    }
		    return to_string(trieu) + "tr" + to_string(le);
		}
		
		virtual string getLoai2()=0;
		virtual void Nhap(){
			cin>>*this;
			Hoten = chuanHoaTen(Hoten);  
    		Date = chuanHoaNS(Date);  
		}
		
		virtual void Xuat(){
			cout<<*this;
		}
			
};

class SV_ChinhQuy : public SV{
	private:
		int Hocbong;
		int Tinchi;
	public:
		// construct , coppy construct , destruct
		
		SV_ChinhQuy(
			string _Masinhvien= "1234",
			string _Hoten="quandepzai",
			string _Date="1/1/2000",
			string _Nganh="CNTT",
			string _Gmail="ElonMusk@gmail.com",
			int _Tinchi=1,
			int _Hocbong=1)
		:SV(_Masinhvien,_Hoten,_Date,_Nganh,_Gmail){
			Hocbong=_Hocbong;
			Tinchi=_Tinchi;
		}
		
		SV_ChinhQuy(const SV_ChinhQuy &k):SV(k){
			Hocbong=k.Hocbong;
			Tinchi=k.Tinchi;
		}
		
		~SV_ChinhQuy(){}
		
		// get
		
		int getHocbong(){return Hocbong;}
		int getTinchi(){return Tinchi;}
		string getLoai(){return "SV Chinh Quy";}
		
		// set
		
		void setHocbong(int a=1){Hocbong=a;}
		void setTinchi(int a=1){Tinchi=a;}
		
		
		
		friend istream& operator >> (istream& is, SV_ChinhQuy &a){
			a.SV::Nhap();
			cout<<"So tin chi: ";
			is>>a.Tinchi;
			cout<<"Hoc bong: ";
			is>>a.Hocbong;
			return is;
		}
		
		long long TinhHocPhi(){
			return Tinchi * HocPhi1TC - Hocbong;
		}
		
		friend ostream& operator << (ostream& os, SV_ChinhQuy &a){
			a.SV::Xuat();
			os<<"So hoc phi can dong la: "<<a.formatTien(a.TinhHocPhi())<<" dong"<<endl;
			return os;
		}
		string getLoai2(){
			return "CQ";
		}
		void Nhap(){
			cin>>*this;
			cout<<endl;
		}
		
		void Xuat(){
			cout<<*this;
		}
		
};

class SV_VuaHocVuaLam:public SV{
	private:
		string Noilamviec;
		int Ky;
	public:
		// construct , coppy construct , destruct
		
		SV_VuaHocVuaLam(
			string _Masinhvien= "1234",
			string _Hoten="quandepzai",
			string _Date="1/1/2000",
			string _Nganh="CNTT",
			string _Gmail="ElonMusk@gmail.com",
			string _Noilamviec= "HCMUE",
			int _Ky=1)
		:SV(_Masinhvien,_Hoten,_Date,_Nganh,_Gmail){
			Noilamviec=_Noilamviec;
			Ky=_Ky;
		}
		
		SV_VuaHocVuaLam(const SV_VuaHocVuaLam &k):SV(k){
			Noilamviec=k.Noilamviec;
			Ky=k.Ky;
		}
		
		~SV_VuaHocVuaLam(){}
		
		// get
		
		string getNoilamviec(){return Noilamviec;}
		int getKy(){return Ky;}
		string getLoai(){return "SV Vua hoc vua lam";}
		
		// set
		
		void setNoilamviec(string a= " "){Noilamviec=a;}
		void setKy(int a=1){Ky=a;}
		
		friend istream& operator >> (istream& is , SV_VuaHocVuaLam &a){
			a.SV::Nhap();
			cout<<"Noi lam viec: ";
			is.ignore(); 
			getline(is,a.Noilamviec);
			cout<<"So luong hoc ki: ";
			is>>a.Ky;
			return is;
		}
		
		long long TinhHocPhi(){
			return HocPhiEvening * Ky;
		}
		
		friend ostream& operator << (ostream& os , SV_VuaHocVuaLam &a){
			a.SV::Xuat();
			os<<"Noi lam viec: "<<a.Noilamviec<<endl;
    		os<<"So luong hoc ki: "<<a.Ky<<endl;
			os<<"So hoc phi can dong la: "<<a.formatTien(a.TinhHocPhi())<<" dong"<<endl;
			return os;
		}
		string getLoai2(){
			return "VHVL";
		}
		void Nhap(){
			cin>>*this;
			cout<<endl;
		}
		
		void Xuat(){
			cout<<*this;	
		}
		
};

class SV_DaoTaoTuXa:public SV{
	private:
		string Diachi;
		int Tinchi;
		int CacLoaiPhiKhac;
	public:
		// construct , coppy construct , destruct
		
		SV_DaoTaoTuXa(
			string _Masinhvien= "1234",
			string _Hoten="quandepzai",
			string _Date="1/1/2000",
			string _Nganh="CNTT",
			string _Gmail="ElonMusk@gmail.com",
			string _Diachi="quan 5",
			int _Tinchi =1,
			int _CacLoaiPhiKhac=1)
		:SV(_Masinhvien,_Hoten,_Date,_Nganh,_Gmail){
			Diachi=_Diachi;
			Tinchi=_Tinchi;
			CacLoaiPhiKhac=_CacLoaiPhiKhac;
		}
		
		SV_DaoTaoTuXa(const SV_DaoTaoTuXa &k):SV(k){
			Diachi=k.Diachi;
			Tinchi=k.Tinchi;
			CacLoaiPhiKhac=k.CacLoaiPhiKhac;
		}
		
		~SV_DaoTaoTuXa(){}
		
		// get
		
		string getDiachi(){return Diachi;}
		int getTinchi(){return Tinchi;}
		int getCacLoaiPhiKhac(){return CacLoaiPhiKhac;}
		string getLoai(){return "SV Dao tao tu xa";}
		
		// set
		
		void setDiachi(string a=" "){Diachi=a;}
		void setTinchi(int a=1){Tinchi=a;}
		void setCacLoaiPhiKhac(int a=1){CacLoaiPhiKhac=a;}
		
		friend istream& operator >> (istream& is, SV_DaoTaoTuXa &a){
			a.SV::Nhap();
			cout<<"Dia chi: ";
			is.ignore();
			getline(is,a.Diachi);
			cout<<"Tin chi: ";
			is>>a.Tinchi;
			cout<<"Cac loai phi khac: ";
			is>>a.CacLoaiPhiKhac;
			return is;
		}
		
		long long TinhHocPhi(){
			return Tinchi * HocPhi1TC + PhuPhiTaiLieu + CacLoaiPhiKhac;
		}
		
		friend ostream& operator << (ostream& os, SV_DaoTaoTuXa &a){
			a.SV::Xuat();
			os<<"So hoc phi can dong la: "<<a.formatTien(a.TinhHocPhi())<<" dong"<<endl;
			os<<"Dia chi: "<<a.Diachi<<endl;
			return os;
		}
		string getLoai2(){
			return "DTTX";
		}
		void Nhap(){
			cin>>*this;
			cout<<endl;
		}
		
		void Xuat(){
			cout<<*this;
		}
};
class QuanLySV{
	private:
		int n = 0;
		vector<SV*> sv;
		
		string TaoMaSinhVien() {
		    int maxId = 0;
		    for (SV* student : sv) {
		        string msv = student->getMasinhvien();
		            int id = stoi(msv.substr(2)); // Bỏ "SV" và lấy số
		            maxId = max(maxId, id);
		    }
		    // Tạo MSV mới bằng cách tăng maxId lên 1
		    stringstream ss;
		    ss << "SV" << setw(6) << setfill('0') << (maxId + 1);
		    return ss.str();
		    
		}
	public:
		
		void CapNhatSV(){
			ifstream fin("DanhSachSinhVien.txt");
			
			if (!fin.is_open()) {
		        cout << "Khong the mo file DanhSachSinhVien.txt!" << endl;
		        return;
		    }
			
			string s;
			
		    while (fin >> s) {
		        fin.ignore(); 
				
				string masv, hoten, date, nganh, gmail;
		        getline(fin, hoten);
		        getline(fin, date);
		        getline(fin, nganh);
		        
		        
		        int hocbong , tinchi;
		        
		        string Noilamviec;
				int Ky;
		        
		        string Diachi;
				int CacLoaiPhiKhac;
				
				
		        SV* t_sv = nullptr;
		        masv = TaoMaSinhVien();
		        if (s == "CQ") {
		        
		        	fin >> tinchi >> hocbong;
		            t_sv = new SV_ChinhQuy(masv , hoten , date , nganh , gmail , tinchi , hocbong);
		        } 
				else if (s == "VHVL") {
		        	getline(fin, Noilamviec);
		        	fin>>Ky;
		            t_sv = new SV_VuaHocVuaLam(masv , hoten , date , nganh , gmail , Noilamviec , Ky);
		        } 
				else if (s == "DTTX"){
		        	getline(fin, Diachi);
		        	fin>>tinchi>>CacLoaiPhiKhac;
		            t_sv = new SV_DaoTaoTuXa( masv , hoten , date , nganh , gmail , Diachi ,tinchi , CacLoaiPhiKhac);
		        }
		        else {
		        	return;
				}
		        sv.push_back(t_sv);
				
				n++;
			
			}
			fin.close();
	}
		void ThemSV(){
			ofstream fout("DanhSachSinhVien.txt", ios::app);
			string s;
			
			while(true) {
				cout << "\nNhap loai sinh vien (CQ / VHVL / DTTX): ";
	        	cin >> s;
	    		cin.ignore();
	    		if(s == "CQ" || s == "VHVL" || s == "DTTX") {
	    			break;
				} else {
					cout<<endl;
					cout << "Loai sinh vien khong hop le! Vui long nhap lai.\n";
				}
			}	
			fout<<s<<endl;
			SV* t_sv = nullptr; 
			
			string masv, hoten, date, nganh, gmail;
			masv = TaoMaSinhVien();
			
			cout<<"Ma sinh vien: "<<masv<<endl;
			cout<<"Nhap ho ten: ";
		    getline(cin, hoten);
		    cout<<"Nhap ngay sinh: ";
		    getline(cin, date);
		    cout<<"Nhap Nganh: ";
		    getline(cin, nganh);

			fout<<hoten<<endl;
			fout<<date<<endl;
			fout<<nganh<<endl;
			   
		    int hocbong , tinchi;
		        
		    string Noilamviec;
			int Ky;
		    
		    string Diachi;
			int CacLoaiPhiKhac;
			
			
			
	        if (s == "CQ") {
	        	cout << "So tin chi: ";
				do {
				    cin >> tinchi;
				    if (tinchi < 0) {
				        cout << "Tin chi phai la so nguyen duong, nhap lai: ";
				    }
				} while (tinchi < 0);
				cout << "So hoc bong: ";
				do {
				    cin >> hocbong;
				    if (hocbong < 0) {
				        cout << "Hoc bong phai la so nguyen duong, nhap lai: ";
				    }
				} while (hocbong < 0);
				
	        	fout<<tinchi<<endl;
	        	fout<<hocbong<<endl;
	            t_sv = new SV_ChinhQuy(masv , hoten , date , nganh , gmail , tinchi , hocbong);
	        } 
			else if (s == "VHVL") {
				cout<<"Noi lam viec: ";
				getline(cin,Noilamviec);
				cout << "So luong hoc ki: ";
				do {
				    cin >> Ky;
				    if (Ky < 0) {
				        cout << "So ky phai la so nguyen duong, nhap lai: ";
				    }
				} while (Ky < 0);
		        fout<<Noilamviec<<endl;
	        	fout<<Ky<<endl;
	            t_sv = new SV_VuaHocVuaLam(masv , hoten , date , nganh , gmail , Noilamviec , Ky);
	        } 
			else{
				cout<<"Dia chi: ";
				getline(cin,Diachi);
				cout<<"So tin chi: ";
				do {
				    cin >> tinchi;
				    if (tinchi < 0) {
				        cout << "Tin chi phai la so nguyen duong, nhap lai: ";
				    }
				} while (tinchi < 0);
				cout << "Cac loai phi khac: ";
				do {
				    cin >> CacLoaiPhiKhac;
				    if (CacLoaiPhiKhac < 0) {
				        cout << "Cac loai phi khac phai la so nguyen duong, nhap lai: ";
				    }
				} while (CacLoaiPhiKhac < 0);
				
				fout<<Diachi<<endl;
		        fout<<tinchi<<endl;
	        	fout<<CacLoaiPhiKhac<<endl;
	            t_sv = new SV_DaoTaoTuXa( masv , hoten , date , nganh , gmail , Diachi ,tinchi , CacLoaiPhiKhac);
	        }
	        
	        sv.push_back(t_sv);                  
	        fout<<endl;
			fout.close();
	        n++;
		}
		void XoaSVTheoMSV(){
			string maSV;
    		cout << "Nhap ma sinh vien can xoa: ";
    		cin >> maSV;
    
    		SV* svCanXoa = BS(sv, maSV);
    
    		if (svCanXoa != nullptr) {
        		auto it = find(sv.begin(), sv.end(), svCanXoa);
        		if (it != sv.end()) {	
            		delete *it; 
            		sv.erase(it); 
            		n--;
            		
            		ofstream fout("DanhSachSinhVien.txt", ios::trunc); // Mở file và ghi đè
           			if (!fout.is_open()) {
                		cout << "Khong the mo file DanhSachSinhVien.txt!" << endl;
                		return;
            		}
            
            		for (int i = 0; i < n; i++) {
                		fout << sv[i]->getLoai2() << endl;
                		fout << sv[i]->getHoten() << endl;
                		fout << sv[i]->getDate() << endl;
                		fout << sv[i]->getNganh() << endl;
                		
                
                		if (sv[i]->getLoai2() == "CQ") {
                    		SV_ChinhQuy* cq = dynamic_cast<SV_ChinhQuy*>(sv[i]);
                    		fout << cq->getTinchi() << endl;
                    		fout << cq->getHocbong() << endl;
                		} else if (sv[i]->getLoai2() == "VHVL") {
                   			SV_VuaHocVuaLam* vhvl = dynamic_cast<SV_VuaHocVuaLam*>(sv[i]);
                    		fout << vhvl->getNoilamviec() << endl;
                    		fout << vhvl->getKy() << endl;
                		} else if (sv[i]->getLoai2() == "DTTX") {
                    		SV_DaoTaoTuXa* dttx = dynamic_cast<SV_DaoTaoTuXa*>(sv[i]);
                    		fout << dttx->getDiachi() << endl;
                    		fout << dttx->getTinchi() << endl;
                    		fout << dttx->getCacLoaiPhiKhac() << endl;
                		}
                		fout<<endl;
            		}	
            		fout.close();
            		cout << "Sinh vien " << maSV << " da duoc xoa!" << endl;
        		}	
    		} else {
        		cout << "Khong tim thay sinh vien voi ma " << maSV << endl;
    		}		
		}
		
		
		// Dùng binary search để tìm và xuất thông tin dùng DanhSachSinhVien.txt
		SV* BS(vector<SV*> &ds, string maSV){
			sort(ds.begin(), sv.end(), [](SV* a, SV* b) {
        		return a->getMasinhvien() < b->getMasinhvien();
    		});
			int l = 0, r = ds.size() - 1;
			while(l <= r) {
				int m = (l + r) / 2;
        		if (sv[m]->getMasinhvien() == maSV) {
           		 	return sv[m]; // Tìm thấy
        		} else if (sv[m]->getMasinhvien() < maSV) {
           			l = m + 1;
        		} else {
            		r = m - 1;
        		}
			}	
			return nullptr;
		}
		void TimSVTheoMSV() {
			string maSV;
    		cout << "Nhap ma sinh vien can tim: ";
    		cin >> maSV;
			SV* ketQua = BS(sv, maSV); // gọi đúng binary search
    		if (ketQua != nullptr) {
        		cout << "THONG TIN SINH VIEN TIM DUOC:\n";
        		cout << "Ma SV: " << ketQua->getMasinhvien() << endl;
        		cout << "Ho ten: " << ketQua->getHoten() << endl;
        		cout << "Ngay sinh: " << ketQua->getDate() << endl;
        		cout << "Nganh: " << ketQua->getNganh() << endl;
        		cout << "Gmail: " << ketQua->getGmail() << endl;
        		cout << "Loai SV: " << ketQua->getLoai() << endl;
        		cout << "Hoc phi: " << ketQua->formatTien(ketQua->TinhHocPhi()) << " dong" << endl;
    		} else {
        		cout << "Khong tim thay sinh vien!\n";
    		}
		}
	
		void DocDanhSachSV(){
			ofstream fout("view.txt");
		    if (!fout.is_open()) {
		        cout << "Khong the mo file find.txt de ghi!" << endl;
		        return;
		    }
        
			cout<<endl;
			fout << "DANH SACH SINH VIEN" << endl;
        	fout << "===================" << endl;
			for(int i=0;i<n;i++){
				cout<<(i+1);
				sv[i]->Xuat();
				cout<<endl;
				
				fout << (i + 1) << ". Loai sinh vien: " << sv[i]->getLoai() << endl;
	            fout << "Ma sinh vien: " << sv[i]->getMasinhvien() << endl;
	            fout << "Ho ten: " << sv[i]->getHoten() << endl;
	            fout << "Ngay sinh: " << sv[i]->getDate() << endl;
	            fout << "Nganh: " << sv[i]->getNganh() << endl;
	            fout << "Gmail: " << sv[i]->getGmail() << endl;
	            fout << "So hoc phi can dong la: " << sv[i]->formatTien(sv[i]->TinhHocPhi()) << " dong" << endl;
	            if(sv[i]->getLoai2()=="VHVL"){
	            	SV_VuaHocVuaLam* vhvl = dynamic_cast<SV_VuaHocVuaLam*>(sv[i]);
	            	fout << "Noi lam viec: " << vhvl->getNoilamviec() << endl;
				}
				else if(sv[i]->getLoai2()=="DTTX"){
	            	SV_DaoTaoTuXa* dttx = dynamic_cast<SV_DaoTaoTuXa*>(sv[i]);
	            	fout << "Dia chi: " << dttx->getDiachi() << endl;
				}
				else{
					fout << endl;
					continue;
				}
	            fout << endl;
	        }
	        	cout<<endl;
	        	fout << "===================" << endl;
       			fout.close();
			}
				
		void XoaToanBoSV() {
	        char confirm;
	        cout << "Ban co chac chan muon xoa toan bo danh sach sinh vien? (y/n): ";
	        cin >> confirm;
	        if (tolower(confirm) != 'y') {
	            cout << "Huy thao tac xoa!" << endl;
	            return;
	        }
	
	        for (SV* student : sv) {
	            delete student;
	        }
	        sv.clear();
	        n = 0;
	
	        ofstream foutDSSV("DanhSachSinhVien.txt", ios::trunc);
	        if (!foutDSSV.is_open()) {
	            cout << "Khong the mo file DanhSachSinhVien.txt!" << endl;
	            return;
	        }
	        foutDSSV.close();
	
	        ofstream foutView("view.txt", ios::trunc);
	        if (!foutView.is_open()) {
	            cout << "Khong the mo file view.txt!" << endl;
	            return;
	        }
	        foutView << "DANH SACH SINH VIEN" << endl;
	        foutView << "===================" << endl;
	        foutView << "===================" << endl;
	        foutView.close();
	
	        cout << "Da xoa toan bo danh sach sinh vien va cap nhat file!" << endl;
	    }
		~QuanLySV() {
	        for (int i = 0; i < n; i++) {
	            delete sv[i];
	        }
    	}
};
int main(){
	QuanLySV a;
	a.CapNhatSV();
	int n;
	const string HELLO[6] = {
        "     _   _  _____  _      _      ___   ",
        "    | | | || ____|| |    | |    / _ \\ ",
        "    | |_| ||  _|  | |    | |   | | | | ",
        "    |  _  || |___ | |___ | |___| |_| | ",
        "    |_| |_||_____||_____||_____|\\___/ ",
        "                                       "
    };

    for (int i = 0; i < 6; i++) {
        cout << HELLO[i] << endl;
    }

	cout<<"CHAO MUNG BAN DA DEN VOI TRANG QUAN LI SINH VIEN!"<<endl;
	while(true){
		cout<<"=========== MENU =============="<<endl;
		cout<<"(1) "<<"Them sinh vien."<<endl;
		cout<<"(2) "<<"Xoa sinh vien bang MSSV."<<endl;
		cout<<"(3) "<<"Tim sinh vien bang MSSV."<<endl;
		cout<<"(4) "<<"Xuat toan bo thong tin sinh vien và xuat ra file."<<endl;
		cout<<"(5) "<<"Xoa toan bo ke ca file."<<endl;
		cout<<"(0) "<<"Thoat."<<endl;
		cout<<"Nhap so: ";
		cin>>n;
		
		switch(n){
			case 0:
				return 0;
			break;
			case 1:
				a.ThemSV();
				break;
			case 2:
				a.XoaSVTheoMSV();
				break;
			case 3:
				a.TimSVTheoMSV(); 	
				break;
			case 4:
				a.DocDanhSachSV();
				break;
			case 5:
				a.XoaToanBoSV();
				break;
			default:
				cout<<"Khong hop le!";
				return 0;
				break;
		}
		
	}
	
}