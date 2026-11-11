#include<bits/stdc++.h>
#define int long long
using namespace std;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while('0' > ch || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch & 15);
		ch = getchar();
	}
	return x * f;
} 
const int N = 2e6 + 5;
int C, T, n, d, a[N], dis[N], Cnt[N], Add[N];
queue<int> que;
vector<int> vt[N]; 

signed main() {
//	freopen("t.err", "w", stderr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	cin >> C >> T;
	while(T --) {
		cin >> n >> d;
		for(int i = 1;i <= n;++ i) {
			cin >> a[i];
			vt[i].clear();
		}
		int Tmp = 1;
		a[n + 1] = 0x3f3f3f3f3f3f3f3f;
		for(int i = 1;i <= n;++ i) {
			while(Tmp < n && a[Tmp] - a[i] <= d) ++ Tmp;
			if(a[Tmp] - a[i] > d) -- Tmp;
			for(int j = i + 1;j <= Tmp;++ j) {
				vt[i].push_back(j);
//				cerr << i << " -> " << j << '\n';
			}
		}
		int res = 0;
		for(int i = 1;i <= n;++ i) {
			for(int j = 1;j <= n;++ j) {dis[j] = n + 10;Cnt[j] = 0;Add[j] = 0;}
			while(!que.empty()) que.pop();
			que.push(i);
			dis[i] = 0;
			Cnt[i] = 0;
			Add[i] = 1;
			while(!que.empty()) {
				int u = que.front();
				que.pop();
				Cnt[u] += Add[u];
				for(int it : vt[u]) {
					if(dis[it] > dis[u] + 1) {
						dis[it] = dis[u] + 1;
						Cnt[it] = 0;
						Add[it] = Cnt[u];
						que.push(it);
					} else if(dis[it] == dis[u] + 1) {
						Add[it] += Add[u];
						que.push(it);
					}
				}
				Add[u] = 0;
			}
			for(int j = 1;j <= n;++ j) {
//				if(Cnt[j] == 2) cerr << i << ' ' << j << "answer!!!\n";
				res += (Cnt[j] == 2);
			}
		}
		cout << res << '\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
