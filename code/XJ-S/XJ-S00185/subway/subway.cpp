#include<bits/stdc++.h>
#define int long long

using namespace std;

struct edge{
	int v,w;
};

const int N=505,P=6e5+5;
int c,n,m,d,q;
int w[P],down[P];//wi:from station to exit downi:frome station to down
int dis[N][N];
vector<edge> e[P];
vector<edge> vis[P];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int st,time;
			cin>>st>>time;
			down[st]=time;
			e[st].push_back((edge){m+i,time});
			e[m+i].push_back((edge){st,time}); 
			vis[st].push_back((edge){i,time});
		}
	} 
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=m+1;i<=m+n;i++){
		for(int j=0;j<e[i].size();j++){
			int v=e[i][j].v;
			int w1=e[i][j].w;
			for(int k=0;k<e[v].size();k++){
				int vv=e[v][k].v;
				int w2=e[v][k].w;
				dis[i-m][vv-m]=min(dis[i-m][vv-m],w1+w2);	
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(dis[i][k]==0x3f3f3f3f3f3f3f3f||dis[k][j]==0x3f3f3f3f3f3f3f3f){
					continue;
				}
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		int res=0x3f3f3f3f3f3f3f3f;
		for(int i1=0;i1<vis[u].size();i1++){
			int bzdjsm=vis[u][i1].v;
			int w1=vis[u][i1].w;
			for(int i2=0;i2<vis[v].size();i2++){
				int sybzd=vis[v][i2].v;
				int w2=vis[v][i2].w;
				res=min(res,dis[bzdjsm][sybzd]+w1+w2);
			}
		}
		res=(res+w[u]+w[v]);
		cout<<res<<"\n";
	}
	return 0;
}
