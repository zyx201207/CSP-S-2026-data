#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=5010;
ll c,T,n,m;
ll a[N];
ll dis[N][N],num[N][N];
bool vis[N][N];
vector<int > edge[N];
void bfs(int s){
	queue<int > q;
	dis[s][s]=0;num[s][s]=1;q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[s][u]=1;
		for(const int& v:edge[u]){
			if(vis[s][v]) continue;
			if(dis[s][u]+1<dis[s][v]){
				dis[s][v]=dis[s][u]+1;
				num[s][v]=num[s][u];
				q.push(v);
			}
			else if(dis[s][u]+1==dis[s][v]) num[s][v]+=num[s][u];
		}
	}
}
void sol(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],edge[i].clear();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=1e18,num[i][j]=0,vis[i][j]=0;
	for(int i=1;i<=n;i++){
		int j=i+1;
		while(a[j]<=a[i]+m&&j<=n){
			edge[i].emplace_back(j);
			j++;
		}
	}
	for(int i=1;i<=n;i++) bfs(i);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(num[i][j]==2) ans++;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) sol();
	return 0;
}
