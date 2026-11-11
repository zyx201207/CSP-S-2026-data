#include<bits/stdc++.h>
using namespace std;
int ca,t,n;
long long a[2000010],ans=0,f[2000010],g[2000010],d,mi[20][20],road[20][20];
int cnt[2000010];
void solve1()
{
	int r=1,l=n;
	for (int i=1;i<=n;i++)
	{
		while (a[r+1]-a[i]<=d&&r<n) r++;
		f[i]=r;
	}
	for (int i=n;i>=1;i--)
	{
		while (a[i]-a[l-1]<=d&&l>1) l--;
		g[i]=l;
	}
	for (int i=1;i<=n;i++) cnt[g[i]]++;
	for (int i=1;i<=n;i++)
	{
		ans+=1ll*cnt[f[i]-1];
		if (g[i]==f[i]-1) ans--;
	}
	cout << ans;
	for (int i=1;i<=n;i++) f[i]=g[i]=cnt[i]=0;
}
void dfs(int s,int u,int pos)
{
	if (pos<mi[s][u])
	{
		mi[s][u]=pos;
		road[s][u]=1;
	}
	else if (pos==mi[s][u]) road[s][u]++;
	if (u==n) return;
	for (int j=u+1;j<=n;j++)
		if (a[j]-a[u]<=d)
			dfs(s,j,pos+1);
}
void solve2()
{
	memset(mi,0x3f,sizeof(mi));
	for (int i=1;i<=n;i++)
	{
		dfs(i,i,0);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (road[i][j]==2)
				ans++;
	printf("%lld\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> ca >> t;
	while (t--)
	{
		ans=0;
		scanf("%d %lld",&n,&d);
		for (int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		if (ca>=3) solve1();
		else if (ca<=2) solve2();
	}
	return 0;
}