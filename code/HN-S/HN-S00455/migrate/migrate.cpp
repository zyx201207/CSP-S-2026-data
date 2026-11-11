#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int c,t;
long long d,a[5001];
vector<int> edge[5001];
inline int bfs(int n,int u,int v){
	//cout<<"DEBUG_UV "<<u<<" "<<v<<'\n';
	queue<int> q;
	int dist[5001];
	q.push(u);
	bool vis[5001];
	rep(i,1,n)
		vis[i]=false,dist[i]=1<<30;
	dist[u]=0;
	while(q.size()){
		int x=q.front();
		q.pop();
		if(vis[x])
			continue;
		vis[x]=true;
		for(auto y:edge[x]){
			//cout<<"DEBUG_Y "<<y<<"\n";
			if(vis[y])
				continue;
			q.push(y);
			dist[y]=min(dist[y],dist[x]+1);
			//cout<<"DEBUG "<<y<<" "<<dist[y]<<'\n';
		}
	}
	return dist[v];
}
int js=0;
bool vvv[5001];
inline void dfs(int u,int v,int l,int x){
	//cout<<"DEBUG_DFS "<<u<<" "<<v<<" "<<l<<" "<<x<<"\n";
	if(x>l||(x==l&&u!=v))
		return;
	if(u==v&&x==l){
		js++;
		return;
	}
	vvv[u]=true;
	for(auto y:edge[u]){
		if(vvv[y]||y<u)
			continue;
		dfs(y,v,l,x+1);
	}
	vvv[u]=false;
	return;
}
inline void solve(){
	int n;
	cin>>n>>d;
	rep(i,1,n)
		edge[i].clear();
	rep(i,1,n)
		cin>>a[i];
	rep(i,1,n-1){
		rep(j,i+1,n){
			if(a[j]-a[i]<=d){
				edge[i].push_back(j),edge[j].push_back(i);
			}else
				break;
		}
	}
	long long ans=0;
	rep(i,1,n){
		rep(j,i+1,n){
			js=0;
			int l=bfs(n,i,j);
			//cout<<"DEBUG_IJ "<<i<<" "<<j<<"\n";
			//cout<<"DEBUG_L "<<l<<"\n";
			rep(k,1,n)
				vvv[k]=false;
			dfs(i,j,l,0);
			//cout<<"DEBUG_JS "<<js<<'\n';
			if(js==2)
				ans++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}
