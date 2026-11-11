#include<bits/stdc++.h>
using namespace std;
const int MAX=1e7+5;
typedef long long ll;
ll c,t;
ll n,d;
ll a[MAX];
ll k[MAX];
int dfs(ll t,ll p,ll num)
{
	if(t>n&&p>n)
	{
		return num;
	}
	if(t==p&&t!=1)
	{
		num++;
	}
	dfs(t+1,p+1,num);
	dfs(t+1,p+2,num);
	dfs(t+2,p+1,num);
	dfs(t+2,p+2,num);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate,out","w",stdout);
	scanf("%lld %lld",&c,&t);
	if(c!=0)
	return 0;
	for(int i=1;i<=t;i++)
	{
		scanf("%lld %lld",&n,&d);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[j]);
		}
		k[i]=dfs(1,1,0);
	}
	for(int i=1;i<=t;i++)
	printf("%lld\n",k[i]);
	return 0;
}
