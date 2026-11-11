#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=510,M=5e5+10;
const long long mxint=1e18;
struct nnd{
	int to,vl;
};
int C,n,m,d,q;
long long ans;
int w[M],k[N];
//int a[N][M],t[N][M];
//int tmd[M][N];
long long v[N][N];
int jd[N][N];
vector<nnd>g[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			v[i][j]=mxint;
			if(i==j) v[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t; 
			cin>>a>>t;
//			tmd[a][i]=t;
			g[a].push_back((nnd){i,t});
		}
	}
	for(int i=1;i<=m;i++){
		int len=g[i].size();
		for(int j=0;j<len;j++){
			for(int k=0;k<len;k++){
				if(j==k) continue;
				long long value=g[i][j].vl+g[i][k].vl;
				v[g[i][j].to][g[i][k].to]=v[g[i][k].to][g[i][j].to]=min(v[g[i][j].to][g[i][k].to],value);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||i==k||k==j) continue;
				v[i][j]=min(v[i][k]+v[k][j],v[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0;
			continue;
		}
		ans=mxint;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				int tx=g[x][i].to,ty=g[y][j].to;
				ans=min(ans,(long long)(g[x][i].vl+g[y][j].vl+v[tx][ty]));
//				cout<<tmd[x][tx]<<' '<<tmd[y][ty]<<' '<<v[tx][ty]<<'\n';
			}
		} 
		cout<<ans+w[x]+w[y]<<'\n'; 
	}
//	cout<<clock()<<"ms";
	return 0;
}
