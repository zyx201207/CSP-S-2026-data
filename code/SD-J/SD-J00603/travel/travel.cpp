#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int a,b;
    string s,c;
    cin>>a>>s>>b>>c;
    int k=(s[0]-'0')*10+s[1]-'0';
    int p=(c[0]-'0')*10+c[1]-'0';
    if(a==b){
    	cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(k==p){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(c[2]=='A'||c[2]=='B'||c[2]=='C'))||((s[2]=='D'||s[2]=='F')&&(c[2]=='D'||c[2]=='F'))){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if((s[2]=='A'&&c[2]=='B')||(s[2]=='B'&&c[2]=='A')||(s[2]=='B'&&c[2]=='C')||(s[2]=='C'&&c[2]=='B')||(s[2]=='D'&&c[2]=='F')||(s[2]=='F'&&c[2]=='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
