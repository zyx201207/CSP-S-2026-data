#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, m, a[N], la[N], ans[N], p[N], cnt[N], pr[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	fill(cnt, cnt + n + 1, 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	p[n] = 1;
	la[a[n]] = n;
	for (int i = n - 1; i >= 1; --i) {
		if (la[a[i]]) {
			pr[i] = la[a[i]];
		} else {
			p[i] = 1;
			pr[i] = i + 1;
		}
		la[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		if (p[i]) {
			ans[a[i]] += cnt[i];
		}
		cnt[pr[i]] += cnt[i];
	}
	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}
