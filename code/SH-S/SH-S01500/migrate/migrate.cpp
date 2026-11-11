#include <bits/stdc++.h>
using namespace std;
long long maxfly,n;
struct node{
	long long x;
	long long locate;
};
long long sum[2000006];
long long state[2000006];
long long cntt;
node q[2000006];
int vis[2000006];
long long test[2000006];
long long ans;
void dfs(long long st,long long from) {
	for (long long i = 1; i <= n; i++) {
		if (i != st && i != from) {
			if (abs(q[st].x - q[i].x) <= maxfly) {
				if (vis[i] == 0) {
					vis[i] = 1;
					test[i] = st;
					dfs(i,st);
				} else {
					if (vis[i] == 1 && from != test[i]) {
						cntt++;
					}
				}
			}
		}
	}
}

int main() {
	freopen ("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c, t;
	cin >> c >> t;
	while (t--) {
		long long cnt = 0;
		cin >> n >> maxfly;
		for (long long j = 1; j <= n; j++) {
			cin >> q[j].x;
		}
		for (long long j = 1; j <= n; j++) {
			memset(vis,0 ,sizeof(vis));
			memset(test,-1,sizeof(test));
			vis[j] = 3;
			dfs(j,31);
		}
		cnt += cntt;
		cout << cnt / 2 << endl;
	}
	return 0;
}
