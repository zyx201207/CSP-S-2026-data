#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 2e6 + 5, INF = (1 << 30);
int C, T;
int n, k;
int cntedge, h[MAXN], e[MAXN << 1], nxt[MAXN << 1];
int d[MAXN];
bool v[MAXN], in[MAXN];
int ans;
inline void addedge(int u, int v){
	e[++cntedge] = v;
	nxt[cntedge] = h[u];
	h[u] = cntedge;
}
void dfscon(int x){
	v[x] = 1;
	for(int i = h[x];i;i = nxt[i]){
		if(in[e[i]] && !v[e[i]]){
			dfscon(e[i]);
		}
	}
}
bool check(){
	memset(v, 0, sizeof(v));
	int cntblk = 0;
	for(int i = 1;i <= n;i++){
		if(!in[i])continue;
		if(!v[i]){
			cntblk++;
			if(cntblk > 2)return 0;
			dfscon(i);
		}
	}
	return cntblk == 1 || cntblk == 2;
}
int calc(){
	int res = 0;
	memset(d, 0x3f, sizeof(d));
	queue<int> q;
	for(int i = 1;i <= n;i++){
		if(in[i]){
			d[i] = 0;
			q.push(i);
		}
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i = h[x];i;i = nxt[i]){
			if(d[e[i]] > d[x] + 1){
				d[e[i]] = d[x] + 1;
				q.push(e[i]);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		res = max(res, d[i]);
	}
	return res;
}
void dfscol(int m, int lst){
	if(m == 0){
		if(check())ans = min(calc(), ans);
		return;
	}
	for(int i = lst + 1;i <= n;i++){
		in[i] = 1;
		dfscol(m - 1, i);
		in[i] = 0;
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &C, &T);
	while(T--){
		cntedge = 0;
		memset(h, 0, sizeof(h));
		memset(e, 0, sizeof(e));
		memset(nxt, 0, sizeof(nxt));
		ans = INF;
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n - 1;i++){
			int st, ed;
			scanf("%d%d", &st, &ed);
			addedge(st, ed);
			addedge(ed, st);
		}
		dfscol(k, 0);
		printf("%d\n", ans);
	}
	return 0;
}
