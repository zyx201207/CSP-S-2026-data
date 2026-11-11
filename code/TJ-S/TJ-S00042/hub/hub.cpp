#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e6 + 10;
int c, t, n, d, r[N];
ll x[N], curmin, ans, cnt;

void dfs(int x, int s, int t, unsigned ll cur) {
	if(x == t) {
		//cout << s << " " << t << " " << cur << "\n";
		if(cur == curmin) cnt++;
		else if(cur < curmin) curmin = cur, cnt = 1;
		return ;
	}
	for(int i=x+1; i<=r[x]; i++) {
		dfs(i, s, t, cur+1);
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i=1; i<=n; i++) cin >> x[i];
		for(int i=1; i<=n; i++) {
			r[i] = i;
			for(int j=i+1; j<=n; j++) if(x[j] <= x[i] + d) r[i] = j;
		}
		ans = 0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<i; j++) {
				cnt = 0; curmin = LLONG_MAX;
				dfs(j, j, i, 0);
				if(cnt == 2) ans++;
			}
		} 
		cout << ans << "\n"; 
	}
	
	return 0;
}
