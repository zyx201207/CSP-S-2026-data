#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define repb(i, a, b) for(int i = (a); i >= (b); --i)

typedef long long ll;
const int N = 2e6 + 5;
const ll INf = 5e18;

int c, T;
int n;
ll d;
ll x[N];

int h[N], t[N];
ll sh[N], st[N];

int dis[N];
ll cnt[N];

int calc(int st){
	queue<int> q;
	rep(i, 1, n) dis[i] = -1, cnt[i] = 0;
	dis[st] = 0;
	cnt[st] = 1;
	q.push(st);
	while(!q.empty()){
		int u = q.front(); q.pop();
		int pos = upper_bound(x + 1, x + 1 + n, x[u] + d) - x - 1;
		repb(i, pos, u + 1){	
			if(dis[i] == -1){
				dis[i] = dis[u] + 1;
				cnt[i] = cnt[u];
				q.push(i);
			}
			else if(dis[i] == dis[u] + 1) cnt[i] += cnt[u];
		}
	}
	int res = 0;
	rep(i, st + 1, n){
		res += (cnt[i] == 2);
	}
	return res;
}

void solve(){
	cin >> n >> d;
	rep(i, 1, n) cin >> x[i];
	
	x[0] = -INf, x[n + 1] = INf;
	rep(i, 1, n){
		h[i] = 1;
		if(i > 1 && x[i] - x[i - 2] > d && x[i + 1] - x[i - 1] > d && x[i] - x[i - 1] <= d) h[i] += h[i - 1];
		sh[i] = sh[i - 1] + h[i];
	}
	repb(i, n, 1){
		t[i] = 1;
		if(i < n && x[i + 2] - x[i] > d && x[i + 1] - x[i - 1] > d && x[i + 1] - x[i] <= d) t[i] += t[i + 1];
		st[i] = st[i + 1] + t[i];
	}
	
	ll ans = 0;
	rep(i, 1, n){
		int pos1 = upper_bound(x + 1, x + 1 + n, x[i] + d) - x - 1;
		if(pos1 <= i + 1) continue;
		int posl = upper_bound(x + 1, x + 1 + n, x[pos1 - 2] + d) - x;
		int posr = upper_bound(x + 1, x + 1 + n, x[pos1 - 1] + d) - x - 1;
		if(posr <= pos1 || posl <= pos1 || posr < posl) continue;
		ans += h[i] * (st[posl] - st[posr + 1]);
//		cout << i << ' ' << h[i] << ' ' << (st[posl] - st[posr + 1]) << ' ' << posl << ' ' << posr << '\n';
	}
	cout << ans << '\n';
}

void solve2(){
	if(c >= 11){
		solve();
		return;
	}
	cin >> n >> d;
	rep(i, 1, n) cin >> x[i];
	ll ans = 0;
	rep(i, 1, n){
		int t = calc(i);
		ans += t;
	}
	cout << ans << '\n';
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> c >> T;
	while(T--) solve2();
	
	return 0;
}