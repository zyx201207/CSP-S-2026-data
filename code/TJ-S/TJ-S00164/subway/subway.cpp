#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505,M=5e5+5;
const ll INF=1e18;
int c,n,m,d,q,w[M],t[N][M];
ll f[N][N];
vector<int> e[N];
ll solve(int x,int y){
	ll ans=INF;
	for(int i:e[x]){
		for(int j:e[y]){
			ans=min(ans,f[i][j]+(ll)t[i][x]+(ll)t[j][y]);
		}
	}
	return ans+(ll)w[x]+(ll)w[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	int k,p;
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>p;
			e[p].push_back(i);
			cin>>t[i][p];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			f[i][j]=INF;
		}
		f[i][i]=0;
	}
	for(int p=1;p<=m;++p){
		for(int i:e[p]){
			for(int j:e[p]){
				if(i==j) continue;
				f[i][j]=min((ll)t[i][p]+(ll)t[j][p],f[i][j]);
				f[j][i]=f[i][j];
			}
		}
	}
	for(int k=1;k<=n;++k){//floyd
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		cout<<solve(x,y)<<'\n';
	}
	return 0;
}
