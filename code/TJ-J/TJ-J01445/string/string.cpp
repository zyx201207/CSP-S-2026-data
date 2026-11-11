#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >>n;
	string s="";
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin >>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	string ss=s;
	reverse(ss.begin(),ss.end());
	int ans=0;
	for(int i=0;i<=int(s.size());i++){
		if(s[i]!=ss[i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
