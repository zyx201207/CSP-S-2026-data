#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
int c,n,m,q,w[501005],k[501005],d[502][502];
vector<pii> G[501005],rG[502];
void floyd(){
	for(int j=1;j<=n;j++)
		for(int i=1;i<=n;i++)
			for(int k=1;k<=n;k++)
				d[i][k]=min(d[i][k],d[i][j]+d[j][k]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>q>>q;
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		d[i][i]=0;
		cin>>k[i];
		for(int j=1,a,t;j<=k[i];j++){
			cin>>a>>t;
			G[a].push_back({i,t});
//			rG[i].push_back({a,t});
		}
	}
	for(int i=1;i<=m;i++){
		if(G[i].size()<2) continue;
		for(int j=0;j<G[i].size();j++){
			for(int k=j+1;k<G[i].size();k++){
				int x=G[i][j].first,y=G[i][k].first;
				d[x][y]=d[y][x]=min(d[x][y],G[i][j].second+G[i][k].second);
			}
		}
	}
	floyd();
	for(int x,y;q--;){
		cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(auto bg:G[x]){
			for(auto ed:G[y]){
				ans=min(ans,d[bg.first][ed.first]+bg.second+ed.second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
