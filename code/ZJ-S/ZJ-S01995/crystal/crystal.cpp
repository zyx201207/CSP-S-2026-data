#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n, m;
	
	cin >> n >> m;
	
	vector<int> v(n);
	
	for (int i = 0; i < n; ++i) cin >> v[i];
	
	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; ++i) cout << v[i] << endl;
	
	int ans = 1;
	
	for (int i = 0; i < n; ++i) {
		int l = i - 1, r = i + 1, t = m, cnt = 0;
		
		while (1) {
			if (t == 0) break;
			int minnum = 0;
			if (l < 0 && r >= n) break;
			if (l < 0) minnum = v[r] - v[i], r++;
			if (r >= n) minnum = v[i] - v[l], l--;
			if (l >= 0 && r < n) if (v[i] - v[l] < v[r] - v[i]) minnum = v[i] - v[l], l--; else minnum = v[r] - v[i], r++;
			
			if (minnum > t) break;
			t -= minnum;
			++cnt;
		}
		
		cout << cnt << ' ' << ans << ' ' << i << endl;
		
		ans = max(ans, cnt + 1);
	}
	
	cout << ans << endl;
	
	return 0;
}