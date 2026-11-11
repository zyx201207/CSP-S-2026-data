#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[1005],a[505][1005],t[505][1005],dis[1005][1005],k[505],ans=1e18,cost,x,y,ti[505][1005];
bool vis[1005],flag[505],rec[505][1005];
void dfs(int now,int tar){
	for(int i=1;i<=n;i++){
		if(rec[i][now]==1&&rec[i][tar]==1){
			ans=min(ans,cost);
			return;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(rec[j][now]==1&&rec[j][i]==1&&vis[i]==0&&flag[j]==0&&i!=now){
				cost+=(ti[j][now]+ti[j][i]);
				vis[i]=1;
				flag[j]=1;
				dfs(i,tar);
				vis[i]=0;
				flag[j]=0;
				cost-=(ti[j][now]+ti[j][i]);
			}
		}
	}
}
void solve1_11(){
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)dis[i][j]=1e15;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j],rec[i][a[i][j]]=1,ti[i][a[i][j]]=t[i][j];
	}
	while(q--){
		bool ok=0;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			if(rec[i][x]==1&&rec[i][y]==1){
				cout<<w[x]+w[y]+ti[i][x]+ti[i][y]<<'\n';
				ok=1;
				break;
			}
		}
		if(!ok){
			dfs(x,y);
			cout<<ans+w[x]+w[y]<<'\n';
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("sunway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	solve1_11();
}