#include<bits/stdc++.h>
#define int long long
#define writen ios::sync_with_stdio(false);
#define by cin.tie(0);
#define Sxi cout.tie(0)
using namespace std;
const int N=2e6+10;
int n,m,t,k,a[N],d,c;
int dis[N],b[N];
int cnt[N];
bool vis[5000][5000];
void solve()
{
	cin>>n>>d;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i+3]-a[i]>d&&a[i+3]-a[i+1]<=d) ans++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<i;j++)
		{
			if(a[j]-a[j-1]<=d&&a[j]-a[j-2]>d)ans++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[j-1]<=d&&a[j]-a[j-2]>d)ans++;
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	writen by Sxi;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return (0^0);
}

