#include<bits/stdc++.h>
#define int long long
using namespace std;
int s[5];
string a,b,c,d;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]) s[1]=1;
	if(s[1]&&b[0]==d[0]&&b[1]==d[1]) s[2]=1;
	if(s[2]&&(b[2]>='D'&&d[2]>='D'||b[2]<='C'&&d[2]<='C')) s[3]=1;
	if(s[3]&&abs(d[2]-b[2])==1) s[4]=1;
	for(int i=1;i<=4;i++) cout<<s[i];
}
