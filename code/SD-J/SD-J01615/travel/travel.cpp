#include<bits/stdc++.h>
using namespace std;
string rs,rc,xs,xc;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>rs>>rc>>xs>>xc;
	if(rs==xs) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(rc[0]==xc[0]&&rc[1]==xc[1]) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if((rc[2]<='C'&&xc[2]<='C')||(rc[2]>'C'&&xc[2]>'C')) cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if((rc[2]+1==xc[2]||rc[2]-1==xc[2])) cout<<1;
	else cout<<0;
	return 0;
}
