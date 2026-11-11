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

LL c, n, m, d, q;
LL w[500100];
LL g[1010][1010];
vector<LL> a[20100], t[20100];

void work_11(){
	memset (g, 0x3f, sizeof g);
	
	for (int i = 1;i <= m;i ++)
		read(w[i]), g[i][i] = 0;
	
	for (int i = 1;i <= n;i ++){
		LL k, ax, tx;
		read(k);
		for (int j = 1;j <= k;j ++){
			read(ax);
			read(tx);
			a[i].pb(ax);
			t[i].pb(tx);
		}
		for (int j = 0;j < k;j ++){
			for (int l = j + 1;l < k;l ++){
				g[a[i][j]][a[i][l]] = g[a[i][l]][a[i][j]] = min(g[a[i][l]][a[i][j]], t[i][j] + t[i][l]);
			}
		}
	}
	
//	for (int i = 1;i <= m;i ++){
//		cout << i << " : ";
//		for (int j = 1;j <= m;j ++)
//			cout << g[i][j] << " ";
//		puts(" ");
//	}
//	puts("\n");
	for (int k = 1;k <= m;k ++){
		for (int i = 1;i <= m;i ++){
			for (int j = 1;j <= m;j ++)
				g[i][j] = min(g[i][k] + g[k][j], g[i][j]);
		}
	}
//	for (int i = 1;i <= m;i ++){
//		cout << i << " : ";
//		for (int j = 1;j <= m;j ++)
//			cout << g[i][j] << " ";
//		puts(" ");
//	}
//	puts("\n");
	
	LL x, y;
	for (int i = 1;i <= q;i ++){
		read(x);read(y);
		cout << g[x][y] + w[x] + w[y] << endl;
	}
}

set<LL> way[510];
vector<LL> id[500100];
LL T;
vector<int>G[20010];
bitset<20100> st;
int dis[500100];
int dij(int st, int ed){
	priority_queue<int> q;
	for (int i = 1;i <= m;i ++)
		dis[i] = 0x3f3f3f3f;
	while (!q.empty())q.pop();
	q.push(st);
	dis[st] = 0;
	while (!q.empty()){
		int t = q.top();
		for (int i = 0, v;i < G[t].size();i ++){
			v = G[t][i];
			if (dis[v] > dis[t] + 1){
				dis[v] = dis[t] + 1;
				q.push(v);
				if (v == ed) return dis[ed];
			}
		}
	}
}

void work_15(){
	for (int i = 1;i <= m;i ++)
		read(w[i]);
	LL T;
	for (int i = 1;i <= n;i ++){
		LL k, ax, tx;
		read(k);
		for (int j = 1;j <= k;j ++){
			read(ax);
			read(tx);
			a[i].pb(ax);
			t[i].pb(tx);
		}
		for (int j = 0;j < k;j ++){
			for (int l = 0;l < k;l ++){
				if (l == k) continue;
				G[l].push_back(k);
				G[k].push_back(l);
			}
		}
		T = t[i][1];
	}
	for (int i = 1;i <= q;i ++){
		int x, y;
		read1(x);read1(y);
		dij(x, y);
		cout << dis[y] * T << "\n";
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);read(n);read(m);read(d);read(q);
	if (c <= 11 && m <= 1000){ work_11();return 0;}
	if (c <= 15){ work_15();return 0;}
	
	return 0; 
}
