#include<iostream>
#define int long long
using namespace std;
int a,x;
string b,y;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(b[2]=='D'||b[2]=='F') b[2]++;
	if(y[2]=='D'||y[2]=='F') y[2]++;
	if(a==x)
	{
		cout<<1;
		if(b[0]==y[0]&&b[1]==y[1])
		{
			cout<<1;
			if(abs(b[2]-y[2])<=1||b[2]+y[2]=='A'+'C')
			{
				cout<<1;
				if(abs(b[2]-y[2])<=1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
