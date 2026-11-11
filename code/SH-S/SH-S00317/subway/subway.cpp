#include<iostream>
using namespace std;
int c,n,m,d,q;
int k,a,t;
int w[500010];
long long dp[500010][25],p[500010][25];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
		cin>>w[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i+2;++j){
			cin>>a>>t;
			dp[a][i]=t;
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			if(j!=i)
				p[i][j]=1e9;
		}
	}
	for(int i=1;i<=m;++i){
		for(int u=1;u<=t;++u){
			for(int v=u+1;v<=d;++v){
				p[u][v]=min(p[v][u],dp[i][u]+dp[i][v]);
				p[v][u]=min(p[v][u],dp[i][u]+dp[i][v]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int u=1;u<=n;++u){
			for(int v=1;v<=n;++v){
				p[u][v]=min(p[u][v],p[u][i]+p[i][v]);
			}
		}
	}
	int x,y;
	for(int i=1;i<=q;++i){
		cin>>x>>y;
		cout<<p[x][y]<<endl;
	}
	return 0;
}
