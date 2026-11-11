#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("trevel.in","r",stdin);
	freopen("trevel.out","w",stdout);
	long long  a,b;
	string s,d;
	cin>>a>>s>>b>>d;
	if(a==b) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s[0]==d[0] and s[1]==d[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((s[2]-'A'<=2 and d[2]-'A'<=2) or (s[2]-'A'>2 and d[2]-'A'>2)) cout<<1;
	else{
		cout<<"00";
		return 0;
	}if(s[2]-d[2]==1 or d[2]-s[2]==1) cout<<1;
	else cout<<0;
	return 0;
} 
