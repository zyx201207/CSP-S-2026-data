#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,a[500005],k[505],f[505][505],ans;
vector<int> b[505],t[505],eid[500005],et[500005];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof f);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			int x,y;
			cin>>x>>y;
			b[i].push_back(x);
			t[i].push_back(y);
			eid[x].push_back(i);
			et[x].push_back(y);
		}
	}
	for(int i=1;i<=m;i++) f[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<eid[i].size();j++){
			for(int k=j+1;k<eid[i].size();k++){
				int u=eid[i][j],v=eid[i][k];
				f[u][v]=f[v][u]=min(f[u][v],et[i][j]+et[i][k]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=j+1;k<=m;k++){
				f[j][k]=f[k][j]=min(f[j][k],f[j][i]+f[i][k]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ans=1e18;
		for(int i=0;i<eid[u].size();i++){
			for(int j=0;j<eid[v].size();j++){
				int x=eid[u][i],y=eid[v][j];
				ans=min(ans,f[x][y]+et[u][i]+et[v][j]);
			}
		}
		cout<<ans+a[u]+a[v]<<'\n';
	}
	return 0;
}
