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
		string _Password= "123456789" // sửa lại mật khẩu cho đúng định dạng 111111
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
		cout<<"Enter your Username: "; // sửa lại tiếng việt không dấu viết liền
		getline(is,a.Username);
		cout<<"Enter your Password: ";
		getline(is,a.Password);
		return is;

	}
	friend ostream& operator << (ostream& os, User &a){
		os<<"Your Username is: "<<a.getUsername()<<endl;
		os<<"Your Password is: "<<a.getPassword()<<endl;
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
		string _Password= "123456789"
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
		string _Password= "123456789",
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
		cout<<"Enter your Name: ";
		getline(is,a.Name);
		cout<<"Enter your Address: ";
		getline(is,a.Address);
		cout<<"Enter your Phone Number: ";
		getline(is,a.Phonenumber);
		cout<<"Enter your Email: ";
		getline(is,a.Email);
		return is;
	}
	friend ostream& operator << (ostream& os, Employee &a){
		a.User::Out();
		os<<"Your Name is: "<<a.getName()<<endl;
		os<<"Your Address is: "<<a.getAddress()<<endl;
		os<<"Your Phone Number is: "<<a.getPhonenumber()<<endl;
		os<<"Your Email is: "<<a.getEmail()<<endl;
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
