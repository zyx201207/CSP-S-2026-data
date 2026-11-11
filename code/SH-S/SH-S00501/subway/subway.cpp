#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500010],k;int ai,ti;
vector<int> a[510],t[510];
long long dp[510][510],dis[510][510];
vector<int> fa[500010],dt[500010];
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;dis[i][i]=0;dp[i][i]=0;
		for(int j=1;j<=k;j++){
			cin>>ai>>ti;
			fa[ai].push_back(i);
			dt[ai].push_back(ti);
			a[i].push_back(ai);t[i].push_back(ti);
		}
	}
	for(int i=1;i<=m;i++){
//		for(auto j:fa[i])cout<<j<<" ";
//		cout<<'\n';
		
		if(fa[i].size()>=2){
			int u=fa[i].size();
			for(int x=0;x<u;x++){
				for(int y=x+1;y<u;y++){
					dis[fa[i][x]][fa[i][y]]=min(dis[fa[i][x]][fa[i][y]],dt[i][x]+dt[i][y]);
					dis[fa[i][y]][fa[i][x]]=min(dis[fa[i][y]][fa[i][x]],dt[i][y]+dt[i][x]);
					dp[fa[i][x]][fa[i][y]]=dis[fa[i][x]][fa[i][y]];
					dp[fa[i][y]][fa[i][x]]=dis[fa[i][y]][fa[i][x]];
				}
			}
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)cout<<dis[i][j]<<" ";
//		cout<<'\n';
//	}
	
	//cout<<'\n';
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[j][k]);
			} 
		}
	}int xs,ys;
	while(q--){
		cin>>xs>>ys;long long ans=0x3f3f3f3f3f3f3f3f;
		int fx=fa[xs].size(),fy=fa[ys].size();
		for(int i=0;i<fx;i++){
			for(int j=0;j<fy;j++){
				//cout<<dp[fa[xs][i]][fa[ys][j]]<<":"<<fa[xs][i]<<","<<fa[ys][j]<<"|";
				ans=min(ans,dp[fa[xs][i]][fa[ys][j]]+w[xs]+w[ys]+dt[xs][i]+dt[ys][j]);
			}
		}//cout<<'\n';
		cout<<ans<<'\n';
	}
	return 0;
}
