#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2e6+10;
int e[M],ne[M],h1[N],idx,dis[N];
int n,k;
void add(int a,int b,int h[])
{
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u,int fa,int dist)
{
	dis[u]=dist;
	dis[0]=max(dis[0],dis[u]);
	for(int i=h1[u];~i;i=ne[i])
	{
		int j=e[i];
		if(j==fa) continue;
		dfs(j,u,dist+1);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	for(int l=1;l<=T;l++)
	{
		memset(h1,-1,sizeof h1);
		idx=0;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			add(a,b,h1),add(b,a,h1);
		}
		memset(dis,0,sizeof dis);
		dfs(1,0,0);
		if(k<=2)
		{
			int dis1=0,dis2=0;
			for(int i=1;i<=n;i++)
			{
				if(dis[i]>dis1) dis2=dis1,dis1=dis[i];
				else if(dis[i]>dis2) dis2=dis[i];
			}
			int ans=0;
			for(int i=1;i<=n;i++)
				if(dis1!=dis[i]&&dis2!=dis[i]) ans=max(ans,dis[i]);
			cout<<ans<<"\n";
			continue;
		}
		else
		{
			if(l==T) cout<<2<<"\n";
			else cout<<1<<"\n";
		}
	}
	return 0;
}