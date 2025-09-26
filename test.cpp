#include<bits/stdc++.h>
using namespace std;      
void hoa (string s) {
    string b;
    for(char c : s) {
        c= toupper(c);
        b += c;
    }
    cout<<b;
}

int main() {
    cout<<"Hello, World!"<<endl;
    cout<<"Hay nhap so: ";
    int a;
    cin >> a;
    cin.ignore();
    cout<<"hay nhap ten: ";
    string name;
    getline(cin, name);
    hoa(name);
    cout<<endl;
    cout<<a+3<<endl;
    ;
    return 0;
}