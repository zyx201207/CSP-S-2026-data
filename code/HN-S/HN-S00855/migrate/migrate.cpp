#include<bits/stdc++.h>

#define ll long long

ll read(){
	ll val = 0, ch = getchar(), b = 1;
	while(!isdigit(ch)){
		if(ch == '-') b = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		val = (val << 3) + (val << 1) + (ch ^ 48);
		ch = getchar();
	}
	return val * b;
}

using namespace std;

const int MOD = 1e9 + 7;

void Add(int &x, int y){x += y; if(x >= MOD) x -= MOD;}
void Sub(int &x, int y){x -= y; if(x < 0) x += MOD;}

const int MAXN = 2e6 + 5;
const int INF = 0x3f3f3f3f;

int c, t;
ll n, d;
ll a[MAXN];
ll dis[MAXN], f[MAXN];

ll ans;

int ind[MAXN];
int q[MAXN], head, tail;
vector<int> G[MAXN];

int Kahn(int s){
	head = 1, tail = 0;
	for(int i = s; i <= n; i++){
		G[i].clear(), ind[i] = 0;
		dis[i] = INF, f[i] = 0;
	}
	for(int i = s; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(a[j] - a[i] > d) break;
			G[i].push_back(j), ind[j]++;
		}
	}
	q[++tail] = s; dis[s] = 0, f[s] = 1;
	while(head <= tail){
		int u = q[head++];
		for(int v : G[u]){
			if(dis[u] + 1 < dis[v]){
				dis[v] = dis[u] + 1;
				f[v] = f[u];
			}else if(dis[u] + 1 == dis[v]){
				f[v] += f[u];
			}
			if(--ind[v] == 0){
				q[++tail] = v;
			}
		}
	}
	for(int i = s; i <= n; i++) ans += f[i] == 2;
}

void Solve(){
	n = read(), d = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();
	}
	ans = 0;
	for(int i = 1; i <= n; i++){
		Kahn(i);
	}
	cout << ans << '\n';
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	while(t--){
		Solve();
	}

	return 0;
}

