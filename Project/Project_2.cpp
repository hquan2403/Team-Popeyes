#include <bits/stdc++.h>
#include <conio.h> // để dùng getch()
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e6;

// thuật toán: sort , search , delete.
// List Employee_Formation , add.


// Lớp làm đơn xin nghỉ
class LeaveRequest {
public:
    string username;  // ai gửi đơn
    string reason;    // lý do nghỉ
    int days;         // số ngày nghỉ

    LeaveRequest(const string &u, const string &r, int d)
        : username(u), reason(r), days(d) {}
};

// Hàm chuẩn hóa tên
string standardizeNames(string name) {
	stringstream ss(name);
	string word = "";
	string res = "";
	while(ss >> word) {
		word[0] = toupper(word[0]);
		for(int i = 1; i < word.size(); i++) {
			word[i] = tolower(word[i]);
		}
		res += word + " ";
	}
	res.pop_back();
	return res;
}

class User{
protected:
	string Username;
	string Password;
public:
	// construct , coppy construct , destruct
	User(
		const string _Username= "user111",
		const string _Password= "11111" // sửa lại mật khẩu cho đúng định dạng 111111
	){
		Username = _Username;
		Password = _Password;
	}
	User(const User &k){
		Username = k.Username;
		Password = k.Password;
	}
	virtual ~User(){}

	//get
	string getUsername() const { return Username;}
	string getPassword() const { return Password;}

	//set
	void setUsername(string a= " "){
		Username = a;
	}
	void setPassword(string a = " "){
		Password = a;
	}

	//>>, <<
	//friend istream& operator >> (istream& is, User &a){
		//cout<<"Hay nhap ten tai khoan: ";
		//getline(is,a.Username);
		//cout<<"Hay nhap mat khau cua ban: ";
		//getline(is,a.Password);
		//return is;

	//}

	public: 
	virtual void input(istream& is) {
		cout<<"Hay nhap ten tai khoan: ";
		getline(is, Username);
		cout<<"Hay nhap mat khau cua ban: ";
		getline(is, Password);
	}

	//friend ostream& operator << (ostream& os, const User &a){
	//	os<<"Ten tai khoan cua ban la: "<<a.getUsername()<<endl;
	//	os<<"Mat khau cua ban la: "<<a.getPassword()<<endl;
	//	return os;
	//}

	virtual void output(ostream& os) const {
		os<<"Ten tai khoan cua ban la: "<<getUsername()<<endl;
		os<<"Mat khau cua ban la: "<<getPassword()<<endl;
	}
};
	// Đưa các toán tử ea ngoài và để là hàm ảo để dừng vòng đệ quy
	istream& operator>>(istream& is, User& a) {
		a.input(is); // Chỉ cần gọi hàm ảo input
		return is;
	}

	ostream& operator<<(ostream& os, const User& a) {
    a.output(os); // Chỉ cần gọi hàm ảo output
    return os;
}

class Employee : public User {
	private:
	string Name;
	string Address;
	string Phonenumber;
	string Email;
	
	public:
	// construct , coppy construct , destruct
	Employee(
		const string _Username= "user111",
		const string _Password= "111111111",
		const string _Name = "Nguyen Van A",
		const string _Address= "111 Tran Hung Dao Quan 1",
		const string _Phonenumber ="1234567890",
		const string _Email ="NguyenVanA@gmail.com"
	):User(_Username,_Password){

	this->Name = _Name;
	this->Address = _Address;
	this->Phonenumber = _Phonenumber;
	this->Email = _Email;
	}	
	string getName() const{
		return Name;
	}
	string getAddress() const {
		return Address;
	}
	string getPhonenumber() const {
		return Phonenumber;
	}
	 string getEmail() const {
		return Email;
	}
	void setName(const string &_Name) { Name = _Name; }
	void setAddress(const string &_Address) { Address = _Address; }
	void setPhonenumber(const string &_Phone) { Phonenumber = _Phone; }
	void setEmail(const string &_Email) { Email = _Email; }


	void input(istream& is) override {
        User::input(is); // Gọi hàm input của lớp cha để nhập Username/Password
        // Sau đó nhập các thông tin riêng của Employee
        cout << "Hay nhap ho ten cua ban: ";
        getline(is, Name);
        cout << "Hay nhap dia chi cua ban: ";
        getline(is, Address);
        cout << "Hay nhap so dien thoai cua ban: ";
        getline(is, Phonenumber);
        cout << "Hay nhap email cua ban: ";
        getline(is, Email);
    }
	void output(ostream& os) const override {
        User::output(os); // Gọi hàm output của lớp cha để xuất thông tin chung
        // Sau đó xuất các thông tin riêng của Employee
        os << "Ho ten cua ban la: " << getName() << endl;
        os << "Dia chi cua ban la: " << getAddress() << endl;
        os << "So dien thoai cua ban la: " << getPhonenumber() << endl;
        os << "Email cua ban la: " << getEmail() << endl;
    }
}; // Kết thúc lớp Employee


