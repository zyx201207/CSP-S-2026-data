#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAX=1e7+5;
typedef long long ll;
ll n,m;
ll a[MAX];
void dfs(ll step,ll sum,ll num)
{
	if(sum>m)
	{
		printf("%lld",step);
		return ;
	}
	if(a[step]<a[num])
	{
		sum+=step;
		for(ll i=1;i<=step;i++)
		{
			a[i]++;
		}
		dfs(step,sum,num);
	}
	else if(sum<=m&&a[step]==a[num])
	{
		dfs(step+1,sum,num+1);
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	dfs(1,0,2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}