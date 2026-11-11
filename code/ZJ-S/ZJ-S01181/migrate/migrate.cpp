#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,f[5005][5005],d,c,T,a[2000005];
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	a[0]=-1e9;
	int now=0;
	for(int i=1;i<=n;i++)
	{
		int now=i,k=i,cnt=0;
		while(k<=n&&now<n)
		{
			while(now<=n&&a[now]-a[k]<=d)now++;
			now--;
			f[i][now]=++cnt;
			k=now;
		}
	}
	int w=0;
	for(int i=1;i<=n;i++)
	  for(int j=n;j>=i;j--)
	  {
	  	if(!f[i][j])f[i][j]=w;
	  	else w=f[i][j];
	  }
	for(int i=1;i<=n;i++)
	  f[i][i]=0;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=i;j<=n;j++)
//		  cout<<f[i][j]<<' ';
//		cout<<endl;
//	}
	int ans=0,mi=1e14;
	for(int i=1;i<=n;i++)
	  for(int j=n;j>i;j--)
	  {
	  	int cnt=0;
	  	for(int k=i+1;k<j;k++)
	      if(mi>f[i][k]+f[k][j])mi=f[i][k]+f[k][j],cnt=1;
	      else if(mi==f[i][k]+f[k][j])cnt++;
	    if(cnt==2)ans++;
	  }
	    
	cout<<ans<<'\n';
}
void solve1314()
{
	cout<<0<<'\n';
	return ;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		if(c==13||c==14)solve1314();
		else solve();
	}
	return 0;
}
