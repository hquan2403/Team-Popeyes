#include <bits/stdc++.h>
using namespace std;
bool snt(int n){
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
int main() {

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(snt(a[i])) cout<<a[i]<<" ";
        else cout<<-1<<" ";
    }
    cout<<"Hello World";
    //dwadwdawdwad
    return 0;
    //dwnaidnwioandiwnaidniownaidnwaiod
} 



