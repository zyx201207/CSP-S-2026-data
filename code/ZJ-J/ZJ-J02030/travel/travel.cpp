#include<bits/stdc++.h>
using namespace std;
char a[5],b[5],c[5],d[5];
int r,x,rp,xp,rs,xs;
int toint(char f[5])
{
	int ans=0;
	if(f[0]=='1') {
		ans+=10;
	}
	ans=ans+(f[1]-'0');
	return ans;
}
int psame(char f[5])
{
	if(f[2]=='A' || f[2]=='B' || f[2]=='C') return 2;
	else return 1;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	r=toint(a);
	x=toint(c);
	if(r!=x) {
		cout<<"0000";
		return 0;
	} else cout<<1;
	rp=toint(b);
	xp=toint(d);
	if(rp!=xp) {
		cout<<"000";
		return 0;
	} else cout<<"1";
	rs=psame(b);
	xs=psame(d);
	if(rs!=xs) {
		cout<<"00";
		return 0;
	} else cout<<1;
	if((b[2]=='A' && d[2]=='C') || (b[2]=='C' && d[2]=='A')) {
		cout<<0;
		return 0;
	} else cout<<"1";
	return 0;
}
//rp++
