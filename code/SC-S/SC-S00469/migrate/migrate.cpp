#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int ,int> > > q;
vector<int> edge[1000050];
int c,t,n,d;
pair<int,int>dist[5050][5005];
long long a[1000050];
int dfs(int x,int end,int st,int p){
	int res=0;
	if(st==p){
		if(x==end){
			++res;
		}
		return res;
	}
	for(int i=0;i<edge[x].size();i++){
		res+=dfs(edge[x][i],end,st+1,p);
	}
	return res;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]={0,0};
			}
			edge[i].clear();
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					edge[i].push_back(j);
					edge[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					dist[i][j]={1e8,1e8};
				}
			}
			q.push({0,i});
			while(!q.empty()){
				int u=q.top().second,w=q.top().first;
				q.pop();
				if(w!=dist[i][u].first ){
					continue;
				}
				for(int j=0;j<edge[u].size();j++){
					int v=edge[u][j];
					if(dist[i][v].first>dist[i][u].first+1){
						dist[i][v].first=dist[i][u].first+1;
						dist[i][v].second=1;
						q.push({dist[i][v].first ,v});
					}else if(dist[i][v].first ==dist[u][v].first+1){
						dist[i][v].second++;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dfs(i,j,0,dist[i][j].first )==2){
					++ans;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}