#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int p[MAXN];
vector<int> g[MAXN];
bool vis[MAXN];
int dep[MAXN];
void init(int n){
	memset(vis,false,sizeof(vis));
	memset(dep,0,sizeof(dep));
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++) g[i].clear();
}
void build(int n,int d){
	for(int i=1;i<=n;i++){
		int far=d+p[i];
		for(int j=i+1;p[j]<=far;j++){
			g[i].push_back(j);
		}
	}
}
bool bfs(int s,int e,int d){
	queue<int> q;
	q.push(s);
	int minn=0x3f3f3f3f,cnt=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(auto v:g[u]){
			if(dep[v]>dep[u]+1){
				dep[v]=dep[u]+1;
				if(minn>dep[v]){
					if(dep[v]==minn){
						cnt++;
					}else{
						cnt=1;
					}
				}
			}
		}
	}
	return cnt==2;
}
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		init(n);
		for(int i=1;i<=n;i++){
			cin>>p[i];
		}
		build(n,d);
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				res+=(int)bfs(i,j,d);
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}