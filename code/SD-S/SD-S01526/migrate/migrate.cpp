#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10, inf = 2e18 + 10;
int c, T;
int n, d, x[N], len[N], cnt[N], sum[N];
void solve1(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> x[i];
	int ans = 0;
	
	for(int s = 1; s < n; s++){
		for(int i = 0; i <= n; i++) len[i] = inf, cnt[i] = 0, sum[i] = 0;
		len[s] = 0;
		cnt[s] = sum[s] = 1;
		
		for(int i = s + 1; i <= n; i++){
			int pos = lower_bound(x + s, x + n + 1, x[i] - d) - x;
			if(pos == i) break;
			int l = pos, r = i - 1, res = pos;
			while(l <= r){
				int mid = l + r >> 1;
				if(len[mid] == len[pos]) res = mid, l = mid + 1;
				else r = mid - 1;
			}
			len[i] = len[pos] + 1;
			cnt[i] = sum[res] - sum[pos - 1];
			if(cnt[i] == 2) ans++;
			sum[i] = sum[i - 1] + cnt[i];
		} 
	}
	cout << ans << "\n";
}
void solve2(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> x[i];
	if(n == 1){
		cout << 0 << "\n";
		return;
	}
	int k = d / (x[2] - x[1]);
	if(k <= 1){
		cout << 0 << "\n";
		return;
	}
	int res = 0;
	for(int i = 2 * k; i <= n; i++) res++;
	cout << res << "\n";
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0);
	std::ios::sync_with_stdio(0);
	cin >> c >> T;
	while(T--){
		if(c <= 10) solve1();
		else solve2();
	}

	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
