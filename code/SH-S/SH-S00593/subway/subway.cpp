#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int w[600000];
vector<array<int,2> > vesna[510000];
int g[600][600];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) g[i][j] = g[j][i] = 1e18; 
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y; cin>>x>>y; vesna[x].push_back({y,i});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<vesna[i].size();j++){
			for(int k=j+1;k<vesna[i].size();k++){
				g[vesna[i][j][1]][vesna[i][k][1]] = min(g[vesna[i][j][1]][vesna[i][k][1]], vesna[i][j][0]+vesna[i][k][0]);
				g[vesna[i][k][1]][vesna[i][j][1]] = min(g[vesna[i][k][1]][vesna[i][j][1]], vesna[i][j][0]+vesna[i][k][0]);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++) g[j][k] = min(g[j][k], g[j][i]+g[i][k]);
	while(q--){
		int x,y;cin>>x>>y;
		int ans = 1e18;
		for(int i=0;i<vesna[x].size();i++)
			for(int j=0;j<vesna[y].size();j++) ans = min(ans, w[x]+w[y]+g[vesna[x][i][1]][vesna[y][j][1]]+vesna[x][i][0]+vesna[y][j][0]);
		cout << ans <<endl;
	}
}
