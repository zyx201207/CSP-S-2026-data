/*
第二题怎么有点吃力
数值膨胀你赢了
还好想出来了
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c, n, m, d, q;//n->sub_way_number m->state_number
const ll maxn = 2e6+10;
ll W_in[maxn];
ll Kv[500010][22];//这个站的第i个的是哪个个编号
ll idx_kv[500010];//这个站有多少个地铁
ll Kv_v[500010][22];//这个站的第i个的平台时间
ll flyd[510][510];//flyd 耍起嘛
ll s, t;
const ll inf = 1e18+10;
void Init() {
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++)flyd[i][j] = inf;
		flyd[i][i] = 0;
	}
	for (ll i = 1; i <= m; i++) {
		for (ll j = 1; j <= idx_kv[i]; j++) {
			for (ll k = j + 1; k <= idx_kv[i]; k++) {
				flyd[Kv[i][j]][Kv[i][k]] = min(flyd[Kv[i][j]][Kv[i][k]], Kv_v[i][j] + Kv_v[i][k]);
				flyd[Kv[i][k]][Kv[i][j]] = min(flyd[Kv[i][k]][Kv[i][j]], Kv_v[i][j] + Kv_v[i][k]);
			}
		}
	}
}
void play_flyd() {
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			for (ll k = 1; k <= n; k++) {
				flyd[i][j] = min(flyd[i][k] + flyd[k][j], flyd[i][j]);
			}
		}
	}
}
void Let_me_IN() {
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++)cin >> W_in[i];
	for (ll i = 1; i <= n; i++) {
		ll state_number;
		cin >> state_number;
		for (ll j = 1; j <= state_number; j++) {
			ll state_id;
			cin >> state_id;
			ll tim_ned;
			cin >> tim_ned;
			idx_kv[state_id]++;
			Kv[state_id][idx_kv[state_id]] = i;
			Kv_v[state_id][idx_kv[state_id]] = tim_ned;
		}
	}
}
void Ill_give_U_ANSWER() {
	ll ANS_forU = inf;
	for (ll i = 1; i <= idx_kv[s]; i++) {
		for (ll j = 1; j <= idx_kv[t]; j++) {
			ANS_forU = min(ANS_forU, W_in[t] + W_in[s] + Kv_v[s][i] + Kv_v[t][j] + flyd[Kv[s][i]][Kv[t][j]]);
		}
	}
	cout << ANS_forU << '\n';
}
//void Poll_out() {
//	for (ll i = 1; i <= n; i++) {
//		for (ll j = 1; j <= n; j++) {
//			cout << flyd[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Let_me_IN();
	Init();
	play_flyd();
//	Poll_out();
	while (q--) {
		cin >> s >> t;
		Ill_give_U_ANSWER();
	}
}