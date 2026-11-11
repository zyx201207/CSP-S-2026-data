#include<bits/stdc++.h>
using namespace std;
int a,b,l=0,ans=0;
char c;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;++i){
		cin>>b>>c;
		l+=b;
		for(int j=1;j<=b;++j)
			s+=c;
	}
	for(int i=0;i<l/2;++i)
		if(s[i]!=s[l-1-i])
			ans++;
	cout<<ans;
	return 0;
}