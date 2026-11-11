#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int sub[500005];
vector<int> v[500005];
vector<long long> w[500005];
vector<int> rd[505];
bool vis[505][505];
long long l[505][505],dis[505][505];
void bfs(int s){
	priority_queue< pair<long long,int> > q;
	q.push({0,s});
	while(!q.empty()){
		pair<int,int> tp=q.top();
		int x=tp.second;
		q.pop();
		if(vis[s][x]) continue;
		vis[s][x]=1;
		for(int i=0;i<rd[x].size();i++){
			int y=rd[x][i];
			if(dis[s][x]+l[x][y]<dis[s][y]){
				dis[s][y]=dis[s][x]+l[x][y];
				q.push({dis[s][y],y});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>sub[i];
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			int x;
			long long y;
			cin>>x>>y;
			v[x].push_back(i);
			w[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=l[i][j]=LONG_LONG_MAX;
		l[i][i]=0;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++) for(int j=0;j<v[i].size();j++) for(int k=j+1;k<v[i].size();k++) l[v[i][j]][v[i][k]]=l[v[i][k]][v[i][j]]=min(l[v[i][j]][v[i][k]],w[i][j]+w[i][k]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(l[i][j]!=LONG_LONG_MAX){
				rd[i].push_back(j);
				rd[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++) bfs(i);
	while(q--){
		int s,t;
		cin>>s>>t;
		long long ans=LONG_LONG_MAX;
		for(int i=0;i<v[s].size();i++) for(int j=0;j<v[t].size();j++) ans=min(ans,dis[v[s][i]][v[t][j]]+w[s][i]+w[t][j]);
		cout<<ans+sub[s]+sub[t]<<"\n";
	}
	return 0;
}