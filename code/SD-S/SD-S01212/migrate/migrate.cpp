#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#define int long long
using namespace std;
int n,d,a[510],dis[510],cnt[510],vis[510],ans;
vector<int> G[510];
int solve(){
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		G[i].clear();
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				//dis[i][j]=1;
				G[i].push_back(j);
				//G[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		queue<int> q;
		memset(dis,0,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		q.push(i);dis[i]=1;vis[i]=1;
		while(q.size()){
			int u=q.front();q.pop();
			for(auto v:G[u]){
				//if(i==6) cout<<u<<' '<<v<<'\n';
				if(!vis[v]){
					//cout<<u<<' '<<v<<' '<<dis[u]+1<<'\n';
					dis[v]=dis[u]+1;
					vis[v]=1;
					q.push(v);
					cnt[v]++;
				}
				else if(dis[v]==dis[u]+1){
					//cout<<u<<' '<<v<<' '<<dis[u]+1<<'\n';
					cnt[v]++;
				}
			}
		}
		for(int j=1;j<=n;j++){
			//cout<<cnt[j]<<' ';
			if(cnt[j]==2) ans++;
		}//cout<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--) solve();
	return 0;
}
/*
1 1
16 4
-1 1 4 6 7 8 9 11 13 14 16 17 21 25 26 27
1 1
10 3
0 3 6 7 8 9 10 11 14 17
*/

