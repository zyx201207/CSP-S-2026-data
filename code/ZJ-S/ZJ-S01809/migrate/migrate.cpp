#include <bits/stdc++.h>
#define int long long
#define N 5050
#define M 90050
using namespace std;
int c, t;
int n, d;
struct state{
	int step;
	int id;
};
//void add(int u, int v){
//	to[++ cnt] = v;
//	nxt[cnt] = h[u];
//	h[u] = cnt;
//}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --){
		int a[N], to[M] = {0}, h[N] = {0}, nxt[M] = {0}, cnt = 0;
		int res = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i ++){
			cin >> a[i];
		}
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j < i;j ++){
				if(abs(a[i] - a[j]) > d) continue;
				to[++ cnt] = j;
				nxt[cnt] = h[i];
				h[i] = cnt;
				to[++ cnt] = i;
				nxt[cnt] = h[j];
				h[j] = cnt;
			}
		}
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j < i;j ++){
				int minn = 1e18, heyiwei = 0, best[N]; 
				// heyiwei means the number of methods to get the S.P.
				queue<state> q;
				state tmp;tmp.id = i;tmp.step = 0;
				q.push(tmp);
				memset(best, 0x3f, sizeof(best));
				while(!q.empty()){
					int now = q.front().id, steps = q.front().step;
					q.pop();
					best[now] = steps;
					if(steps > minn) continue;
//					cout << now << " " << steps << endl;
					if(now == j){
						if(steps < minn){
							minn = steps;
							heyiwei = 1;
						}else if(steps == minn){
							heyiwei ++;
						}
						continue;
					}
					for(int p = h[now];p;p = nxt[p]){
						int v = to[p];
						if(steps < best[v]){
							tmp.id = v;
							tmp.step = steps + 1;
							q.push(tmp);
//							cout << now << "->>>>>" << v << " " << steps << endl;
						}
					}
				}
				if(heyiwei == 2) res ++;
			}
		}
		cout << res << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
