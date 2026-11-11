#include <iostream>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define int long long
#define pi pair<int, int>
const int maxn = 5e3 + 5;
int n, d, x[maxn];
vector<int> g[maxn];
int num[maxn], cnt[maxn], vst[maxn];
inline void dijkstra(int st){
	memset(num, 0x3f, sizeof(num));
	memset(vst, 0, sizeof(vst));
	priority_queue<pi, vector<pi>, greater<pi>> q;
	q.push({0, st});
	num[st] = 0;
	
	while(!q.empty()){
		int u = q.top().second; q.pop();
		if(vst[u]) continue;
		
		for(int v : g[u]){
			if(num[v] > num[u] + 1){
				num[v] = num[u] + 1;
				q.push({num[v], v});
			}
		}
	}
}
inline void counting(int st){
	memset(cnt, 0, sizeof(cnt));
	priority_queue<pi, vector<pi>, greater<pi> > q;
	q.push({0, st}); 
	
	while(!q.empty()){
		int u = q.top().second, dis = q.top().first; q.pop();
		if(num[u] == dis) cnt[u]++;
		
		for(int v : g[u]){
			if(dis + 1 > num[v]) continue;
			q.push({dis + 1, v});
		}
	}
}
//int NW = 0;
inline void solve(){
//	NW++;
	
	cin >> n >> d;
	
//	cout << n << ' ' << d << '\n';
	
	for(int i = 1; i <= n; i++) g[i].clear();
	memset(num, 0x3f, sizeof(num));
	memset(vst, 0, sizeof(vst));
	memset(cnt, 0, sizeof(cnt));
	
//	bool flag1 = true;
	for(int i = 1; i <= n; i++){
		cin >> x[i];
//		if(i >= 3 && x[i] - x[i - 1] != x[i - 1] == x[i - 2]) flag1 = false;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			if(abs(x[i] - x[j]) <= d) g[i].push_back(j);
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		dijkstra(i);
		counting(i);
//		printf("i:%d\n", i);
		for(int j = i + 1; j <= n; j++){
			if(cnt[j] == 2) ans++;
//			printf("j:%d, cnt[j]:%d\n", j, cnt[j]);
		}
	}
	
//	printf("NW:%lld\n", NW);
	cout << ans << '\n';
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, T; cin >> c >> T;
	while(T--) solve();
	return 0;
}
/*
0 1
5 3
-3 0 2 3 4
*/

/*
Õû¸ö»î°É2£ºhope the greatest CCF give me 40 points in this question 
*/
