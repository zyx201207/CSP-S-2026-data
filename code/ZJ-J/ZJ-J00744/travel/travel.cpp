#include<bits/stdc++.h>
using namespace std;
int a,b;
string s,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>t;
	if(a==b) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s[0]==t[0]&&s[1]==t[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(abs(s[2]-t[2])<=2&&(min(s[2],t[2])>'C'||max(s[2],t[2])<'D')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s[2]-t[2])==1) cout<<1;
	else cout<<0;
	return 0;
} 
