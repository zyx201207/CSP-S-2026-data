//SN-J01043
#include<bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 7;
int n, m;
int a[N], nxt[N], f[N];
bool jmp[N];
int ans[N];
struct node{
	int to, nxt;
}e[N << 1];
int cnt, head[N];
void add(int u, int v){
	swap(u, v);
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
}
void dfs(int u){
	f[u] = 1;
	for (int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to;
		dfs(v), f[u] += f[v];
	}
	ans[a[u]] += f[u] * jmp[u];
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out","w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--){
		jmp[i] = 1;
		if (nxt[a[i]]){
			add(i, nxt[a[i]]);
			jmp[i] = 0;
		}else if (i < n) add(i, i + 1);
		nxt[a[i]] = i;
	}
	dfs(n);
	for (int i = 1; i <= m; i++) cout << ans[i] << " \n"[i == m];
}
