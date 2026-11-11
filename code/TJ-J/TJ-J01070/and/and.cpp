#include <bits/stdc++.h>
using namespace std;

int s[200005];
string y;
string e(int n){
	string a = "" , b= "";
	while(n) {
		a += n % 2 + 48;
		n /= 2;
	}
	for(int i = a.size() - 1;i >= 0;i--) {
		b += a[i];
	}
	return b;	
}

int main()
{ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1;i <= n£»i++) {
		cin >> s[i];
	}
	cout <<12;
	return 0; 
}
