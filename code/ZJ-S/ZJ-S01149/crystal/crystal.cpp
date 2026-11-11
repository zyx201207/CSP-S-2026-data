#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+100;
int n,maxk,f[100];
ll m,a[N];
void dfs(int x,int opt,ll ans,int cnt)
{
	if(ans>m)
	{
		if(cnt-1>maxk) maxk=cnt-1;
		return ;
	}
	for(int i=1;i<=n;++i)
	{
		if(f[i]) continue;
		f[i]=1;
		dfs(i,opt,ans+abs(a[opt]-a[i]),cnt+1);
		f[i]=0;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)
	  scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		  f[j]=0;
		f[i]=1;
		dfs(i,i,0,1);
	}
	printf("%d",maxk);
	return 0;
}
