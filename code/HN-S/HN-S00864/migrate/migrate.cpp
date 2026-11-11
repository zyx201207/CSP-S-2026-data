#include<bits/stdc++.h>
using namespace std;
#define int long long
//void dij(int p)
//{
//	priority_queue<int>Q;
//	Q.push(p);
//	
//	for(int i=1;i<=n;i++)
//	{
//		
//	}
//	while(Q.size())
//	{
//		int x=Q.top();
//		Q.pop();
//		if(vis[x])
//		{
//			continue;
//		}
//		for(int i=1;i<=n;i++)
//		{
//			for()
//		}
//	}
//}
int ans;
int c,d,q;
int dis[2000002],pat,tot,T,a[2000002],n,m;
void dfs(int x,int len,int e)
{
	if(x==e)
	{
		if(dis[e]>len)
		{
			dis[e]=len;
			pat=1;
		}
		else if(dis[e]==len)
		{
			pat++;
		}
		return;
	}
	if(dis[x]<len)
	{
		dis[x]=len;
	}
	for(int i=x+1;i<=e;i++)
	{
//		cout<<a[x]+d<<' '<<a[i]<<'|';
		if(a[x]+d>=a[i])
		{
			dfs(i,len+1,e);
		}
		else
		{
			return;
		}
	}
	return;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==11||c==12)
	{
		while(T--)
		{
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			if(n==1)
			{
				cout<<"0\n";
				continue;
			}
			int di=a[2]-a[1];
			if(d<2*di)
			{
				cout<<"0\n";
				continue;
			}
			int jumpnum=d/di;
			int duannum=n-2*jumpnum+1;
			if(duannum<0)
			{
				cout<<"0\n";
			}
			else
			{
				cout<<duannum<<'\n';
			}	
		}
		return 0;
	}
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
//				if(i==j)continue;
				int l=min(i,j),r=max(i,j);
				dis[r]=1e9;
				pat=0;
				dfs(l,0,r);
				if(pat==2)
				{
					ans++;
				}
//				cout<<i<<' '<<j<<' '<<pat<<' '<<dis[j]<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
}
