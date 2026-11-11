#include <bits/stdc++.h>
#define ll long long
#define int register int
#define db double
#define pii pair<ll,ll>
#define mpi make_pair
#define fir first
#define sec second
#define AKIOI ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define AKNOI return 0
#define endl '\n'
using namespace std;
const ll MAXN = 505;
ll c, n, m, d, Q, w[MAXN], ans;
vector<pii >mptb[MAXN];//ai->ti, bi
vector<pii >mpta[MAXN];//bi->ti, ai

//ll quickpow(ll m,ll p){
//	if(p%2==1) return m*quickpow(m*m,(p-1)/2);
//	else return quickpow(m*m,p/2);
//}

bool vis[MAXN];//标记每个点是否已达。

void bfs(ll st, ll ed) {
	queue<pair<ll, pii> >q; //已经花了多长时间，走到了哪个点，在哪条线路上。
	for (auto it : mptb[st]) {
		q.push(mpi(w[st] + w[ed] + it.fir, mpi(st, it.sec)));
	}
	while (q.size()) {
		pair<ll, pii> now = q.front();
		q.pop();
		if (now.sec.fir == ed) {
			//从线路 now.sec.sec 到点 ed 所需的时间。
			for (auto it : mpta[now.sec.sec]) {
				if (it.sec == ed) {
					ans = min(ans, now.fir + it.fir);
					break;
				}
			}
			return;
		}
		for (auto it1 : mptb[now.sec.fir]) { //枚举可达的线路
			for (auto it2 : mpta[it1.sec]) { //对于每条线路，枚举可达的点。
				if (vis[it2.sec])
					continue;
				vis[it2.sec] = 1;
				if (it1.sec == now.sec.sec)
					q.push(mpi(now.fir, mpi(it2.sec, it1.sec)));
				else
					q.push(mpi(now.fir + it2.fir + it1.fir, mpi(it2.sec, it1.sec)));
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	AKIOI;
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (signed i = 1; i <= n; i++) {
		ll ki, ai, ti;
		cin >> ki;
		for (int j = 1; j <= ki; j++) {
			cin >> ai >> ti;
			mptb[ai].push_back(mpi(ti, i)); //对于点 ai，可以用 ti 的代价移动到线路 i 上。
			mpta[i].push_back(mpi(ti, ai)); //对于线路 i，可以用 ti 的代价移动到点 ai 上。
		}
	}
	for (int i = 1; i <= Q; i++) {
		memset(vis, 0, sizeof(vis));
		ans = LLONG_MAX;
		ll x, y;
		cin >> x >> y;
		bfs(x, y);
		cout << ans << endl;
	}
	AKNOI;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16
*/