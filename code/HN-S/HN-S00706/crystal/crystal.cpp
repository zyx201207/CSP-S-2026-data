#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],nw,p[500005],maxn,minn = 1e9,ans,cnt;
map<int,int>mp;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) 
	{
		cin >> a[i];
		mp[a[i]]++,cnt = max(cnt,mp[a[i]]);
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++) if (minn >= abs(a[i] - a[(n + 1) / 2])) minn = abs(a[i] - a[(n + 1) / 2]);
	for (int i = 1;i <= n;i++) if (abs(a[i] - a[(n + 1) / 2]) == minn) p[++nw] = a[i];
	for (int i = 1;i <= nw;i++) mp[p[i]]++;
	for (int i = 1;i <= nw;i++) if (maxn < mp[p[i]]) maxn = mp[p[i]];
	minn = 1e9;
	for (int i = 1;i <= nw;i++) if (mp[p[i]] == maxn) minn = min(minn,p[i]);
	for (int i = 1;i <= n;i++)
	{
		if (a[i] > minn) break;
		if (m >= minn - a[i]) m -= (minn - a[i]),ans++;
	}
	cout << max(ans,cnt);
	return 0;
}