// Class cho danh sách liên kết
class EmployeeList {
private:
	// Lớp Node
	class Node {
	public:
		Employee *data;
		Node *next;
		// Hàm khởi tạo cho Node
		Node(Employee *emp) : data(emp), next(nullptr) {}
	};
	Node *head;

public: 
	EmployeeList() {
		head = nullptr; 
	}
	// Hủy để tránh rò bộ nhớ
	~EmployeeList() {
		Node *current = head;
		while(current != nullptr) {
			Node *nextNode = current->next;
			delete current->data; // Xóa đối tượng Employee được trỏ bởi data
			delete current; // Xóa Node hiện tại
			current = nextNode; // Di chuyển đến Node tiếp theo
		}
	}

	// Hàm thêm nhân viên vào danh sách
	void AddEmployee(Employee *emp) {
		Node *newNode = new Node(emp);
		if(head == NULL) {
			head = newNode;
		} else {
			Node *tmp = head;
			while(tmp->next != nullptr) {
			tmp = tmp->next;
			}
			tmp->next = newNode;
		}
		cout<<"Da them nhan vien thanh cong va mat khau mac dinh cua nhan vien la 11111"<<endl;
	}

	// Hàm xóa nhân viên
	void DeleteEmployee() {
		if(!head) {
			cout<<"Danh sach rong";
			return;
		}
		cout<<"Nhap username can xoa: ";
		string username;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, username);

		// head cần xóa nằm đầu linked list
		if(head->data->getUsername() == username) {
			Node *tmp = head;
			head = head->next;
			if(tmp->data) {
				delete tmp->data;
			}
			delete tmp;
			cout<<"Da xoa nhan vien: "<<username<<endl;
			return;
		}

