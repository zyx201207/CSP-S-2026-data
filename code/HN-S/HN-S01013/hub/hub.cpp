#include<bits/stdc++.h>
using namespace std;
const int N=4000+100;
int dis[N][N];
vector<int>vec[N];
void bfs(int s){
	queue<int>q;
	q.push(s);
	dis[s][s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:vec[u]){
			if(dis[s][v]==1e9){
				dis[s][v]=dis[s][u]+1;
				q.push(v);
			}
		}
	}
	return;
}
void slove(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		vec[i].clear();
		for(int j=1;j<=n;j++){
			dis[i][j]=1e9;
		}
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	int ans=1e9;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int mx=-1;
			for(int k=1;k<=n;k++){
				mx=max({mx,dis[k][i],dis[k][j]});
			}
			ans=min(ans,mx);
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		slove();
	}
	return 0;
}

