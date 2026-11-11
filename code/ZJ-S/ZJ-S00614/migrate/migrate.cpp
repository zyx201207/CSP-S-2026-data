#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2000005;
int C, T;
int n, d, a[N], l[N], r[N], f[N], g[N];
int que[N], front, back, s[N];
void solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1, L = 1, R = 1; i <= n; i++){
		while(L <= i && a[i]-a[L] > d) L++;
		while(R < n && a[R+1]-a[i] <= d) R++;
		l[i] = L;
		r[i] = R;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		f[i] = 1;
		g[i] = 0;
		front = 1;
		back = 0;
		que[++back] = i;
		s[0] = 0;
		s[1] = 1;
		int j = i+1, p = 1;
		for(; j <= n; j++){
			f[j] = 0;
			g[j] = INF;
			while(front <= back && a[que[front]]+d < a[j]){
				front++;
				if(p < front){
					p = front;
					while(p < back && g[que[p+1]] == g[que[front]]) p++;
				}
			}
			if(front > back) break;
			g[j] = g[que[front]]+1;
			f[j] = s[p]-s[front-1];
			while(front <= back && g[que[front]] > g[j]) back--;
			p = min(p, back);
			que[++back] = j;
			s[back] = s[back-1]+f[j];
		}
		for(int k = i+1; k < j; k++) if(f[k] == 2) ans++;
	}
	cout << ans << '\n';
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while(T--) solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
