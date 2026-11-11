#include <queue>
#include <cstdio>
namespace FastIn
{
	const int S = 4e6 + 7;
	char *p1, *p2, buf[S];
	#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, S, stdin), p1 == p2) ? EOF : *p1++)
	template <typename _T>
	inline void read(_T &x)
	{
		x = 0;
		char c = gc();
		bool isneg = false;
		for (; c < '0' || c > '9'; c = gc())
			isneg |= c == '-';
		for (; c >= '0' && c <= '9'; c = gc())
			x = (x << 3) + (x << 1) + (c & 15);
		isneg && (x = -x);
	}
	#undef gc
}
using FastIn::read;
const int MAXN = 2e6 + 7;
int sid, T, n;
long long D, ans, a[MAXN];
namespace task3
{
	struct DPValue { int dis, cnt; };
	std::deque<std::pair<long long, DPValue>> q;
	inline void solve()
	{
		for (int i = 1; i <= n; ++i)
		{
			q.clear(), q.push_front({a[i], {0, 1}});
			for (int j = i + 1; j <= n; ++j)
			{
				while (q.size() && a[j] - q.back().first > D)
					q.pop_back();
				if (q.empty())
					break;
				DPValue cur = {q.back().second.dis + 1, 0};
				for (int k = (int)(q.size()) - 1; ~k; --k)
				{
					if (q[k].second.dis != cur.dis - 1)
						break;
					cur.cnt += q[k].second.cnt;
					if (cur.cnt >= 3)
					{
						cur.cnt = 3;
						break;
					}
				}
				cur.cnt == 2 && ++ans;
				while (q.size() && q.front().second.dis > cur.dis)
					q.pop_front();
				q.push_front({a[j], cur});
			}
		}
		printf("%lld\n", ans);
	}
}
namespace task4
{
	inline bool chkspecial()
	{
		for (int i = 3; i <= n; ++i)
			if (a[i] - a[i - 1] != a[2] - a[1])
				return false;
		return true;
	}
	inline void solve()
	{
		D = D / (a[2] - a[1]);
		if (D == 0 || D == 1)
			return (void)(putchar('0'), putchar('\n'));
		D = (D << 1) - 1, printf("%lld\n", std::max(0ll, n - D));
	}
}
namespace task5
{
	int rb[MAXN];
	inline bool chkspecial()
	{
		for (int i = 1; i <= n; ++i)
			if (a[i] - a[1] <= D && a[n] - a[i] <= D)
				return true;
		return false;
	}
	inline void solve()
	{
		int keypoint = 0;
		for (int i = 1; i <= n; ++i)
			if (a[i] - a[1] <= D && a[n] - a[i] <= D)
			{
				keypoint = i;
				break;
			}
		if (keypoint == 1)
			return (void)(putchar('0'), putchar('\n'));
		for (int s = 1, t = keypoint; s < keypoint; ++s)
		{
			while (t <= n && a[t] - a[s] <= D)
				++t;
			rb[s] = t - 1;
		}
		for (int s = 1, t = keypoint; s < keypoint; ++s)
		{
			while (t <= n && a[t] - a[s] <= D)
				++t;
			if (a[keypoint + 1] - a[s] <= D)
				if (keypoint + 2 <= n && a[keypoint + 2] - a[s] <= D)
					continue;
				else if (s == keypoint - 1)
					ans += n - (keypoint + 1);
				else
					ans += n - rb[keypoint - 1];
			else
				if (s == keypoint - 1)
					continue;
				else
					ans += rb[keypoint - 1] - rb[keypoint - 2];
		}
		printf("%lld\n", ans);
	}
}
namespace task6
{
	int rb[MAXN];
	inline bool chkspecial()
	{
		if (D >= 3e17)
			return true;
		return a[n] - a[1] <= 10 * D;
	}
	inline void solve()
	{
		for (int s = 1, t = 1; s <= n; ++s)
		{
			while (t <= n && a[t] - a[s] <= D)
				++t;
			rb[s] = t - 1;
		}
		for (int i = 1; i < n; ++i)
		{
			if (a[i + 1] - a[i] > D)
				continue;
			int ll = i + 1, rr = rb[i];
			int l1 = i + 1, r1 = rr, l2 = 0, r2 = 0;
			while (ll <= n && rr <= n)
			{
				if (!l1 && !l2)
					break;
				if (!l1)
				{
					int lnew = rb[r2 - 1] + 1, rnew = rb[r2];
					l2 = lnew, r2 = rnew;
					if (l2 > r2)
						break;
					ans += r2 - l2 + 1;
				}
				else
				{
					if (l1 == r1)
					{
						int lnew = rb[r1 - 1] + 1, rnew = rb[r1];
						l1 = lnew, r1 = rnew;
						if (l1 > r1)
							break;
					}
					else
					{
						int lnew = rb[r1 - 2] + 1, rnew = rb[r1 - 1];
						l2 = lnew, r2 = rnew;
						if (l2 > r2)
							l2 = r2 = 0;
						else
							ans += r2 - l2 + 1;
						lnew = rb[r1 - 1] + 1, rnew = rb[r1],
						l1 = lnew, r1 = rnew;
						if (l1 > r1)
							l1 = r1 = 0;
					}
				}
				ll = rr + 1, rr = rb[rr];
			}
		}
		printf("%lld\n", ans);
	}
}
namespace taskmysterious
{
	int lmaxlen[MAXN], rmaxlen[MAXN];
	inline void solve()
	{
		a[n + 1] = 4e18, lmaxlen[n + 1] = rmaxlen[n + 1] = 0;
		int lst = 1;
		for (int i = 2; i <= n; ++i)
			if (a[i] - a[i - 1] <= D && a[i] - a[i - 2] > D)
				lmaxlen[i] = i - lst;
			else
				lmaxlen[i] = 0, lst = i;
		lst = n;
		for (int i = n - 1; i; --i)
			if (a[i + 1] - a[i] <= D && a[i + 2] - a[i] > D)
				rmaxlen[i] = lst - i;
			else
				rmaxlen[i] = 0, lst = i;
		for (int i = 2; i < n - 1; ++i)
		{
			if (a[i + 2] - a[i - 1] <= D)
				continue;
			#define islegal(x) ((x) - a[i - 1] <= D && (x) - a[i - 2] > D && a[i + 2] - (x) <= D && a[i + 3] - (x) > D)
			if (islegal(a[i]) && islegal(a[i + 1]))
				ans += (long long)(lmaxlen[i - 1] + 1) * (long long)(rmaxlen[i + 2] + 1);
			else
			{
				long long tmp = a[i - 2]; a[i - 2] = -4e18;
				if (islegal(a[i]) && islegal(a[i + 1]))
					ans += rmaxlen[i + 2] + 1;
				a[i - 2] = tmp, tmp = a[i + 3], a[i + 3] = 4e18;
				if (islegal(a[i]) && islegal(a[i + 1]))
					ans += lmaxlen[i - 1] + 1;
				a[i + 3] = tmp;
			}
			#undef islegal
		}
		printf("%lld\n", ans);
	}
}
inline void solve()
{
	read(n), read(D), ans = 0;
	for (int i = 1; i <= n; ++i)
		read(a[i]);
	if (n == 1)
		return (void)(putchar('0'), putchar('\n'));
	if (task4::chkspecial())
		return task4::solve();
	if (task5::chkspecial())
		return task5::solve();
	if (task6::chkspecial())
		return task6::solve();
	if (sid <= 10)
		return task3::solve();
	taskmysterious::solve();
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	a[0] = -4e18;
	for (read(sid), read(T); T; --T)
		solve();
	fclose(stdin), fclose(stdout);
	return 0;
}