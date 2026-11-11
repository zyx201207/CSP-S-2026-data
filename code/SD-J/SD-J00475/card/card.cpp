#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=3e5+10;
int n,m,a[N],b[N],cnt[M];
vector<int>last[M];
bool vis[N],f=1;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i!=1&&a[i]>a[i-1])
		{
			f=0;
		}
	}
	if(f)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<i<<" ";
		}
		return 0;
	}
	for(int k=1;k<=n;k++)
	{
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;i++)
		{
			last[i].push_back(0);
		}
		for(int i=k;i<=n;i++)
		{
			int x=last[a[i]].size();
			if(x!=1)
			{
				for(int j=last[a[i]][x-1];j<i;j++)
				{
					if(vis[j]==0)
					{
						last[a[j]].pop_back();
						vis[j]=1;
					}
				}
			}
			last[a[i]].push_back(i);
		}
		for(int i=1;i<=m;i++)
		{
			if(last[i].size()!=1)
			{
				cnt[i]++;
			}
			last[i].clear();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}

