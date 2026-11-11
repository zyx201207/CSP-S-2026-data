#include<bits/stdc++.h>
#define int long long
using namespace std;
using pii=pair<int,int>; 
const int N=5e5+10,M=505;
int w[N];
vector<int> zh[N],xh[N];
int c,n,m,d,q;
vector<int> has[N];
int dp[M][M];
int qu[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	if(c>=1&&c<=6){
	int co[M][M];
		cin>>n>>m;
		cin>>d;
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int zt;
				cin>>zt>>co[zt][i];
				xh[i].push_back(zt);
				has[zt].push_back(i);
			}
		}
		cin>>q;
		while(q--){
			for(int i=1;i<=m;i++){ 
				for(int j=1;j<=m;j++) dp[i][j]=INT_MAX;
			int x,y;
			cin>>x>>y;
			int h=1,t=1;
			qu[i]=1;
			dp[x][y]=0;
			while(h<=t){
				int top=qu[h++];
				for(int i=0;i<zh[top].size();i++){
					int u=zh[top][i];
					for(int j=0;j<xh[u].size();j++){
						int v=xh[u][j];
						if(dp[x][v]<=dp[x][top]+co[top][u]+co[v][u]) continue;
						else{
							dp[x][v]=dp[x][top]+co[top][u]+co[v][u];
							qu[++t]=v;
						}
					}
				}
			}
			cout<<w[x]+w[y]+dp[x][y]<<'\n';	
			}
		}
	}
	if(c>=12&&c<=19){
	vector<int> has[N];
	int dp[M][M];
	int qu[N];
	int co;
		cin>>n>>m;
		cin>>d;
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int zt,co;
				xh[i].push_back(zt);
				has[zt].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++) dp[i][j]=-1;
			dp[i][i]=0;
			int h=1,t=1;
			qu[i]=1;
			while(h<=t){
				int top=qu[h++];
				for(int j=0;j<xh[top].size();j++){
					int u=xh[top][j];
					for(int k=0;k<zh[u].size();k++){
						int v=zh[u][k];
						if(dp[i][v]!=-1) continue;
						 dp[i][v]=dp[i][top]+1;
						 qu[++t]=v;
					}
				}
			}
			int q;
			cin>>q;
			while(q--){
				int ans=LLONG_MAX;
				int x,y;
				cin>>x>>y;
				for(int i=0;i<zh[x].size();i++){
					for(int j=0;j<zh[y].size();j++){
						int u=zh[x][i],v=zh[y][i];
						ans=min(ans,dp[u][v]);
					}
				}
				cout<<w[x]+w[y]+ans*co<<'\n';
			}
		}
	}
	return 0;
}