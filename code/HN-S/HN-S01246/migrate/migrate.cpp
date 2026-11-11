#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+7;
int c,t,n,m,a[N],dist[N][3],vis[N][3];
vector<int>E[N];
queue<pair<int,int>>q;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=m) E[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[j][0]=dist[j][1]=dist[j][2]=1e18;
				vis[j][0]=vis[j][1]=vis[j][2]=0;
			}
			dist[i][0]=0;
			q.push({i,0});
			while(!q.empty()){
				int u=q.front().first,v=q.front().second;
				q.pop();
				if(vis[u][v]) continue;
				vis[u][v]=1;
				for(auto now:E[u]){
					if(dist[now][0]>dist[u][v]+1){
						dist[now][2]=dist[now][1];
						dist[now][1]=dist[now][0];
						dist[now][0]=dist[u][v]+1;
						q.push({now,0});
					}
					else if(dist[now][1]>dist[u][v]+1){
						dist[now][2]=dist[now][1];
						dist[now][1]=dist[u][v]+1;
						q.push({now,1});
					}
					else if(dist[now][2]>dist[u][v]+1){
						dist[now][2]=dist[u][v]+1;
						q.push({now,2});
					}
				}
			} 
			for(int j=1;j<=n;j++){
				if(dist[j][0]!=1e18&&dist[j][1]!=1e18&&dist[j][0]==dist[j][1]&&dist[j][1]!=dist[j][2]) ans++;
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) E[i].clear();
	}
	return 0;
} 
