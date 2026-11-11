#include<bits/stdc++.h>
#define int long long
using namespace std;
string s[10];
int c[10],l[10];
char h[10];
bool f[10];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	h[1]=s[1][2];
	h[2]=s[2][2];
	l[1]=(s[1][0]-'0')*10+(s[1][1]-'0');
	l[2]=(s[2][0]-'0')*10+(s[2][1]-'0');
	f[1]=(c[1]==c[2]);
	f[2]=(f[1]&(l[1]==l[2]));
	f[3]=(f[2]&((h[1]<='C'&&h[2]<='C')||(h[1]>'C'&&h[2]>'C')));
	f[4]=(f[3]&(abs(h[1]-h[2])==1));
	cout<<f[1]<<f[2]<<f[3]<<f[4];
	return 0;
}

