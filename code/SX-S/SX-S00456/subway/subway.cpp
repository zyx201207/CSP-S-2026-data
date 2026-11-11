#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 1010;
long long c, n, m, d, q, p[M][M], ev[M], v[M][M], w[N], a[N], b, x[N], y, ax, ay, az;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
//	if(c>=7 && c<=11)
//	{
//		for(int i=1;i<=m;i++)
//			scanf("%lld",w+i);
//		for(int i=1;i<=n;i++)
//		{
//			scanf("%lld",&a);
//			if(a==1)
//			{
//				scanf("%lld%lld",&a,&b);
//				continue;
//			}
//			scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
//			p[a][x]=b+y;
//			p[x][a]=b+y;
//			qe[a].push(x);
//			qe[x].push(a);
//		}
//	}
	for (int i = 1; i <= m; i++)
		scanf("%lld", w + i);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &b);
		for (int j = 1; j <= b; j++)
			scanf("%lld%lld", a + j, x + j);
		for (int j = 1; j <= b; j++) {
			for (int re = 1; re <= b; re++) {
				if (j != re && (!p[a[j]][a[re]] || p[a[j]][a[re]] > x[j] + x[re])) {
					p[a[j]][a[re]] = x[j] + x[re];
					p[a[re]][a[j]] = x[j] + x[re];
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		scanf("%lld%lld", &b, &y);
		for (int j = 1; j <= m; j++) {
			for (int kl = 1; kl <= m; kl++)
				v[j][kl] = p[j][kl];
		}
		memset(ev, 0, sizeof(ev));
		ev[b] = 1;
		for (int po = 1; po < m - 1; po++) {
			ax = 0;
			for (int j = 1; j <= m; j++) {
				if (ev[j])
					continue;
				if (!ax || (v[b][j] < v[b][ax] && v[b][j]))
					ax = j;
			}
			if (!ax)
				break;
			ev[ax] = 1;
			for (int j = 1; j <= m; j++) {
				if (ev[j])
					continue;
				if (v[ax][j]) {
					if (v[b][j]) {
						v[b][j] = min(v[b][j], v[b][ax] + v[ax][j]);
						v[j][b] = v[b][j];
					} else {
						v[b][j] = v[b][ax] + v[ax][j];
						v[j][b] = v[b][j];
					}
				}
			}
		}
		printf("%lld\n", v[b][y] + w[b] + w[y]);
	}
	return 0;

}
//16:35:37
//还是回来了，第四题看完人已经通透了……
//话说这一届打完就可以写退役记了，我常常追忆过去……
//暴力不好写，还是写A
//不兑………………暴…………力………………