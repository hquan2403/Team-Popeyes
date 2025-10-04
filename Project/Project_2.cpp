#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e6;

// Đếm nguyên tố từ 0 đến 25
bool nt(int n) {
	if(n < 2) {
		return false;
	}
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++) {
		if(nt(i)) {
			cout<<i<<" ";
		}
	}
	cout<<endl;
	cout<<"dwadwa";
}
