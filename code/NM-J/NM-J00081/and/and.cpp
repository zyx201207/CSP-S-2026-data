#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[200010];
bool used[200010];
long long jg[200010];
long long maxn = -1;
long long sum;

void dfs (long long pos) {
	if (pos >= m) {
		sum = jg[1];
		for (int i = 2; i <= m; i++) {
			sum = (sum & jg[i]);
		}
		maxn = max(maxn, sum);
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!used[a[i]]) {
			jg[pos] = a[i];
			used[a[i]] = 1;
			dfs(pos++);
			used[a[i]] = 0;
		}
	}
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	dfs(1);

	cout << maxn;
	
    return 0;
}

