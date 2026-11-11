#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,m,n,d,q,w[500010];
int k[500010];
int g[510][510];
vector<pair<int,int>>crs[500010],ptc[500010];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		g[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,b;
			cin>>a>>b;
			crs[a].push_back({i,b});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto xx:crs[i]){
			int su1=xx.first,wf=xx.second;
			for(auto yy:crs[i]){
				int su2=yy.first,wt=yy.second;
				g[su1][su2]=min(g[su1][su2],wf+wt);
				g[su2][su1]=g[su1][su2];
			}
		}
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		}
	}
	while(q--){
		int f,t;
		cin>>f>>t;
		int ans=LONG_LONG_MAX;
		for(auto xx:crs[f]){
			int su1=xx.first,wf=xx.second;
			for(auto yy:crs[t]) {
				int su2=yy.first,wt=yy.second;
				ans=min(ans,w[f]+w[t]+wf+wt+g[su1][su2]);
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

