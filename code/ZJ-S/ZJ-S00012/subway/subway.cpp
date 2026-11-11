#include<bits/stdc++.h>
#define int long long
#define inf 1e17
using namespace std;
int c,n,m,d,q,w[500005],k[505],zj[505][505],ans[505][505];
unordered_map<int,int>mp[505];
vector<int>e[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,a,t;j<=k[i];j++){
			cin>>a>>t;
			mp[i][a]=t;
			e[a].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			zj[i][j]=inf;
			for(int k=1;k<=m;k++){
				if(mp[i][k]&&mp[j][k]){
					zj[i][j]=min(zj[i][j],mp[i][k]+mp[j][k]);
				}
			}
			zj[j][i]=zj[i][j];
		}
	}
	for(int x=1;x<=n;x++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				zj[i][j]=min(zj[i][j],zj[i][x]+zj[x][j]);
			}
		}
	}
	while(q--){
		int x,y,ans=inf;
		cin>>x>>y;
		for(int u:e[x]){
			for(int v:e[y]){
				ans=min(ans,mp[u][x]+mp[v][y]+zj[u][v]+w[x]+w[y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

