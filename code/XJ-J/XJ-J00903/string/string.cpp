#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,x;
	char c;
	string s;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a;
		cin >> c;
		for(int j=1;j<=a;j++){
			s += c;
		}
	}
	long long len=s.size();
	x=len/2;
	for(int i = 0;i<len/2;i++){
		if(s[i]==s[len-i-1]){
			x--;
		}
	}
	cout << x;
	return 0;
}