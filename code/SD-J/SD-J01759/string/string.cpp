#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

using lnt = long long;

const int MAXN = 2e5+10;

int a[MAXN];
char b[MAXN];

void Solve()
{
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i] >> b[i], a[i] += a[i-1];
	lnt ans = 0;
	for (int i=1;a[i]<a[n]/2;i++)
	{
		int now_pos_front = min(a[i-1]+1,a[n]/2), now_pos_end = min(a[i],a[n]/2);
		int end_j = upper_bound(a+1,a+n+1,a[n]-now_pos_front+1) - a;
		int start_j = lower_bound(a+1,a+n+1,a[n]-now_pos_end+1) - a;
		for (int j=start_j+1;j<end_j;j++) if (b[j] != b[i]) ans += a[j]-a[j-1];
		if (b[start_j] != b[i]) ans += a[n]-now_pos_end-a[start_j-1];
		if (b[end_j] != b[i]) ans += a[n]-now_pos_front-a[end_j-1];
	}
	cout << ans; 
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; //cin >> T;
	while (T--) Solve();
	return 0;
}
