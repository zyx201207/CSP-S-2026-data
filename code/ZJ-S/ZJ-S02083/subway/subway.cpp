#include<bits/stdc++.h>
using namespace std;

const int N = 510, M = 500010;

int testid,n,m,d,q;
int w[M],hd[M],ed,st;
long long cnt,ans = -1;
bool vis[M];
struct Edge{
	int v,nxt,line;
}e[2*M];

int linew[1010][N];

void addedge(int u,int v,int line){
	++cnt;
	e[cnt].v = v, e[cnt].line = line;
	e[cnt].nxt = hd[u];
	hd[u] = cnt;
}

void dfs(int curu, int curt, int curline){
	if(curu == ed){
		long long ft = curt + linew[curu][curline] + w[curu];
		if(ans == -1 || ans > ft) ans = ft;
		return;
	}
	if(ans != -1 && curt > ans) return;
	vis[curu] = 1;
	for(int i = hd[curu];i;i = e[i].nxt){
		int exc = 0;
		if(vis[e[i].v] == 1) continue;
		if(curline != e[i].line){
			exc = exc + linew[curu][curline] + linew[curu][e[i].line];
		}
		dfs(e[i].v,curt + exc,e[i].line);
	}
	vis[curu] = 0;
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> testid >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1,k; i <= n; i++){
		cin >> k;
		int u,tu;
		cin >> u >> tu;
		linew[u][i] = tu;
		for(int j = 2,v,tv; j <= k; j++){
			cin >> v >> tv;
			linew[v][i] = tv;
			addedge(u,v,i);
			addedge(v,u,i);
			u = v;
		}
	}
	while(q--){
		cin >> st >> ed;
		ans = -1;
		for(int i = hd[st];i;i = e[i].nxt){
			dfs(e[i].v,w[st] + linew[st][e[i].line], e[i].line);
		}
		cout << ans << '\n';
	}
	return 0;
}