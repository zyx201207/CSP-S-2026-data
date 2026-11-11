#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,a[1000009],fa[1000009];
vector<int> e[1000009];
pair<int,int> dis[1000009];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t>>t;
	while(t--)
	{
		for(int i=0;i<=n+1;i++)
		{
			fa[i]=0,e[i].clear();
		}
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int tmp=n;
		for(int i=n;i>=1;i--)
		{
			while(a[tmp]-a[i]>m)
			{
				tmp--;
			}
			if(tmp>i)
			{
				fa[i]=tmp; 
			}
		}
		int ans=0;
		for(int i=n;i>=1;i--)
		{
			for(int j=i;j<=n;j++)
			{
				dis[j]={0x3f3f3f3f,0};
			}
			dis[i]={0,1};
			for(int j=i;j<=n;j++)
			{
				if(dis[j].first>=0x3f3f3f3f)
				{
					break;
				} 
				for(int k=j+1;k<=fa[j];k++)
				{
					if(dis[k].first>dis[j].first+1)
					{
						dis[k].first=dis[j].first+1,dis[k].second=dis[j].second;
					}
					else if(dis[k].first==dis[j].first+1)
					{
						dis[k].second+=dis[j].second;
					}
				}
				if(dis[j].second==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
5 3
-3 0 2 3 4
*/
