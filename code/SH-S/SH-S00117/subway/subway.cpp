#include <iostream>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define int long long
#define pi pair<int, int>
const int maxn = 505;
const int maxm = 1005;
const int inf = 4e18;
int c, n, m, d, q;
int w[maxm], k[maxn];
int a[maxn][maxm], t[maxn][maxm];
struct stion{
	int id; // 代表是第几个站台
	int num; // 代表是第几个地铁
	int val; // 代表边权 
};
vector<stion> g[maxm * 20];
inline int trans(stion nd){
	return (nd.id - 1) * (d + 1) + nd.num;
}
inline stion re_trans(int x){
	stion nd = {x / (d + 1) + 1, x % (d + 1), 0ll};
	return nd;
	// 注意，边权是没有传回去的，要自己修改 
}
int dis[maxm * 20], vst[maxm * 20];
int ans[maxm][maxm];
inline void dijkstra(int st){
	memset(dis, 0x3f, sizeof(dis));
	memset(vst, 0ll, sizeof(vst));
	priority_queue<pi, vector<pi>, greater<pi> > p;
	stion fst = {st, 0ll, 0ll};
	p.push({0ll, trans(fst)});
	dis[trans(fst)] = 0ll;
	
//	if(st == 186) printf("st:%lld\n", st);
	
	while(!p.empty()){
		pi u = p.top(); p.pop();
		
		stion nw = re_trans(u.second);
//		if(st == 186) printf("\tnw_station:%lld, num_rail:%lld\n", nw.id, nw.num);
		
		int x = u.second;
		if(vst[x]) continue;
		vst[x] = 1;
		
		for(stion gt : g[x]){
			int v = trans(gt);
			if(dis[v] > dis[x] + gt.val){
				dis[v] = dis[x] + gt.val;
				p.push({dis[v], v});
			}
			
//			if(st == 186) printf("\t\t goto_station:%lld, goto_rail:%lld, need_time:%lld, dis[goto]:%lld\n", gt.id, gt.num, gt.val, dis[v]);
		}
	}
	
	for(int i = 1; i <= m; i++){
		stion tp = {i, 0ll, 0ll};
		ans[st][i] = dis[trans(tp)];
		
//		if(st == 186) printf("\ti:%lld, dis[goto]:%lld\n", i, dis[trans(tp)]);
	}
}
signed main(){
	// there is still something wrong !!!!! 
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
		}
		
		for(int j = 1; j <= k[i] - 1; j++){
			stion frm = {a[i][j], i, 0ll}, wnt = {a[i][j + 1], i, 0ll};
			g[trans(frm)].push_back(wnt);
			g[trans(wnt)].push_back(frm);
		}
		
		for(int j = 1; j <= k[i]; j++){
			stion zt = {a[i][j], 0ll, t[i][j]}, dtz = {a[i][j], i, t[i][j]};
			g[trans(zt)].push_back(dtz), g[trans(dtz)].push_back(zt);
		}
	}
	
	/* 调试生图数组g */ 
	
//	for(int i = 1; i <= m; i++){
//		for(int j = 0ll; j <= d; j++){
//			stion nd = {i, j, 0ll};
//			if(g[trans(nd)].size() == 0ll) continue;
//			printf("i:%lld, j:%lld\n", i, j);
//			
//			for(stion v : g[trans(nd)]){
//				printf("\tgo_station:%lld, subway_num:%lld, path_time:%lld\n", v.id, v.num, v.val);
//			}
//		}
//	}
	
	// 图没有问题 
	
	/* 结束调试生图数组g */
	
	for(int i = 1; i <= m; i++){
		dijkstra(i);
	}
	
	while(q--){
		int x, y; cin >> x >> y;
		cout << ans[x][y] + w[x] + w[y] << '\n';
		
//		if(x == 186) printf("w[x]:%d, w[y]:%d\n", w[x], w[y]);
	}
	return 0ll;
}
/*
0ll 2 5 20 2 
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/ 

/*
整个活吧：hope the greatest CCF give me 44 points in this question 
*/