		// Từ thứ hai trở đi
		Node *prev = head;
		Node *cur = head->next;
		while(cur) {
			if(cur->data->getUsername() == username) {
				prev->next = cur->next;
				if(cur->data) {
					delete cur->data;
				}
				delete cur;
				cout<<"Da xoa nhan vien: "<<username<<endl;
				return;
			}
			prev = cur;
			cur = cur->next;
		}
		cout<<"Khong tim thay username: "<<username<<endl;
	}

	// Hàm hiển thị
	void ShowALL() {
		if(!head) {
			cout<<"Danh sach rong"<<endl;
			return;
		}
		Node *p = head;
		int index = 1;
		while(p) {
			cout<<"Nhan vien: "<<index<<" ";
			if(p->data) {
				cout<<*(p->data)<<endl;
			}
			p = p->next;
			index++;
		}
	}

	// Chuyển linked list sang vector để dễ sử dụng Merge Sort và Binary Search
	vector<Employee> toVector() const {
		vector<Employee> v;
		Node *p = head;
		while(p) {
			v.push_back(*(p->data));
			p = p->next;
		}
		return v;
	}
			
	// Hàm sắp xếp (Merge Sort)
	static void merge(vector<Employee> &v, int l, int m, int r) {
		vector<Employee> left(v.begin() + l, v.begin() + m + 1);
		vector<Employee> right(v.begin() + m + 1, v.begin() + r + 1);

		int i = 0;
		int j = 0;
		int k = l;
		while(i < (int) left.size() && j < (int) right.size()) {
			if(left[i].getUsername() < right[j].getUsername()) {
				v[k] = left[i];
				k++;
				i++;
			} else {
				v[k] = right[j];
				k++;
				j++;
			}
		}
		while(i < (int) left.size()) {
			v[k] = left[i];
				k++;
				i++;
		}
		while(j < (int) right.size()) {
			v[k] = right[j];
				k++;
				j++;
		}
	}
	static void mergeSort(vector<Employee> &v, int left, int right) {
		if(left >= right) {
			return;
		}
		int mid = (left + right) / 2;
		mergeSort(v, left, mid);
		mergeSort(v, mid + 1, right);
		merge(v, left, mid, right);
	}
			
	// Hàm tìm kiếm (Binary Search)
	static int binarySearch(vector<Employee> &v, string username) {
		int left = 0;
		int right = v.size() - 1;
		while(left <= right) {
			int mid = (left + right) / 2;
			if(v[mid].getUsername() == username) {
				return mid;
			} else if(v[mid].getUsername() < username) {
			left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return -1;
	}

	// In ra kết quả sau khi sắp xếp và tìm kiếm
	void SortAndSearch() {
		vector<Employee> v = toVector();
		if(v.empty()) {
			cout<<"Danh sach rong"<<endl;
			return;
		}
		mergeSort(v, 0, v.size() - 1);
		cout<<"--- Danh sach nhan vien da duoc sap xep ---"<<endl;
		for(auto &e : v) {
				cout<<e<<endl;
		}
		string username;
		cout<<"Nhap username can tim: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, username);
		int index = binarySearch(v, username);
		if(index != -1) {
			cout<<"Nhan vien có ma username "<<v[index].getUsername()<<" duoc tim thay o vi tri so "<<index + 1<<endl;
		} else {
			cout<<"Khong tim thay nhan vien co username "<<username<<" trong danh sach"<<endl;
		}
	}

	// Thay đổi cập nhật thông tin cho username
	void UpdateEmployee() {
		if(!head) {
			cout<<"Danh sach rong"<<endl;
			return;
		}
		cout<<"--- CAP THONG TIN NHAN VIEN ---"<<endl;
		cout<<"Nhap username can cap nhat"<<endl;
		string username;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
    	getline(cin, username);

		Node *p = head;
		while(p) {
			if(p->data->getUsername() == username) {
				cout<<"Tim thay nhan vien: "<<username<<endl;
				string name, address, phone, email;

				cout<<"Nhap ho ten moi (bo trong neu giu nguyen): ";
				getline(cin, name);
				name = standardizeNames(name);

				cout<<"Nhap dia chi moi (bo trong neu giu nguyen): ";
				getline(cin, address);
				cout<<"Nhap so dien thoai moi (bo trong neu giu nguyen): ";
				getline(cin, phone);
				cout<<"Nhap email moi (bo trong neu giu nguyen): ";
				getline(cin, email);

				// Cập nhật nếu có nhập
				if(!name.empty()) {
					p->data->setName(name); // username cần được giữ nguyen
				}
				if(!address.empty()) {
						p->data->setAddress(address);
				}
				if(!phone.empty()) {
					p->data->setPhonenumber(phone);
				}
				if(!email.empty()) {
					p->data->setEmail(email);
				}
				cout<<"Cap nhat thong tin cho nhan vien thanh cong"<<endl;
				return;
			}
				p = p->next; // Di chuyển cập nhật nhân viên khác
			}
			cout<<"Khong tim thay nhan vien co username:"<<username<<endl;
		}

	Employee *currentUser = nullptr;

	// Hàm đăng nhập cho Employee
	void LoginEm(){
		if (!head) {
    		cout<<"Danh sach nhan vien rong"<<endl;
    		return;
    	}
		string user, pass;
		cout<<"Vui long nhap username: ";
		cin>>user;
		cout<<"Vui long nhap mat khau: ";

		char ch;
		pass = "";
		while(true) {
			ch = _getch();
			if(ch == 13) { // Enter
				break;
			} else if(ch == 8) { // Backspeace
				if(!pass.empty()) {
					cout<<"\b \b";
					pass.pop_back();
				}
			} else {
				pass.push_back(ch);
				cout<<"*";
			}
		}
		cout<<endl;
		
		Node *p = head;
		while(p != nullptr) {
			if(p->data->getUsername() == user && p->data->getPassword() == pass) {
				cout<<"Dang nhap thanh cong"<<endl;
				cout<<"Xin chao, "<<p->data->getUsername()<<endl;
				currentUser = p->data;
				return;
			}
			p = p->next;
		}
		cout<<"Thong tin dang nhap khong chinh xac"<<endl;
	}

	// Hàm thông tin cho Employee
	void Information(){
		if (currentUser == nullptr) {
        	cout<<"Chua dang nhap!"<<endl;
        	return;
    	}
		cout<<"Thong tin ca nhan cua nhan vien"<<endl;
    	cout<<*currentUser<<endl;
	}

	// Hàm thay đổi mật khẩu
	void ChangePassword(){
		if(!head) {
			cout<<"Danh sach rong"<<endl;
			return;
		}
		string user, oldPass, newPass;
		cout<<"Nhap username: ";
		cin>>user;
		cout<<"Nhap mat khau hien tai: ";

		char ch;
		oldPass = "";
		while(true) {
			ch = _getch();
			if(ch == 13) { // Enter
					break;
			} else if(ch == 8) { // Backspeace
				if(!oldPass.empty()) {
					cout<<"\b \b";
					oldPass.pop_back();
				}
			} else {
				oldPass.push_back(ch);
				cout<<"*";
			}
		}
		cout<<endl;
		Node *p = head;
		while(p != nullptr) {
			if(p->data->getUsername() == user && p->data->getPassword() == oldPass) {
				cout<<"Nhap mat khau moi: ";
				newPass = "";
				while(true) {
					ch = _getch();
					if(ch == 13) { // Enter
						break;
					} else if(ch == 8) { // Backspeace
						if(!newPass.empty()) {
							cout<<"\b \b";
							newPass.pop_back();
						}
					} else {
						newPass.push_back(ch);
						cout<<"*";
					}
				}
				cout<<endl;
				p->data->setPassword(newPass);
				cout<<"Doi mat khau thanh cong"<<endl;
				return;
			}	
			p = p->next;
		}
		cout<<"Username hoac mat khau khong chinh xac"<<endl;
	}

	 queue<LeaveRequest> leaveQueue;
	// Hàm duyệt đơn xin nghỉ
	void SubmitLeaveRequest() {
		if(currentUser == nullptr) {
            cout<<"Chua dang nhap"<<endl;
            return;
        }
		string reason;
        int days;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Nhap ly do xin nghi: ";
        getline(cin, reason);
        cout<<"Nhap so ngay nghi: ";
        cin >> days;

        leaveQueue.push(LeaveRequest(currentUser->getUsername(), reason, days));
        cout<<"Da gui don xin nghi."<<endl;
	}
};

// Lớp cho admin
class Administrator : public User{
	private: 
	// Danh sach cac admin duoc cap tai khoa
	vector<pair<string, string>> adminAccounts = {
		{"Phong", "30052006"},
		{"Hao", "10032006"},
		{"Quan", "24032005"},
		{"Tinh", "22072006"}
	};
	public: 

	// construct , coppy construct , destruct
	Administrator(
		string _Username= "user111",
		string _Password= "1111111111"
	):User(_Username,_Password){
		//
	}
	Administrator(const Administrator &k):User(k){
		//
	}
	~Administrator(){}

	bool LoginAd() {
		int attempt = 0;
		while(attempt < 3) {
			string user, pass;
			cout<<"=== ADMIN LOGIN ==="<<endl;
			cout<<"Vui long nhap username cua ban: ";
			getline(cin, user);
			cout<<"Vui long nhap mat khau cua ban: ";
			char ch;
			pass = "";

			while (true) {
				ch = _getch(); // Lấy kí tự mà không in ra màn hình
				if(ch == 13) { // Enter là kết thúc (ASCII 13)
					break;
				} else if(ch == 8) { // Backspace (ASCII 8)
					if(!pass.empty()) {
						pass.pop_back();
						cout<<"\b \b"; // Xóa 1 ký tự trên màn hình
					}
				} else {
					pass.push_back(ch);
					cout<<'*';
				}
			}
			cout<<endl;

			// Kiểm tra đăng nhập
			for(auto &acc : adminAccounts) {
				if(user == acc.first && pass == acc.second) {
					cout<<"Dang nhap thanh cong, xin chao admin "<<user<<endl;
					Username = user; // Ghi lại admin nào vì chỉ duy nhất một admin đăng nhập trong thời gian đó
					Password = pass; 
					return true;
				}
			}
			attempt++;
			cout<<"Ban da sai thong tin lan thu: "<<attempt<<endl;
			cout<<"Nhap khong chinh xac qua 3 lan se bi khoa"<<endl;
			if(attempt < 3) {
				cout<<"Khong dung, hay thu lai"<<endl;
			}
		}
		cout<<"Ban da bi khoa vi nhap khong chinh xac qua 3 lan"<<endl;
		return false;
	}
	void addEmployee(EmployeeList &list){
    	string username, name, address, phone, email;

		cout<<"--- THEM NHAN VIEN MOI ---"<<endl;
		cout<<"Nhap username: ";
		getline(cin, username);

		cout<<"Nhap ho ten: ";
		getline(cin, name);
		name = standardizeNames(name);

		cout<<"Nhap dia chi: ";
		getline(cin, address);

		cout<<"Nhap so dien thoai: ";
		getline(cin, phone);

		cout<<"Nhap email: ";
		getline(cin, email);

		// Tạo mật khẩu cho nhân viên mặc định là 11111
		Employee *e = new Employee(username, "11111", name, address, phone, email);

		list.AddEmployee(e); // Thêm vào danh sách
	}
	void deleteEmployee(EmployeeList &list){
		cout<<"--- XOA NHAN VIEN ---"<<endl;
		list.DeleteEmployee();

	}
	void Search(EmployeeList &list){
		cout<<"-- TIM KIEM THONG TIN NHAN VIEN"<<endl;
		list.SortAndSearch();
	}
	void Update(EmployeeList &list){
		list.UpdateEmployee();
	}
	void Showall(EmployeeList &list){
		if (!list.toVector().size()) {
        	cout << "Danh sach nhan vien rong." << endl;
        	return;
    	}
		vector<Employee> v = list.toVector();
		int index = 1;
		for(auto &e : v) {
			cout<<"Nhan vien so: "<<index<<endl;
			cout<<"Ten "<<e.getName()<<endl;
			cout<<"Username "<<e.getUsername()<<endl;
			cout<<"SĐT "<<e.getPhonenumber()<<endl;
			cout<<"Email "<<e.getEmail()<<endl;
			cout<<"Dia chi "<<e.getAddress()<<endl;
			cout<<"Mat khau "<<e.getPassword()<<endl;
			index++;
		}
	}

	// Hàm quản lý và duyệt đơn xin nghỉ
	void ProcessLeaveRequests(EmployeeList &list) {
		if(list.leaveQueue.empty()) {
            cout<<"Khong co don xin nghi nao"<<endl;
            return;
        }
		cout<<"--- DUYET DON XIN NGHI ---"<<endl;
		while(!list.leaveQueue.empty()) {
			LeaveRequest &req = list.leaveQueue.front();
			cout<<"Nhan vien: "<<req.username<<", so ngay: "<<req.days<<", ly do: "<<req.reason<<endl;

			char choice;
			cout<<"Quyet dinh duyet (Y hoac N): ";
			cin>>choice;
			if(choice == 'Y' || choice == 'y') {
				cout<<"Da chap nhan don xin nghi cua "<<req.username<<endl;
			} else {
				cout<<"Tu choi don xin nghi cua "<<req.username<<endl;
			}
			list.leaveQueue.pop();
		}
	}
};


int main() {
    EmployeeList list;        
    Administrator admin;      
    int roleChoice;   

    cout<<"==== XIN CHAO BAN DEN HE THONG QUAN LY NHAN SU ===="<<endl;
    cout<<"1. Ban la ADMIN"<<endl;
    cout<<"2. Ban la NHAN VIEN"<<endl;
    cout<<"Nhap lua chon: ";
    cin>>roleChoice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (roleChoice == 1) {
        // Đăng nhập Admin
        if (admin.LoginAd()) {
            int choice = 0;
            do {
                cout<<"\n=== MENU ADMIN ==="<<endl;
                cout<<"1. Them nhan vien moi"<<endl;
                cout<<"2. Xoa nhan vien"<<endl;
                cout<<"3. Cap nhat thong tin nhan vien"<<endl;
                cout<<"4. Tim kiem nhan vien"<<endl;
                cout<<"5. Hien thi danh sach nhan vien"<<endl;
				cout<<"6. Duyen don xin nghi cua nhan vien"<<endl;
                cout<<"7. Thoat"<<endl;
                cout<<"Nhap lua chon: ";
				
				cin>>choice;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (choice) {
                    case 1:
                        admin.addEmployee(list);
                        break;
                    case 2:
                        admin.deleteEmployee(list);
                        break;
                    case 3:
                        admin.Update(list);
                        break;
                    case 4:
                        admin.Search(list);
                        break;
                    case 5:
                        admin.Showall(list);
                        break;
					case 6:
						admin.ProcessLeaveRequests(list);
            			break;
                    case 7:
                        cout<<"Dang xuat...\n";
                        break;
                    default:
                        cout<<"Lua chon khong hop le"<<endl;
                }
            } while (choice != 7);
        }
    } 
    else if (roleChoice == 2) {
        // Đăng nhập nhân viên
        list.LoginEm();
        int choice;
        do {
            cout<<"\n=== MENU NHAN VIEN ==="<<endl;
            cout<<"1. Xem thong tin ca nhan"<<endl;
            cout<<"2. Doi mat khau"<<endl;
			cout<<"3. Lam don xin nghi"<<endl;
            cout<<"4. Thoat"<<endl;
            cout<<"Nhap lua chon: ";
            cin>>choice;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice) {
                case 1:
                    list.Information();
                    break;
                case 2:
                    list.ChangePassword();
                    break;
				case 3:
					list.SubmitLeaveRequest();
            		break;
                case 4:
                    cout<<"Dang xuat..."<<endl;
                    break;
                default:
                    cout<<"Lua chon khong hop le"<<endl;
            }
        } while (choice != 4);
    } 
    else {
        cout<<"Lua chon khong hop le. Ket thuc chuong trinh"<<endl;
    }

return 0;
}