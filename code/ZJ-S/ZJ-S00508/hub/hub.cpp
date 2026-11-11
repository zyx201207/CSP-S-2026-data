#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define D(x) cout << #x << ": " << x << ' '
#define DE(x) cout << #x << ": " << x << '\n'
#define pii pair<ll, ll>
#define mkp(x, y) make_pair(x, y)
#define pl p << 1
#define pr p << 1 | 1
using namespace std;
constexpr ll MOD = 998244353ll, inf = 1ll << 56;
ll Case, tt;
ll n, m, k, qq;
ll dis[1000010];
bool vis[1000010];
vector<ll> G[1000010];
struct node
{
	ll x, d;
	bool operator < (const node &t) const
	{
		return d > t.d;
	}
};
/*
竟然是最后一次了么
进考场前拍集体照，没忍住，掉小珍珠了
不舍么？肯定的
不甘么？远比表现出来的多
但是……又有什么办法呢？
T1 依旧神秘二分，12mins 过大样例，希望别挂吧，最后再拍
T2 题意有点长，理解了 10mins
看着好像分层图，我写，调的脑子有点晕。
突然发现写唐了，可以直接将一条线视作一个点的，测下大样例。 
最后一个跑了 0.97s，有点慌 15:40 过大样例，似乎不太好拍
祈祷大样例不要太水吧
T3 先写一个 n ^ 2 log(n) 的暴力
很好，过了前三个样例
发现，尽量往后跳路径一定短？那么只需要记录最后三个即可？
好像会出问题，因为中间的节点被跳过了 
似乎，如果 cnt[u] > 3 以后，这个节点就不用再去更新其他节点了
拍了一下，似乎是对的 
复杂度不会算，应该能有 40pts？ 
观察了一下，似乎可以用线段树维护
但是计算的是 1 为起点的点对
枚举起点的话又是 n ^ 2log(n) 了
但是似乎比上一份代码跑得更快？
拍了 1000 组 应该没有问题，但是 n = 5000 要跑 2.5s，完了 
先开 T4 16:57
先打一个 2^n * n * log(n) 15pts 17:15
特殊性质有点神秘，先放了
回去想 T3 
mn 是单调不减的
有什么说法么？
那么 pos[e] 的 mn 一定最小
我只需要统计 pos[e] ~ e - 1 有多少个 mn，开个桶，似乎是 n ^ 2 了
搞一个指针移动一下，这样应该是 n ^ 2，拍了 1000 组，40pts 17:52
回去拍一下 T1
继续想 T4
是否可以枚举连通块大小，然后贪心地选点？
似乎有点难实现，调不出来可能 17:56，再去想想 T3
回头看了眼 T2，竟然没有最大的样例
完了，复杂度似乎假了，n * d * q = 1e9，第二大的是 1e8，好像还带 log，有点卡常，祈祷有 90pts
检查了一下前两题
T3 性质B 有点说法，还能争么？
争不动了，先保分 18:15 
T3 又拍了 1000 组，应该不会挂吧
还是做不到么？
尽管已经有所预料了……
欸……
希望别挂分吧—— 
*/

void baoli()
{
	ll ans = inf;
	for (ll st = 0; st < (1ll << n); st++)
	{
		if (__builtin_popcountll(st) != k)
			continue;
		for (int i = 1; i <= n; vis[i++] = 0);
		ll cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (((st >> j - 1) & 1ll) == 0)
				continue;
			if (!vis[j])
			{
				cnt++;
				queue<ll> q;
				q.push(j);
				while (q.size())
				{
					ll u = q.front(); q.pop();
					vis[u] = 1;
					for (auto v : G[u])
						if (((st >> v - 1) & 1ll) && !vis[v])
							q.push(v);
				}
			}
		}
		if (cnt <= 2)
		{
			priority_queue<node> q;
			for (int i = 1; i <= n; i++)
				if (vis[i])
					q.push(node{i, dis[i] = 0});
				else
					dis[i] = inf;
			ll res= -inf;
			while (q.size())
			{
				ll u = q.top().x, d = q.top().d; q.pop();
				if (dis[u] != d)
					continue;
				res = max(res, d);
				for (auto v : G[u])
					if (dis[v] > dis[u] + 1)
						q.push(node{v, dis[v] = dis[u] + 1});
			}
			ans = min(ans, res);
		}
	}
	cout << ans << '\n';
}

void solve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; G[i++].clear());
	for (int i = 1; i < n; i++)
	{
		ll u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if (n <= 10)
		return baoli(), void();
}

int main()
{
	ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	for (cin >> Case >> tt; tt--; )
		solve();
	return 0;
}

