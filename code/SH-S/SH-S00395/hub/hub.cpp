#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c, t, n, k, u, v, rr, cnt[1000005], sl[1000005], cntans[1000005];
ll ret, lian;
vector <ll> e[1000005], pt[1000005], xm[1000005], rq;
bool b[1000005], con[1000005], ans[1000005];
void dfs(ll now, ll fa, ll dis)
{
	cnt[now]++, pt[rr].push_back(now), xm[now].push_back(rr);
	if (!dis) return;
	for (ll i : e[now]) if (i != fa) dfs(i, now, dis - 1);
}
bool cmp(ll ta, ll tb)
{
	return cnt[ta] > cnt[tb];
}
void cal(ll now, ll fa)
{
	cntans[now] = ans[now];
	for (ll i : e[now])
	{
		if (i == fa) continue;
		cal(i, now);
		cntans[now] += cntans[i];
	}
}
void work(ll now, ll fa, bool ad)
{
	ad |= ans[now];
	if (!ans[now]) con[now] = 1, ret++;
	for (ll i : e[now])
	{
		if (i == fa) continue;
		if (!cntans[i]) continue;
		work(i, now, ad);
	}
}
void fin(ll now, ll fa, ll cc)
{
	ll cntd = 0;
	for (ll i : e[now])
	{
		if (i == fa) continue;
		if (!con[i]) continue;
		cntd++;
	}
	lian = max(lian, cc - (cntd > 1));
	for (ll i : e[now])
	{
		if (i == fa) continue;
		if (!con[i]) continue;
		if (cntd <= 1) fin(i, now, cc + 1);
		else fin(i, now, 1);
	}
}
bool check(ll num)
{
	rq.clear();
	for (ll i = 1; i <= n; i++) cnt[i] = 0, xm[i].clear();
	for (ll i = 1; i <= n; i++) cntans[i] = con[i] = ans[i] = 0, b[i] = 1, rr = i, dfs(i, 0, num);
	for (ll i = 1; i <= n; i++) sl[i] = i;
	ll rst = n, idex = 0;
	ret = lian = 0;
	for (ll i = 1; i <= n; i++)
	{
		sort(sl + i, sl + n + 1, cmp);
		ans[sl[i]] = 1, ret++;
		idex = sl[i];
		for (ll j : xm[sl[i]])
		{
			for (ll k : pt[j]) cnt[k]--;
			pt[j].clear();
			if (b[j]) b[j] = 0, rst--;
		}
		if (!rst) break;
	}
	cal(idex, 0);
	work(idex, 0, 0);
	for (ll i = 1; i <= n; i++) if (con[i]) fin(i, 0, 1);
	return ret - lian <= k;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		for (ll i = 1; i <= n; i++) e[i].clear();
		for (ll i = 1; i < n; i++) cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
		ll l = 0, r = n;
		while (l < r)
		{
			ll mid = (l + r) / 2;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		cout << l << "\n";
	}
}
