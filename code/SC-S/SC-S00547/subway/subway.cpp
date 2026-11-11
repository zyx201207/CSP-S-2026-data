#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=5e2+5;
int c,n,m,d_cnt,q;
long long f[N][N],w[M];
long long cst[M][21];
vector<pair<int,long long>> ed[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d_cnt>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
		}f[i][i]=0;
	}
	for(int li=1;li<=n;li++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int a;
			long long t;
			cin>>a>>t;
			for(auto e:ed[a]){
				int v=e.first;
				long long t2=e.second;
				f[li][v]=min(f[li][v],t2+t);
				f[v][li]=f[li][v];
			}
			ed[a].push_back({li,t});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				f[j][i]=f[i][j];
			}
		}
	}for(int r=1;r<=q;r++){
		int x,y;
		cin>>x>>y;
		long long res=1e18;
		for(auto e1:ed[x]){
			for(auto e2:ed[y]){
				res=min(res,f[e1.first][e2.first]+e1.second+e2.second);
			}
		}cout<<res+w[x]+w[y]<<"\n"; 
	}
	return 0;
}