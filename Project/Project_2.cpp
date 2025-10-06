#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e6;

class User{
	private:
	string Username;
	string Password;
	public:
	// construct , coppy construct , destruct
	User(
		string _Username= "user111",
		string _Password= "111111111" // sửa lại mật khẩu cho đúng định dạng 111111
	){
		Username = _Username;
		Password = _Password;
	}
	User(const User &k){
		Username = k.Username;
		Password = k.Password;
	}
	~User(){}

	//get
	string getUsername(){ return Username;}
	string getPassword(){ return Password;}

	//set
	void setUsername(string a= " "){
		Username = a;
	}
	void setPassword(string a = " "){
		Password = a;
	}

	//>>, <<
	friend istream& operator >> (istream& is, User &a){
		cout<<"Hay nhap ten tai khoan: ";
		getline(is,a.Username);
		cout<<"Hay nhap mat khau cua ban: ";
		getline(is,a.Password);
		return is;

	}
	friend ostream& operator << (ostream& os, User &a){
		os<<"Ten tai khoan cua ban la: "<<a.getUsername()<<endl;
		os<<"Mat khau cua ban la: "<<a.getPassword()<<endl;
		return os;
	}

	virtual void Type(){
		cin>>*this;
	}
	virtual void Out(){
		cout<<*this;
	}

};
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
		string _Username= "user111",
		string _Password= "111111111",
		string _Name = "Nguyen Van A",
		string _Address= "111 Tran Hung Dao Quan 1",
		string _Phonenumber ="1234567890",
		string _Email ="NguyenVanA@gmail.com"
	):User(_Username,_Password){
		string Name = _Name;
		string Address = _Address;
		string Phonenumber = _Phonenumber;
		string Email = _Email;
	}
	Employee(const Employee &k):User(k){
		Name =k.Name;
		Address = k.Address;
		Phonenumber = k.Phonenumber;
		Email = k.Email;
	}
	
	~Employee(){}

	//get
	string getName (){ return Name;}
	string getAddress(){ return Address;}
	string getPhonenumber(){ return Phonenumber;}
	string getEmail(){ return Email;}

	//set
	void setName(string a= " "){
		Name = a;
	}
	void setAddress(string a = " "){
		Address = a;
	}
	void setPhonenumber(string a = " "){
		Phonenumber = a;
	}
	void setEmail(string a = " "){
		Email = a;
	}

	//>>, <<
	friend istream& operator >> (istream& is, Employee &a){
		a.User::Type();
		cout<<"Hay nhap ho ten cua ban: ";
		getline(is,a.Name);
		cout<<"Hay nhap dia chi cua ban: ";
		getline(is,a.Address);
		cout<<"Hay nhap so dien thoai cua ban: ";
		getline(is,a.Phonenumber);
		cout<<"Hay nhap email cua ban: ";
		getline(is,a.Email);
		return is;
	}
	friend ostream& operator << (ostream& os, Employee &a){
		a.User::Out();
		os<<"Ho ten cua ban la: "<<a.getName()<<endl;
		os<<"Dia chi cua ban la: "<<a.getAddress()<<endl;
		os<<"So dien thoai cua ban la: "<<a.getPhonenumber()<<endl;
		os<<"Email cua ban la: "<<a.getEmail()<<endl;
		return os;
	}
	void LoginEm(){}
	void Information(){}
	void ChangePassword(){}
};
int main() {
	Administrator a;
	cin>>a;
	cout<<a;
}
