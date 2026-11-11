#include<bits/stdc++.h>
#define int long long 
using namespace std;
char c,d;
string a,b,s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<1;
			c=s1[2];d=s2[2];
			if(c<='C'&&d<='C'||c>'C'&&d>'C'){
				cout<<1;
				if(abs(c-d)==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}