#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
