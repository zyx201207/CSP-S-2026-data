#include<bits/stdc++.h>
//#define int long long
using namespace std;
int fl;
string a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>a>>b>>c>>d;
	if(a!=c) cout<<0,fl=0;
	else cout<<1,fl=1;
	if(b.substr(0,2)==d.substr(0,2)&&fl) cout<<1,fl=1;
	else cout<<0,fl=0;
	if((b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C')&&fl) cout<<1,fl=1;
	else cout<<0,fl=0;
	if(abs(b[2]-d[2])==1&&fl) cout<<1;
	else cout<<0; 
	return 0;
}