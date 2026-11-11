#include<bits/stdc++.h>
using namespace std;

string s;

int spell(long long x, string a){
	for(long long i = 0;i < x;i++){
		s += a;
	}
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n = 0;
	cin >> n;
	for(long long i = 0; i < n;i++){
		long long x;
		string a;
		cin >> x >> a;
		spell(x, a);
	}
	long long sum = 0;
	long long n_ = n/2;
	for(long long i = 0;i <= n_;i++){
		if(s[i] != s[n-i])sum++;
	}
	cout << sum;
	return 0;
}