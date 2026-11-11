#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else cout<<0;
	if(a==c&&(b[0]+b[1])==(d[0]+d[1])) cout<<1;
	else cout<<0;
	short e=b[2]=='D'||b[2]=='F'?1:0,f=d[2]=='D'||d[2]=='F'?1:0;
	if(a==c&&(b[0]+b[1])==(d[0]+d[1])&&e==f) cout<<1;
	else cout<<0;
	if(a==c&&(b[0]+b[1])==(d[0]+d[1])&&e==f&&((char(b[2]+1)!='D'&&char(b[2]+1)==d[2])||(char(b[2]-1)!='C'&&char(b[2]-1)==d[2]))) cout<<1;
	else cout<<0;
	return 0;
}
