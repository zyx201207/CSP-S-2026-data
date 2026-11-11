#include <bits/stdc++.h>
#define int long long
using namespace std;

int testid,test,n,d,a[2000005],nxt[2000005],suf[2000005],val[2000005],val2[2000005],dp[2000005];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> testid >> test;
	while (test--)
	{
		cin >> n >> d;
		for (int i = 1;i <= n;i++) cin >> a[i],suf[i] = val[i] = dp[i] = 0;
		for (int i = 1;i <= n;i++) nxt[i] = upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		for (int i = n;i >= 1;i--)
		{
			suf[i]++;
			if (nxt[i] != i && nxt[i-1] < nxt[i]) suf[i] += suf[nxt[i]];
		}
//		for (int i = 1;i <= n;i++) cout << nxt[i] << ' ';cout << endl;
		int ans = 0;
		for (int i = 1;i <= n;i++)
		{
			int x = nxt[i]-1,y = nxt[i];
			if (x <= i) continue;
			int l = max(y,nxt[x-1])+1,r = nxt[x];
			if (l > r) continue;
//			cout << i << ' ' << x << ' ' << y << ' ' << l << ' ' << r << endl;
			
			val[i] = r-l+1;
			int nxty = nxt[y];
			if (r == nxty && nxt[r-1] < nxt[r]) val[i] += nxt[r]-nxt[nxty-1]-1;
			if (r == nxty) val[i] += suf[r]-1;
		}
		for (int i = 1;i <= n;i++)
		{
			int x = nxt[i]-1,y = nxt[i];
			if (x <= i) continue;
			int l = max({y,nxt[x-1],nxt[nxt[i-1]]})+1,r = nxt[x];
			if (l > r) continue;
//			cout << i << ' ' << x << ' ' << y << ' ' << l << ' ' << r << endl;
			
			val2[i] = r-l+1;
			int nxty = nxt[y];
			if (r == nxty && nxt[nxty-1] < nxt[nxty]) val2[i] += nxt[nxty]-nxt[nxty-1]-1;
			if (r == nxty) val2[i] += suf[r]-1;
		}
//		for (int i = 1;i <= n;i++)
//		{
//			int now = i,to = nxt[i];
//			while (now != to)
//			{
//				ans += val[now];
////				cout << now << ' '
//				if (nxt[to-1] >= nxt[to]) break;
//				now = to,to = nxt[to];
//			}
//		}
		for (int i = n;i >= 1;i--)
		{
			if (nxt[i] == i) continue;
			dp[i] = val2[i];
			if (nxt[nxt[i]-1] < nxt[nxt[i]]) dp[i] += dp[nxt[i]];
			ans += dp[i]+val[i]-val2[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
