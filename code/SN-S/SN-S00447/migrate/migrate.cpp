//SN-S00447 陈博煜 西安交通大学附属中学 
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e6 + 5;
long long pos[MAXN], d;
int rlmt[MAXN], llmt[MAXN], dis[MAXN], cnt[MAXN];
bool vis[MAXN];
int c, t, n;

inline long long read(){
	long long num = 0, sign = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
		sign = (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= '0' && ch <= '9')
		num = (num << 1) + (num << 3) + ch - 48,
		ch = getchar();
	return sign > 0 ? num : -num;
}

void dijkstra(int s){
	for(int i = 1; i <= n; i++)
		dis[i] = INF, cnt[i] = 0, vis[i] = false;
	priority_queue<pair<int, int> > pq;
	dis[s] = 0, cnt[s] = 1, pq.push({-dis[s], s});
	while(pq.size()){
		int u = pq.top().second; pq.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int v = llmt[u]; v <= rlmt[u]; v++)
			if(dis[v] > dis[u] + 1)
				dis[v] = dis[u] + 1, cnt[v] = cnt[u],
				pq.push({-dis[v], v});
			else if(dis[v] == dis[u] + 1)
				cnt[v] += cnt[u];
	}
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	while(t--){
		n = read(), d = read();
		for(int i = 1; i <= n; i++) pos[i] = read();
		for(int i = 1; i <= n; i++)
			rlmt[i] = upper_bound(pos + 1, pos + 1 + n, pos[i] + d) - pos - 1,
			llmt[i] = lower_bound(pos + 1, pos + 1 + n, pos[i] - d) - pos;
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			dijkstra(i);
			for(int j = 1; j <= n; j++)
				if(dis[j] < INF && cnt[j] == 2) ans++;
		}
		cout<< ans / 2<< "\n";
	}
	fclose(stdin), fclose(stdout);
	return 0;
}
