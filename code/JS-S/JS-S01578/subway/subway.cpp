#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5, N = 501;
int qread(){
	bool f = 0;
	int x = 0;
	char op = 0;
	while(op < '0'||op > '9'){
		if(op == '-')   f = 1;
		op = getchar();
	}
	if(f)   while(op>='0'&&op<='9'){
		x = x*10 + '0' - op;
		op =getchar();
	}
	else while(op>='0'&&op<='9'){
		x = x*10 + op -'0';
		op = getchar();
	}
	return x;
}
int c, n, m, d, q, k;
int s, e;
int w[M];
struct node{
	int a, w;
};
vector<node> tl[M], edg[N], gt[N];
int vis[N];
void bfs(int st){
	memset(vis, 0x3f, n * sizeof(int));
	queue<node>qe;
	qe.push({st, 0});
	vis[st] = 0;
	while(!qe.empty()){
		node f = qe.front();
		qe.pop();
		for(auto v : edg[f.a]){
			if(vis[v.a] > f.w + v.w){
				qe.push({v.a, f.w + v.w});
				vis[v.a] = f.w + v.w;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = qread(), n = qread(), m = qread(), d = qread(), q = qread();
	for(int i = 0; i < m; i++)  w[i] = qread();
	for(int i = 0; i < n; i++){
		k = qread();
		for(int j = 0; j < k; j++){
			int a = qread(), t = qread();
			tl[a].push_back({i, t});
			gt[i].push_back({a, t});
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < tl[i].size(); j++){
			for(int ii = j + 1; ii < tl[i].size(); ii++){
				edg[tl[i][j].a].push_back({tl[i][ii].a, tl[i][j].w + tl[i][ii].w});
				edg[tl[i][ii].a].push_back({tl[i][j].a, tl[i][j].w + tl[i][ii].w});
			}
		}
	}
	for(int i = 0; i < q; i++){
		s = qread(), e = qread();
		int ans = 0x7fffffff, ts, te;
		for(auto u: tl[s]){
			bfs(u.a);
			for(int j = 0; j < gt[u.a].size(); j++){
				if(gt[u.a][j].a == s){
					ts = gt[u.a][j].w;
					break;
				}
			}
			for(auto v: tl[e]){
				for(int j = 0; j <gt[v.a].size(); j++){
					if(gt[v.a][j].a == e){
						te = gt[v.a][j].w;
						break;
					}
				}
				ans = min(ans, vis[v.a]+ts+te);
			}
		}
		cout << ans + w[s-1] + w[e-1]<<'\n';
	}
	return 0;
}