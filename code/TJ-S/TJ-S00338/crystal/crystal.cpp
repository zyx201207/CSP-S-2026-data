#include <bits/stdc++.h>

#define int long long 

using namespace std;

const int N = 1e6 + 10;
int n, m, a[N], b[N];

bool check(int l, int r) {
	int sz = r - l + 1;
	int goal = sz * a[r];
	int sum = b[r] - b[l - 1];
	if(goal - sum <= m) return true;
	return false;
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ) 
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i ++ ) {
		b[i] = a[i];
		b[i] += b[i - 1];
	}
	int maxn = 0;
	for(int i = 1; i <= n; i ++ ) {
		int l = 1, r = i;
		while(l < r) {
			int mid = (l + r) >> 1;
			if(check(mid, i)) r = mid;
			else l = mid + 1;
		}
		maxn = max(maxn, i - l + 1);
	}
	
	cout << maxn << "\n";
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int t; t = 1;
	while(t -- ) solve();
	return 0;
} 
