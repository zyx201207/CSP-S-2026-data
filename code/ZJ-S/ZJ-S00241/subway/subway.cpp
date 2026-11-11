#include<bits/stdc++.h>
#define int long long
#define MIN(A,B) (A<B?A:B)
using namespace std;
const int N=505,M=5e5+5;

struct edge{
	int v,w;
};

int c,n,m,d,q;
int L[M],dis[N][N];
vector<edge>e[M];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dis[i][j]=2e18;
			if(i==j)dis[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)cin>>L[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1,id,w;j<=k;j++){
			cin>>id>>w;
			edge x={i,w};
			e[id].push_back(x);
		}
	}
	for(int i=1;i<=m;i++){
		int s=e[i].size();
		for(int j=0;j<s;j++){
			for(int k=0;k<s;k++){
				if(j!=k){
					int a=e[i][j].v,b=e[i][k].v;
					int w=e[i][j].w+e[i][k].w;
					dis[a][b]=MIN(dis[a][b],w);
					dis[b][a]=dis[a][b];
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int u,v,rt=2e18;cin>>u>>v;
		int sz1=e[u].size(),sz2=e[v].size();
		for(int i=0;i<sz1;i++){
			for(int j=0;j<sz2;j++){
				rt=min(rt,L[u]+L[v]+e[u][i].w+e[v][j].w+dis[e[u][i].v][e[v][j].v]);
			}
		}
		cout<<rt<<'\n';
	}
	return 0;
}
