#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=505;
const int MAXM=5e5+5;
int c,n,m,d,q;
struct station{
	int w;
	int t[MAXN];
}sta[MAXM];
vector<int> g[MAXN];
void build(vector<int> way){
	int len=way.size()-1;
	for(int i=1;i<len;i++){
		g[way[i]].push_back(way[i-1]);
		g[way[i-1]].push_back(way[i]);
	}
}
bool vis[MAXM];
int dist[MAXM];
void dfs(int s,int e){
	queue<int> q;
	q.push(s);
	dist[s]=0;
	while(!q.empty()){
		int u=q.front();
		if(vis[u])continue;
		vis[u]=true;
		for(auto v:g[u]){
			int w=0;
			if(g[u].size()>2){
				w=sta[u].t[]
			}
		}
	}
}
signed main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>sta[i].w;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		vector<int> way;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			way.push_back(a);
			sta[a].t[i]=t;
		}
		build(way);
	}
	while(q--){
		
	}
}
/*
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCFf**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCFf**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCFf**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCFf**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCFf**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCFf**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCFf**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCFf**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCFf**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCFf**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCFf**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCFf**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCFf**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
f**king CCF
*/