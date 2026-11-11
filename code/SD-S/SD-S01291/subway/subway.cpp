#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+3;
int c,n,m,d,q,ans;
int cs[N],k[N],vis[N],dis[N]; 
vector<int> xl[N];
struct hhj{
	int zt,tm;
};
struct jc{
	int zz,yx;
}qs[N];
vector<hhj> a[503];
void di(int x,int y)
{
	int cnt=0,cur=0; 
	for(int i=1;i<=m;i++)
		dis[i]=LLONG_MAX;
	jc f={x,0};
	dis[x]=0;
	qs[++cnt]=f;
	while(cnt>0)
	{
		jc u=qs[cnt];
		int num=cnt;
		for(int i=1;i<cnt;i++)
		{
			if(qs[i].yx<u.yx)
			{
				u=qs[i];
				num=i;
			}
		}
		for(int i=num;i<cnt;i++)
			qs[i]=qs[i+1];
		cnt--;
		int h=u.zz,t=u.yx;
		if(vis[h])	continue;
		vis[h]=1;
		for(int i:xl[h])
		{
			for(auto v:a[i])
			{
				if(v.zt==h)
				{
					cur=v.tm;
					break;
				}
			}
			for(auto v:a[i])
			{
				if(v.zt==h)	continue;
				if(dis[v.zt]>dis[h]+v.tm+cur)
				{
					dis[v.zt]=dis[h]+v.tm+cur;
					f={v.zt,dis[v.zt]};
					qs[++cnt]=f;
				}
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>cs[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int u,v;
			cin>>u>>v;
			a[i].push_back({u,v});
			xl[u].push_back(i);
		}
	}
	while(q--)
	{
		for(int i=1;i<=m;i++)
			vis[i]=0;
		ans=LLONG_MAX;
		int x,y;
		cin>>x>>y;
		di(x,y);
		cout<<dis[y]+cs[x]+cs[y]<<'\n';
	}
	return 0;
}

