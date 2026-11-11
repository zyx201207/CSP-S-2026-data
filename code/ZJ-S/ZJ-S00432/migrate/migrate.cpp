#include <bits/stdc++.h>
using namespace std;
int c, T, n;
long long lis[2000010], d, fa[2000010], sz[2000010], ans;
int cnt;
//bool v[2000010];
// d, ans,
int getfa(int x){
	if (fa[x] == x) return x;
	fa[x] = getfa(fa[x]);
	return fa[x];
}
stack<pair<int, int> > st;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (T --){
		scanf("%d%lld", &n, &d);
		for (int i = 1;i <= n;i ++){
			scanf("%lld", &lis[i]);
			fa[i] = i;
			sz[i] = 1;
		}
//		for (int i = 1;i <= n;i ++){
//			int pos = upper_bound(lis + 1, lis + 1 + n, lis[i] + d) - lis;
//			for (int j = i + 1;j < pos;j ++){
//				if (f[j] == f[i] + 1) nm[j] ++;
//				else{
//					if (f[j] > f[i] + 1){
//						nm[j] = 0;
//						f[j] = f[i] + 1;
//					}
//					else{
//						 	
//					}
//				}
//			}
//			if (nm[i] == 2) cnt ++;
//		}
//			fa[i] = i;
//			sz[i] = 1;
//		}
////		for (int i = 2;i <= n;i ++){
////			if (i == 2 || (lis[i] - lis[i - 2] > d && lis[i] - lis[i - 1] <= d)){
////				bef[i] = bef[i - 1] + 1;
////			}
////		}
////		for (int i = n - 1;i >= 1;i --){
////			if (i == n - 1 || (lis[i + 2] - lis[i] > d && lis[i + 1] - lis[i] <= d)){
////				aft[i] = aft[i + 1] + 1;
////			}
////		}
////		cout<<bef[1]<<aft[4];
		int i = 1, j = 4, pj = 0, cur = 0;
		ans = 0;
		while (j <= n){
			if (lis[j] - lis[i] <= d) j ++;
			else{
				int poa = upper_bound(lis + 1, lis + 1 + n, lis[i] + d) - lis;
				int pob = lower_bound(lis + 1, lis + 1 + n, lis[j] - d) - lis;
//				cout<<poa<<pob;
				if (poa - pob == 2){
					st.push({i, j});
					i ++;
				}
				else{
					if (poa - pob >= 3){
						j ++;
					}
					else {
						if (poa - pob == 1){
							fa[getfa(j)] = getfa(i);
							sz[getfa(i)] += sz[getfa(j)];
							fa[getfa(pob)] = getfa(i);
							sz[getfa(i)] += sz[getfa(pob)];
						}
						i ++;
					}
				}
			}
		}
		while (!st.empty()){
			ans += sz[getfa(st.top().first)] * sz[getfa(st.top().second)];
			st.pop();
		}
		printf("%d\n", ans);
	}
	return 0;
}
