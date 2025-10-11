#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e6;

// thuật toán: sort , search , delete.
// List Employee_Formation , add.

class User{
private:
	string Username;
	string Password;
public:
	// construct , coppy construct , destruct
	User(
		const string _Username= "user111",
		const string _Password= "111111111" // sửa lại mật khẩu cho đúng định dạng 111111
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

class Administrator : public User{
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

	void LoginAd(){}
	void Add(){}
	void Delete(){}
	void Search(){}
	void Update(){}
	void Showall(){}
};

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
			cout<<"Da them nhan vien thanh cong"<<endl;
		}

		// Hàm xóa nhân viên
		void DeleteEmployee() {

		}

		// Hàm hiển thị
		void ShowALL() {

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
			getline(cin, username);
			int index = binarySearch(v, username);
			if(index != -1) {
				cout<<"Nhan vien có ma username: "<<v[index].getUsername()<<" duoc tim thay o vi tri so "<<index + 1<<endl;
			} else {
				cout<<"Khong tim thay nhan vien co username: "<<username<<" trong danh sach"<<endl;
			}
		}
};
	void LoginEm(){}
	void Information(){}
	void ChangePassword(){}
int main() {printf("");
	EmployeeList list;

	cout<<"Nhap so luong nhan vien: "<<endl;
	int n;
	cin>>n;
	// Consume the newline character left in the input buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');


	for(int i = 0; i < n; i++) {
		cout<<"--- Nhap thong tin nhan vien: "<<i + 1<<endl;
		Employee *e = new Employee();
		cin>> *e;
		list.AddEmployee(e);
	}
	
	// Gọi tính năng sắp xếp tìm kiếm
	list.SortAndSearch();
return 0;
}