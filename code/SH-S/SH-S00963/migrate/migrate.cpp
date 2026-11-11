#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
const int INF=1e9;

vector<int> g[N]; 
ll pos[N];
int dis[5005][5005];
int cnt[5005][5005];

void solve(){
	ll n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>pos[i];
	}
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(pos[j]-pos[i]<=d) g[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
	}
	for(int s=1;s<=n;s++){
		dis[s][s]=0;
		//int vis[N]={};
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
		q.push({0,s});
		//vis[s]=1;
		while(q.size()){
			int u=q.top().second;
			q.pop();
			//vis[u]=1;
			for(auto it:g[u]){
				int v=it;
				//if(vis[v]) continue;
				if(dis[s][v]==dis[s][u]+1) cnt[s][v]++;
				else if(dis[s][v]>dis[s][u]+1){
					dis[s][v]=dis[s][u]+1;
					cnt[s][v]=1;
					q.push({dis[s][v],v});
				}
			}
		}
	} 
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dis[i][j]==INF) continue;
			if(cnt[i][j]==2) ans++;
		}
	}
	printf("%d\n",ans);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
