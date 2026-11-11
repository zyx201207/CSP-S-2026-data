#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N = 2000005;
int c,T,n,d,a[N],r[N],l[N],f[N],ff[N],g[N],gg[N],ll[N],rr[N],cnt,tpl[N],tpr[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 0; i <= n+1; i++)
			f[i] = ff[i] = g[i] = gg[i] = tpl[i] = tpr[i] = 0;
		int pot = 1;
		for (int i = 1; i <= n; i++)
		{
			while (pot <= n && a[pot]-a[i] <= d) pot++;
			r[i] = pot-1;
		}
		for (int i = n; i >= 1; i--)
		{
			f[i] = r[i]-i+ff[r[i]];
			if (r[i-1] < r[i])
			{
				ff[i] = r[i]-r[i-1]+ff[r[i]];
			}
			else ff[i] = 0;
		}
		pot = n;
		for (int i = n; i >= 1; i--)
		{
			while (pot >= 1 && a[i]-a[pot] <= d) pot--;
			l[i] = pot+1;
		}
		l[n+1] = n+1;
		for (int i = 1; i <= n; i++)
		{
			g[i] = i-l[i]+gg[l[i]];
			if (l[i+1] > l[i])
			{
				gg[i] = l[i+1]-l[i]+gg[l[i]];
			}
			else gg[i] = 0;
		}
		int ans = 0;
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (r[i] > rr[cnt])
			{
				cnt++;
				ll[cnt] = i,rr[cnt] = r[i];
				tpl[i] = cnt,tpr[r[i]] = cnt;
			}
		}
		rr[0] = 0,ll[n+1] = n+1;
		for (int i = 1; i <= cnt; i++)
		{
			if (rr[i]-ll[i] >= 2)
			{
				int j = tpl[rr[i]-1];
				if (!j) continue;
				int x = ll[i+1]-ll[i],y = rr[j]-rr[j-1];
			//	if (!y) continue;
				if (rr[i-1] < rr[i]-1) x = gg[rr[i]];
				if (ll[j+1] > ll[j]+1) y = ff[ll[j]];
				ans += x*y;
		//	cout << i << ' ' << x << ' ' << y << '\n';
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 1
10 14
-31 -24 -17 -10 -3 4 11 18 25 32

5
*/
