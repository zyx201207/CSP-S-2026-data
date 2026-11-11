#include<bits/stdc++.h>
using namespace std;

int n,m,T;
long long f[1010][1010];
int w[1000010];
vector<int> g[1000010];
int z[500010][510];
void init(){
	int x,y;
	cin>>x>>y;
	long long ans=1e18;
	for(auto j : g[x]){
		for(auto k : g[y]){
			ans=min(ans,(long long)w[x]+w[y]+z[x][j]+z[y][k]+f[j][k]);
		}
	}
	cout<<ans<<"\n";
}
void zdl(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				if(i==j || k==i || k==j){
					continue;
				}
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[j][k]);
			}
		}
	}
}
void solve(){
	for(int i=1; i<=m; i++){
		for(int j=0; j<g[i].size(); j++){
			for(int k=j; k<g[i].size(); k++){
				f[g[i][j]][g[i][k]]=min(f[g[i][j]][g[i][k]],(long long)z[i][g[i][j]]+z[i][g[i][k]]);
				f[g[i][k]][g[i][j]]=min(f[g[i][k]][g[i][j]],(long long)z[i][g[i][j]]+z[i][g[i][k]]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>T>>T;
	memset(f,0x3f3f3f3f,sizeof(f));
	for(int i=1; i<=m; i++){
		cin>>w[i];
	}
	f[0][0]=0;
	for(int i=1; i<=n; i++){
		f[i][i]=0;
		int q;
		cin>>q;
		while(q--){
			int x;
			cin>>x;
			cin>>z[x][i];
			g[x].push_back(i);
		}
	}
	solve();
	zdl();
	while(T--){
		init();
	}
	return 0;
}
