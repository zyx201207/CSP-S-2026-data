#include<bits/stdc++.h>
#include<cstdio>
using namespace std; 
#define ll long long
const int N=5e6+10;
ll n,m,t,c,k,q,ins;
ll z[N],d[5010][5010];
ll h[N],e[N],w[N],ne[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//memset(h,-1,sizeof h);
	//cin>>c>>n>>m>>k>>q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&k,&q);
		for(int i=1;i<=400+n;i++)
		{
			for(int j=1;j<=400+n;j++)
			{
				if(i==j)
				{
					d[i][j]=0;
				}
				else d[i][j]=1e16;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cin>>z[i];
		}
		for(int i=1;i<=n;i++)
		{
			ll a1;
			scanf("%lld",&a1);
			for(int j=1;j<=a1;j++)
			{
				ll x,y;
				scanf("%lld%lld",&x,&y);
//				add(x,i+400,y);
//				add(i+400,x,y);
				d[x][i+400]=min(d[x][i+400],y);
				d[i+400][x]=min(d[i+400][x],y);
			}
		}
		for(int i=1;i<=400+n;i++)
		{
			for(int o=1;o<=400+n;o++)
			{
				if(i==o)
				{
					continue;
				}
				for(int j=1;j<=400+n;j++)
				{
					if(i==j||o==j)
					{
						continue;
					}
					else 
					{
						d[i][j]=min(d[i][j],d[i][o]+d[o][j]);
						d[j][i]=min(d[j][i],d[j][o]+d[o][i]);
						d[i][j]=min(d[i][j],d[j][i]);
						d[j][i]=min(d[i][j],d[j][i]);
					}
				}
			}
			
		}
		for(int i=1;i<=q;i++)
		{
			ll x,y;
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",d[x][y]+z[x]+z[y]);
		}
	return 0;
}
