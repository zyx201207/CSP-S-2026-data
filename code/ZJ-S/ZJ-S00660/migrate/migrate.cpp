#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],cnt,minn;
bool vis[2000005];
vector<int> g[2000005];
void dfs(int x,int y,int sum){
	if(sum>minn) return;
	if(x==y){
		if(sum==minn) cnt++;
		else if(sum<minn) cnt=1,minn=sum;
		return;
	}
	for(int i=0;i<g[x].size();i++){
		if(vis[g[x][i]]) continue;
		vis[g[x][i]]=1;
		dfs(g[x][i],y,sum+1);
		vis[g[x][i]]=0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d) g[i].push_back(j),g[j].push_back(i); 
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0,minn=2e9;
				dfs(i,j,0);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
