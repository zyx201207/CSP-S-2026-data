#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 5e2 + 10;
long long C, n, m, D, Q, ans, num, out[N], k[M], a[M][M], d[M][M];
//long long lin1, lin2, lin3, lin4, lin5, L; 
struct node{
	int to;
	long long w;
}t;
vector <node> v[N];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld %lld %lld %lld %lld", &C, &n, &m, &D, &Q);
	for (int i = 1; i <= m; i ++) scanf("%lld", &out[i]);//,lin4++;
	for (int i = 1; i <= n; i ++){
		scanf("%lld", &k[i]);//lin4++;
		int to;long long w;
		for (int j = 1; j <= k[i]; j ++){
			scanf("%d %lld", &to, &w); 
			t.to = i, t.w = w;
			v[to].push_back(t);
			//lin4++;
		}
	}
	memset(a, 0x3f, sizeof a);//lin1+=n*n;
	memset(d, 0x3f, sizeof d);//lin1+=n*n;
	long long u, vv, w;
	for (int i = 1; i <= n; i ++) a[i][i] = 0;//,lin1++;
	for (int i = 1; i <= m; i ++){
		for (int j = 0; j < v[i].size(); j ++){
			for (int k = j + 1; k < v[i].size(); k ++){
				u = v[i][j].to, vv = v[i][k].to, w = v[i][j].w + v[i][k].w;
				a[u][vv] = a[vv][u] = min(w, a[u][vv]);
				//lin1++;
			}
		}
		//L = v[i].size(), lin5 = max(lin5, L);
	}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			d[i][j] = a[i][j];//,lin1++;
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				d[i][j] = d[j][i] = min(d[i][j], d[i][k] + d[j][k]);//,lin2++;
	while (Q --){
		int x, y;
		scanf("%d %d", &x, &y);
		ans = out[x] + out[y], num = 1e18;
		for (int i = 0; i < v[x].size(); i ++){
			for (int j = 0; j < v[y].size(); j ++){
				num = min(num, d[v[x][i].to][v[y][j].to] + v[x][i].w + v[y][j].w);//lin3++;
			}
		}
		ans += num;
		printf("%lld\n", ans);
//		lin3++;
	}
//	cout << lin1 << " " << lin2 << " " << lin3 << " " << lin4 << " " << lin5 << " " << lin1 + lin2 + lin3 + lin4;
	return 0;
}
