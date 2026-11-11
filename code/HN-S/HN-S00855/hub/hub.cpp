#include<bits/stdc++.h>

#define ll long long

int read(){
	int val = 0, ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)){
		val = (val << 3) + (val << 1) + (ch ^ 48);
		ch = getchar();
	}
	return val;
}

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 5;

int c, t;
int n, k;

int head[MAXN], tot;
struct Edge{int to, nxt;}e[MAXN << 1];
void Add(int u, int v){e[++tot] = {v, head[u]}, head[u] = tot;}

int dep[MAXN], mx[MAXN];
int f[MAXN], fa[MAXN];

void init(int u, int pa){
	fa[u] = pa;
	mx[u] = dep[u];
	for(int i = head[u], v; i; i = e[i].nxt){
		v = e[i].to;
		if(v == pa) continue;
		dep[v] = dep[u] + 1;
		init(v, u);
		mx[u] = max(mx[u], mx[v]);
	}
}

vector<int> s[MAXN];
int cm[MAXN];

void dfs(int u, int pa, int lim){
	bool flag = 0;
	for(int i = head[u], v; i; i = e[i].nxt){
		v = e[i].to;
		if(v == pa) continue;
		dfs(v, u, lim);
		f[u] += f[v];
		if(mx[u] - dep[u] > lim){
			flag = 1; 
		}
	}
	if(flag) f[u]++;
//	cout << f[u] << '\n';
}

int res;

void fd(int u, int d){
	res = min(res, max(1, f[u]) + cm[k + 2 * dep[d] - dep[u]]);
	for(int i = head[u], v; i; i = e[i].nxt){
		v = e[i].to;
		if(v == fa[u]) continue;
		fd(v, d);
	}
}

void ins(int u){
	cm[dep[u]] = min(cm[dep[u]], f[u]);
	for(int i = head[u], v; i; i = e[i].nxt){
		v = e[i].to;
		if(v == fa[u]) continue;
		ins(v);
	}
}

int get(int d){
	res = INF;
	for(int i = head[d], v; i; i = e[i].nxt){
		v = e[i].to;
		if(v == fa[d]) continue;
		fd(v, d), ins(v);
//		cout << v << '\n';
	}
//	cout << res << '\n';
	return res;
}

int dfs2(int u, int mxx, int lim){
	int Res = max(1, f[u]);
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to;
		if(v == fa[u]) continue;
//		cout << v << ' ' << dep[v] << '\n';
		if(dep[v] + mxx > lim) continue;
		Res = min(Res, dfs2(v, mxx, lim));
	}
	return Res;
}

int check(int mid){
	dfs(1, 1, mid);
	int ans = n;
	int mxx = 0, mxc;
	for(int i = head[1], v; i; i = e[i].nxt){
		v = e[i].to;
		int mxx = 0;
		for(int j = head[1]; j; j = e[j].nxt){
			if(i == j) continue;
			mxx = max(mxx, mx[e[j].to]);
		}
		if(mxx > mid) continue;
		ans = min(ans, dfs2(v, mxx, mid));
	}
//	cout << ans << '\n';
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= n; j++) cm[j] = INF;
		ans = min(ans, get(i));
	}
	return ans <= k;
}

void Solve(){
	n = read(), k = read();
	for(int i = 1, u, v; i < n; i++){
		u = read(), v = read();
		Add(u, v), Add(v, u);
	}
	init(1, 1);
	int l = 0, r = n, mid, ans = n;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)){
			r = mid - 1;
			ans = mid;
		}else{
			l = mid + 1;
		}
//		cout << '\n';
	}
	cout << ans << '\n';
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	c = read(), t = read();
	while(t--){
		Solve();
	}

	return 0;
}


