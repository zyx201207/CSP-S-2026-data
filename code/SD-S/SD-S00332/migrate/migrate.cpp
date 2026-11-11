#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,x[2000005];
vector<int>g[2000005];
int dis[2000005];
bool vis[2000005];
int cnt[2000005],ans;
void bfs(int s){
	queue<int>q;
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<g[now].size();i++){
			if(vis[g[now][i]]){
				//if(dis[g[now][i]]==dis[now]+1)cnt[g[now][i]]++;
				continue;
			}
			vis[g[now][i]]=1;
			q.push(g[now][i]);
			dis[g[now][i]]=dis[now]+1; 
		}
	}
}
void dfs(int s,int tot){
	if(tot!=0&&tot==dis[s])cnt[s]++;
	if(tot>dis[s])return;
	for(int i=0;i<g[s].size();i++){
		if(vis[g[s][i]])continue;
		vis[g[s][i]]=1;
		dfs(g[s][i],tot+1);
		vis[g[s][i]]=0;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					g[i].push_back(j);
					//g[j].push_back(i);
				}
				else break;
			}
			//g[i].push_back(i+1);
			//g[i+1].push_back(i);
		}
		for(int i=1;i<n;i++){
			memset(cnt,0,sizeof(cnt));
			memset(vis,0,sizeof(vis));
			bfs(i);
			memset(vis,0,sizeof(vis));
			vis[i]=1;
			dfs(i,0);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
				//cout<<i<<" "<<j<<":"<<cnt[j]<<'\n';
			}
		}
		//cout<<'\n';
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13
*/
