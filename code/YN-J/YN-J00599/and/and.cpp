#include <bits/stdc++.h>
using namespace std;
string s;
int m=0;

int r(int n){
	while(n>=0){
		m=n;
		n/=2;
		m%=2;
	}
	return m;
}

int main() {
	freopen(and.in, "r", std.in)
	freopen(and.out, "w", std.out)
	int n;	
	cin >> n;
	cout<<r(n);
}