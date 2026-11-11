#include<bits/stdc++.h>

using namespace std;
const int MAXN=5005
long long c,t,n,d,x[MAXN],sum[ma];
long long dis[MAXN][MAXN];
bool f[MAXN];
struct node{
	long long ste,pos;
};
void bfs(int u,int v){
	queue<node> q;
	int diss=8e18,ans=0;
	for(int i=1;i<=n;i++){
		if(i==u) continue;
		if(dis[u][i]<d) q.push({u,i});
	}
	while(!q.empty()){
		int x=q.front().pos,ste=q.front().ste;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		if(x==v){
			if(diss>ste){
				ans=1,diss=ste;
			}else if(diss==ste){
				ans++;
			}
		}
		for(int i=1;i<=n;i++){
			if(dis[u][i]<d) q.push({v,i});
		}
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		sum[i]=sum[i-1]+x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=abs(sum[i]-sum[j]);
		}
	}
	
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
