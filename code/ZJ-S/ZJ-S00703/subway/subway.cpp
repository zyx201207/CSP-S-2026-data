#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N],t[N][505],dis[N];
struct node
{
	int v,sub;
};
vector<node>g[N];
void go(int x,int s,int y)
{
	for(auto k:g[x])
	{
		if(k.v==x) continue;
		int d=0;
		if(k.sub!=s)
		{
			d=t[x][s]+t[x][k.sub];
		}
		if(k.v==y)
		{
			if(dis[k.v]>dis[x]+d+t[k.v][k.sub])
			{
				dis[k.v]=dis[x]+d+t[k.v][k.sub];
			}
		}
		else if(dis[k.v]>dis[x]+d)
		{
			dis[k.v]=dis[x]+d;
			go(k.v,k.sub,y);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",w+i);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		if(k<2)
		{
			cin>>k;
			cin>>k;
			continue;
		}       
		int la=0;
		for(int j=1;j<=k;j++)
		{
			int a,tt;
			scanf("%d%d",&a,&tt);
			if(j==1) la=a;
			else
			{
				g[a].push_back({la,i});
				g[la].push_back({a,i});
			}
			t[a][i]=tt;
		}
	}
	for(int r=1;r<=q;r++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		for(int i=1;i<=m;i++) dis[i]=INT_MAX;
		dis[x]=0;
		go(x,0,y);
		printf("%d\n",dis[y]+w[x]+w[y]);
	}
	return 0;
}