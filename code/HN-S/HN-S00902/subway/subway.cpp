#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,flooor[505],p,state,vv,head[20005],u,v,w,t=1,dis[20005],f[20005],l,r;
struct node{
	int v,w,next;
}a[20005];
int add(int u,int v,int w)
{
	a[t].v=v;
	a[t].w=w;
	a[t].next=head[u];
	head[u]=t;
	t++;
	return 0;
}
int djs(int x)
{
	dis[x]=0;
	for(int i=1;i<=m;i++)
	{
		int o=-1;
		for(int k=1;k<=m;k++)
		{
			if((dis[k]<dis[o]||o==-1)&&f[k]==0)
			{
				o=k;
			}
		}
		f[o]=1;
		for(int j=head[o];j!=-1;j=a[j].next)
		{
			dis[a[j].v]=min(dis[a[j].v],dis[o]+a[j].w);
		}
	}
	return 0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>flooor[i];
	}
	for(int i=1;i<=20005;i++)
	{
		head[i]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p;
		m++;
		for(int j=1;j<=p;j++)
		{
			cin>>state>>vv;
			add(state,m,vv);
			add(m,state,vv);
		}
	}
	for(int z=1;z<=q;z++)
	{
		for(int i=1;i<=m;i++)
		{
			dis[i]=0x7f7f7f7f;
			f[i]=0;
		}
		cin>>l>>r;
		djs(l);
		cout<<flooor[l]+dis[r]+flooor[r]<<endl;
	}
	return 0;
} 
