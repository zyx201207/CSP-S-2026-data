#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
int dif(string s){
	int len=s.size(), sum=0;
	for(int i=0; i<len/2; i++){
		if(s[i]!=s[len-i-1]){
			sum++;
		}
	}
	return sum;
}
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++){
		int x;
		char c;
		cin >> x >> c;
		for(int j=1; j<=x; j++){
			s+=c;
		}
	}
	cout << dif(s);
	return 0;
}
