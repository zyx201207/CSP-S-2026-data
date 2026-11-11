#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
const int INF=1e9;
vector<int> g[N];
int vis[N],_vis[N];

void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans=INF;
	for(int s=0;s<(1<<n);s++){
		int pc=__builtin_popcount(s);
		if(pc!=k) continue;
		int cnt=0;
		for(int i=i;i<=n;i++){
			if((s>>(i-1))&1) _vis[i]=vis[i]=1;
		}
		for(int i=1;i<=n;i++){
			if(vis[i]){
				queue<int> q;
				q.push(i);
				vis[i]=0;
				while(q.size()){
					int u=q.front();
					q.pop();
					for(auto v:g[u]){
						if(vis[v]){
							q.push(v);
							vis[v]=0;
						}
					} 
				}
				cnt++;
			}
		}
		if(cnt>2) continue;
		int mx=0;
		for(int i=1;i<=n;i++){
			if(_vis[i]) continue;
			int dist=INF;
			int tmp[N]={};
			queue<pair<int,int>> q;
			q.push({i,0});
			tmp[i]=1;
			while(q.size()){
				int u=q.front().first;
				tmp[u]=1;
				int w=q.front().second;
				q.pop();
				if(_vis[u]){
					dist=min(dist,w);					
				}
				for(auto v:g[u]){
					if(tmp[v]) continue;
					q.push({v,w+1});
				}
			}
			mx=max(mx,dist);
		}
		ans=min(ans,mx);
	}
	printf("%d\n",ans);
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

