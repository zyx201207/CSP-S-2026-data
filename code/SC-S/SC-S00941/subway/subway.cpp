#include<bits/stdc++.h> 
using namespace std;
const int MAX=1e7+5;
typedef long long ll;
ll c,n,m,d,q;
ll w[MAX];
ll p[1005][1005];
struct node{ ll u,v; };
node k[MAX];
struct edge{ ll a,b; };
edge f[MAX];
ll ans=0;
void f1(ll u,ll v)
{
	ll ans=0x7fffffff;
	ll num=w[u]+w[v];
	ll sum=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=3;j<=2*p[i][1];j+=2)
		{
			if(p[i][j]==u)
			f[i].a=j+1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=3;j<=2*p[i][1];j+=2)
		{
			if(p[i][j]==v)
			f[i].b=j+1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=f[i].a,k=f[i].a+2;j<=f[i].b,k<=f[i].b;j+=2,k+=2)
		{
			sum+=p[i][k]-p[i][j];
		}
		ans=min(sum,ans);
	}
	printf("%lld",ans);
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld",&c);
	if(c!=0)
	return 0;
	scanf("%lld %lld %lld %lld",&n,&m,&p,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&p[i][1]);
		for(int j=2;j<=2*p[i][1];j++)
		{
			scanf("%lld",&p[i][j]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%lld %lld",&k[i].u,&k[i].v);
		f1(k[i].u,k[i].v);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}