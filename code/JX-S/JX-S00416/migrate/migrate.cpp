#include <bits/stdc++.h>
#define int long long
#define PII pair <int, int>
#define N 2020231
using namespace std;
const int INF = 2e18;
const int mod = 998244353;

int C;

int n, d, x[N];

void solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++)
		cin >> x[i];
	
	if(C <= 10){
		
		deque <int> q;
		map <int, int> tim;
		vector <int> dp, cnt;
		int ans = 0;
		for(int u = 1; u <= n; u++){
			dp.assign(n + 1, 0);
			cnt.assign(n + 1, 0);
			q.clear();
			tim.clear();
			cnt[u] = 1;
			for(int v = u + 1; v <= n; v++){
				while(!q.empty() && dp[q.front()] > dp[v - 1])
					tim[dp[q.front()]] -= cnt[q.front()],
					q.pop_front();
				tim[dp[v - 1]] += cnt[v - 1];
				q.push_front(v - 1);
				while(!q.empty() && abs(x[v] - x[q.back()]) > d)
					tim[dp[q.back()]] -= cnt[q.back()],
					q.pop_back();
				if(q.empty()) break;
				dp[v] = dp[q.back()] + 1;
				cnt[v] = tim[dp[q.back()]];
				ans += (cnt[v] == 2);
				
				/*
				
				cout << u << "->" << v << ' ' << dp[v] << ' ' << cnt[v] << '\n';
				for(auto x : q)
					cout << x << ' ' << dp[x] << ' ' << cnt[x] << '\n';
				if(cnt[v] == 2){
					cout << "add : " << u << ' ' << v << '\n';
				}
				
				*/
			}
		}
		cout << ans << '\n';
		
	} else if(C <= 12){
		
		if(n == 1) return cout << 0 << '\n', void(0);
		int dx = x[2] - x[1];
		if(dx == 0) return cout << 0 << '\n', void(0);
		int D = d / dx;
		if(D <= 1) return cout << 0 << '\n', void(0);
		int ans = 0;
		for(int i = 1; i <= n; i++){
			int l = i + D + 1;
			int r = min(i + 2 * D - 1, n);
			if(l > r) continue;
			ans += r - l + 1;
		}
		cout << ans << '\n';
		
	} else if(C <= 14){
		
		int ans = 0;
		for(int i = 1; i <= n; i++){
			int l = x[i] + d + 1;
			int r = x[i] + 2 * d;
			int pl = lower_bound(x + 1, x + 1 + n, l) - x;
			int pr = lower_bound(x + 1, x + 1 + n, r) - x - 1;
			if(pl < pr)
				ans += r - l + 1;
		}
		cout << ans << '\n';
		
	} else cout << "0\n";
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> C >> T;
	while(T--)
		solve();
	return 0;
}

// nooooo i waste much time on wrong idea qwq
