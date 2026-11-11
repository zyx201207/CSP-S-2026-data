#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
const int N=2e6+10;
int x[N],n,d;
int l[N],r[N],cnt;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cnt=0;
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n-2;i++)
		{
			if(i!=n-2)
			{
				if(x[i]+d>=x[i+2]&&x[i]+d<x[i+3])
				{
					cnt++;
					l[cnt]=i;
					r[cnt]=i+2;
				}
			}
			else
			{
				if(x[i]+d>=x[i+2])
				{
					cnt++;
					l[cnt]=i;
					r[cnt]=i+2;
				}
			}
		}
//		cout<<cnt<<' ';
		if(cnt<2)cout<<0<<'\n';
		else cout<<l[cnt-1]<<'\n';
	}
}
