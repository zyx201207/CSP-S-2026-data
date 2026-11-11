#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	string p1=b.substr(0,2),p2=d.substr(0,2);
	if(p1==p2) cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	int l,r;
	if(b[2]=='A'||(b[2]=='B'||b[2]=='C')) l=1;
	else l=2;
	if(d[2]=='A'||(d[2]=='B'||d[2]=='C')) r=1;
	else r=2;
	if(l==r) cout<<"1";
	else
	{
		cout<<"00";
		return 0;
	}
	if(l==2) cout<<"1";
	else
	{
		int now=b[2]-'A',now2=d[2]-'A';
		if(abs(now-now2)==1) cout<<"1";
		else cout<<"0";
	}
	return 0;
}