#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f[]={1,2,3,4,0,5};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0] and b[1]==d[1])cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if((f[b[2]-'A']<=3 and f[d[2]-'A']<=3) or 
	   (f[b[2]-'A']>=4 and f[d[2]-'A']>=4))cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(f[b[2]-'A']-f[d[2]-'A'])==1)cout<<1;
	else cout<<0;
	return 0;
}
