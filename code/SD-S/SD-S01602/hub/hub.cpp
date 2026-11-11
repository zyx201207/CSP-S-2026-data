#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define pb push_back

inline void read(LL &x){
	x = 0;int f = 1, c = getchar();
	while (c < 48 || c > 57){
		if (c == '-') f = -1;
		c = getchar(); 
	}
	while (c >= 48 && c <= 57){
		x = (x << 3) + (x << 1) + (c & 15);
		c = getchar();
	}
	x *= f;
}
inline void read1(int &x){
	x = 0;int f = 1, c = getchar();
	while (c < 48 || c > 57){
		if (c == '-') f = -1;
		c = getchar(); 
	}
	while (c >= 48 && c <= 57){
		x = (x << 3) + (x << 1) + (c & 15);
		c = getchar();
	}
	x *= f;
}

#define pii pair<int,int>
#define fi first
#define se second

vector<int> g[4010];
pii e[4010];
int n, k;

void del(pii x){
	int u = x.fi;
	int v = x.se;
	for (int i = 0;i < g[u].size();i ++){
		if (g[u][i] == v){
			swap(g[u][i], g[u][g[u].size() - 1]);
			g[u][g[u].size() - 1] = -1;
			break;
		}
	}
	for (int i = 0;i < g[v].size();i ++){
		if (g[v][i] == u){
			swap(g[v][i], g[v][g[v].size() - 1]);
			g[v][g[v].size() - 1] = -1;
			break;
		}
	}
}

void add(pii x){
	int u = x.fi, v = x.se;
	g[u][g[u].size() - 1] = v;
	g[v][g[v].size() - 1] = u;
}

int dep[4010], fa[4010];

int dfs1(int u, int f){
	fa[u] = f;
	dep[u] = dep[f] + 1;
	int maxn = -0x3f3f3f3f, id = u;
	for (int i = 0, v;i < g[u].size();i ++){
		v = g[u][i];
		if (v == f || v == -1) continue;
		int v_id = dfs1(v, u);
		if (dep[v_id] > maxn){
			maxn = dep[v_id];
			id = v_id;
		}
	}
	return id;
}

int find(int x){
	int st = dfs1(x, 0);
	int ed = dfs1(st, 0);
//	cout << x << " " << st << " " << ed << endl;
	int now = ed, mid = dep[st] + dep[ed] >> 1;
	while (dep[now] > mid) now = fa[now];
	return now;
}
vector<int> res;

void dfs(int u, int f){
	dep[u] = dep[f] + 1;
	int son_size = 0;
	for (int i = 0, v;i < g[u].size();i ++){
		v = g[u][i];
		if (v == f || v == -1) continue;
		dfs(v, u);
		son_size ++;
	}
	if (f != 0 && !son_size) res.pb(dep[u] - 1);
}

void work(){
	read1(n);read1(k);
	for (int i = 1;i <= n;i ++)
		g[i].clear();
	
	for (int i = 1, u, v;i < n;i ++){
		read1(u);read1(v);
		e[i] = {u, v};
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int root1, root2;
	int ans = 0x3f3f3f3f;
	
	for (int i = 1;i < n;i ++){
		res.clear();
		del(e[i]);
//		cout << i << " " << e[i].fi << " " << e[i].se << endl;
		root1 = find(e[i].fi);
		root2 = find(e[i].se);
//		cout << root1 << " " << root2 << endl;
//		puts(" ");
		dfs(root1, 0);
		dfs(root2, 0);
//		for (int i = 1;i <= n;i ++)
//			printf ("%d : %d\n", i, dep[i]);
		int kk = k - 2, flag = 0x3f3f3f3f;
		sort(res.begin(), res.end());
//		cout << res.size() << endl;
//		for (int j = 0;j < res.size();j ++)
//			cout << res[j] << " ";
//		puts("\n");
		for (int j = res.size() - 2;~j;j --){
			LL x = (res[j + 1] - res[j]) * (res.size() - j - 1);
			if (kk >= x){
				kk -= x;
				flag = res[j];
			}
			else break;
		}
		ans = min(ans, flag);
		add(e[i]);
	}
	cout << ans << endl;
	
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c, t;
	read1(c);read1(t);
	while (t --){
		work();
	}
	
	return 0; 
}/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
