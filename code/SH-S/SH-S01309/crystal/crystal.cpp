#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005

int n;
ll m, a[MAXN];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	int l=0, r=0, ans=1, mans=1;
	ll dj=0;
	for (; r<n; r++) {
		dj += (a[r] - a[r-1]) * (r-l);
		while (l <= r && dj > m)
			dj -= a[r] - a[l++];
		ans = r - l + 1;
		mans = max(ans, mans);
	}
	cout << mans << '\n';
	return 0;
}
