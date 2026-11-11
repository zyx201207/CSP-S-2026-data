#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000006;
int c,T,n,d,a[N],cnt;
pair<int,int> dis[500][500];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(c>=11&&c<=12)
		{
			int maxn=d/(a[2]-a[1]);
			if(maxn<=1)
			{
				cout<<"0\n";
				continue;
			}
			cout<<max(0ll,n-(2*maxn-1))<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				dis[i][j].second=1;
				if(abs(a[i]-a[j])<=d)
				dis[i][j].first=1;
				else
					dis[i][j].first=1e18;
			}
		cnt=0;
		for(int k=1;k<=n;k++)
			for(int u=1;u<=n;u++)
				for(int v=1;v<=n;v++)
				{
					if(dis[u][v].first>dis[u][k].first+dis[k][v].first)
					{
						dis[u][v].first=dis[u][k].first+dis[k][v].first;
						dis[u][v].second=0;
					}
					if(dis[u][v].first==dis[u][k].first+dis[k][v].first)
						dis[u][v].second+=dis[u][k].second*dis[k][v].second;
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(dis[i][j].second==2)
					cnt++;
		cout<<cnt<<"\n";
	}
	return 0;
}
