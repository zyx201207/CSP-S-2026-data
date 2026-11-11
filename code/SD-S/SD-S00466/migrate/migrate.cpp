#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=510,INF=0x3f3f3f3f3f3f3f3f;
ll x[N],f[N][N],cnt[N][N];
vector <ll> G[N];
void solve()
{
	ll n,d;
	cin >> n >> d;
	for (int i=1;i<=n;i++) cin >> x[i];
	
	for (int i=1;i<=n;i++) G[i].clear();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			f[i][j]=INF;
			cnt[i][j]=0;
			if (i==j) f[i][j]=0;
		}
	}
	
	sort(x+1,x+1+n);
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if (x[j]-x[i]<=d)
			{
				f[i][j]=1;
				cnt[i][j]=1;
			}
		}
	}
	
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (f[i][j]>f[i][k]+f[k][j])
				{
					f[i][j]=f[i][k]+f[k][j];
					cnt[i][j]+=cnt[i][k]+cnt[j][k];
				}
				else if (f[i][j]==f[i][k]+f[k][j] && i!=j && i!=k && j!=k) cnt[i][j]+=cnt[i][k]+cnt[j][k];
			}
		}
	}
	
	ll ans=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) if (cnt[i][j]==2) ans++;
	}
	cout << ans << "\n";
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
