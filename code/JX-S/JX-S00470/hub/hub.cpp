
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define fi first
#define se second
#define pb push_back

#define OI freopen("hub.in","r",stdin),freopen("hub.out","w",stdout)

using namespace std;

struct Edge{
	int to,next;
}edge[4010];

int cnt,head[2010];
int vis[2010];
int dist[2010];

void add(int from,int to){
	edge[cnt].to = to;
	edge[cnt].next = head[from];
	head[from] = cnt ++;
}

int n,m,fans = 0x3f3f3f3f;

void dfs2(int u,int fa){
	if(vis[u]) dist[u] = 0;
	else dist[u] = dist[fa] + 1;
	for(int i = head[u];i != -1;i = edge[i].next){
		int v = edge[i].to;
		if(v == fa) continue;
		
		dfs2(v,u);
		
		dist[u] = min(dist[u],dist[v] + 1);
	}
}

void dfs(int pos,int num,int chnum){
	if(num > 2) return;
	
	if(chnum == m){
		memset(dist,0x3f3f3f3f,sizeof dist);
		dfs2(1,0);
		int ans = 0;
		for(int i = 1;i <= n;i ++){
			ans = max(ans,dist[i]);
		}
		if(fans > ans){
			fans = ans;
		}
		return;
	}
	if(pos > n) return;
	
	//choose
	vis[pos] = 1;
	bool ok = 0;
	for(int i = head[pos];i != -1;i = edge[i].next){
		if(vis[edge[i].to]){
			ok = 1;
			break;
		}
	}
	if(ok) dfs(pos + 1,num,chnum + 1);
	else dfs(pos + 1,num + 1,chnum + 1);
	
	vis[pos] = 0;
	
	dfs(pos + 1,num,chnum);
}

void solve(){
	memset(head,-1,sizeof head);
	memset(vis,0,sizeof vis);
	memset(edge,0,sizeof edge);
	cnt = 0;
	cin >> n >> m ;
	for(int i = 1;i < n;i ++){
		int a,b;
		cin >> a >> b;
		add(a,b),add(b,a);
	}
	dfs(1,0,0);
	cout << fans << '\n';
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	OI;
	int c,T;
	cin >> c >> T;
	while(T --){
		fans = 0x3f3f3f3f;
		solve();
	}
	return 0;
}


