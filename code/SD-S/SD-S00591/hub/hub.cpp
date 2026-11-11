#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
namespace Rain_Cloud{
	const int N=1e5+7;
	int c,t;
	vector<int>g[N];
	int n,k;
	int col[N];
	int dist[N];
	int level[N];
	int vis[N];
	void dfs(int now){
		vis[now]=1;
		for(auto wx:g[now]){
			if(vis[wx]==0&&col[wx]) dfs(wx);
		}
	}
	void bfs(){
		queue<int>Q;
		for(int i=1;i<=n;i++){
			if(col[i]){
				Q.push(i);
				level[i]=0;
			}else level[i]=-1;
		}
		while(!Q.empty()){
			int now=Q.front();
			Q.pop();
			for(auto wx:g[now]){
				if(level[wx]==-1){
					level[wx]=level[now]+1;
					Q.push(wx);
				}
			}
		}
	}
	void duoce1(){
		int minn=0x3f3f3f3f;
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int now=0;now<(1<<n);now++){
			for(int i=1;i<=n;i++){
				vis[i]=0;
				col[i]=((now>>(i-1))&1);
			}
			int tot=0,cnt=0;
			for(int i=1;i<=n;i++){
				cnt=cnt+col[i];
			}
			if(cnt!=k){
				continue;
			}
			for(int i=1;i<=n;i++){
				if(col[i]&&vis[i]==0){
					tot++;
					dfs(i);
				}
			}
			if(tot>2){
				continue;
			} 
			bfs();
			int maxn=0;
			for(int i=1;i<=n;i++){
				maxn=max(maxn,level[i]);
			}
			minn=min(minn,maxn);
		}
		cout<<minn<<'\n';
	}
	void duoce2(){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++) col[i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k==n){
			cout<<0<<'\n';
			return ;
		}else{
			if(k>=n/2){
				cout<<1<<'\n';
			}else{
				int blk=(n/2-k)/4;
				if((n/2-k)%4) blk++;
				cout<<blk+1<<'\n';
			}
		}
	}
	void RainS(){
		cin>>c>>t;
		if(c<=3){
			while(t--) duoce1();
		}else if(c==13||c==14){
			while(t--) duoce2();
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Rain_Cloud::RainS();
	return 0;
}
