#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else cout<<0;
	if(a==c && b.substr(0,2)==d.substr(0,2)) cout<<1;
	else cout<<0;
	if(a==c && b.substr(0,2)==d.substr(0,2))
	{
		if(b[2]>='A' && b[2]<='C' && d[2]>='A' && d[2]<='C') cout<<1;
		else if(b[2]>='D' && b[2]<='F' && d[2]>='D' && d[2]<='F') cout<<1;
		else cout<<0;
	}
	else cout<<0;
	if(a==c && b.substr(0,2)==d.substr(0,2) && ((b[2]>='A' && b[2]<='C' && d[2]>='A' && d[2]<='C')||(b[2]>='D' && b[2]<='F' && d[2]>='D' && d[2]<='F')))
	{
		if(b[2]>='A' && b[2]<='C' && (b[2]==d[2]+1 || d[2]==b[2]+1)) cout<<1;
		else if((b[2]=='D' && d[2]=='F') || (b[2]=='F' && d[2]=='D')) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	// 8:46 AC
	// good
}
