#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 100;
int x[N];
char s[N];
int n, ans = 0;
int cnt[255];
bool vis[255];
signed main() {
	// aabbc -> abcba
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> s[i];
		cnt[s[i]] += x[i];
		
	}	
	for (char i = 'a'; i <= 'z'; i++) {
		if (vis[i] == 0 && cnt[i] > 1) {
			int idx = lower_bound(s + 1, s + 1 + n, i) - s;
			cout << i << ' ' << idx << ' ';
			//cout << cnt[i];
			ans += abs(cnt[i] / 2 - x[idx]);
			cout << ans << '\n';            
		}
		vis[i] = 1;	
	}
	cout << ans;
	return 0;
}