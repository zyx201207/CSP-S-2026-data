#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int sk[500010], sh[500010], h[10010], nxt[10010];
int dd[10010], val[500010], cnt = 0, dval[500010];
int pos = 0;
struct point{
	int x, val;
};
point q[50010];

void addedge(int x, int y, int z, int pos)
{
	nxt[pos] = h[x];
	dd[pos] = y;
	val[pos] = z;
	h[x] = pos;
}

int main()
{
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
	{
		cnt++, pos++;
		scanf("%d", sk[i]);
		addedge(0, cnt, sk[i], pos);
	}
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		cnt++:
		while (k--)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			pos++;
			addedge(x, cnt, y, pos);
		}
	}
	while (q--)
	{
		int s, t;
		scanf("%d %d", &s, &t);
		for (int i = h[0]; i != 0; i = nxt[i])
		{
			if (dd[i] == s) ans += val[i];
			if (dd[i] == t) ans += val[i];
		}
		int l = 0, r = 1;
		point ss;
		ss.x = s, ss.val = 0;
		q[++l] = s;
		while (l <= r)
		{
			point u = q[r--]
			for (int i = h[u.x]; i != 0; i = nxt[i])
			{
				if (dval[dd[i]] <= u.val + val[i]) continue;
				point v;
				v.val = u.val + val[i];
				v.x = i;
				if (v.x == t) ans = min(ans, v.val);
				q[++r] = v;
			}
		}
	}
	printf("%d", ans);
	return 0;
}