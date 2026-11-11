#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=505; 
long long w[N];
int k[N];
int c,n,m,d,q;
long long ans;
struct Node{
	int id;
	long long t;
};
vector<Node>bl[N];
long long g[M][M];
bool f[M][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	memset(g,127,sizeof g);
	memset(f,false,sizeof f);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int aa;
			long long tt;
			scanf("%d%lld",&aa,&tt);
			bl[aa].push_back({i,tt});
		}
	}
	for(int i=1;i<=n;i++)
		g[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<bl[i].size();j++){
			for(int k=j+1;k<bl[i].size();k++){
				int u=bl[i][j].id,v=bl[i][k].id;
				long long t1=bl[i][j].t,t2=bl[i][k].t;
				g[u][v]=g[v][u]=min(t1+t2,g[u][v]);
				f[u][v]=f[v][u]=true;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(!f[i][j]) continue;
			for(int k=1;k<=n;k++){
				if(i==k||j==k) continue;
				if(!f[j][k]) continue;
				g[i][k]=min(g[i][k],g[i][j]+g[j][k]);
				g[k][i]=g[i][k];
				f[i][k]=f[k][i]=true;
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ans=1e18;
		for(auto xx:bl[x])
			for(auto yy:bl[y])
				ans=min(ans,g[xx.id][yy.id]+xx.t+yy.t);
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
