#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int M=5e5+10,N=505;

int c,n,m,d,q;

ll w[M],dis[N][N];

int k[N];

struct Edge{
	int v,w;
};

vector<Edge> b[M];

//vector<int> a[N],t[N];

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	memset(dis,0x3f,sizeof(dis));
	
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		cin>>k[i];
//		a[i].push_back(0);t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int A,T;
			cin>>A>>T;
//			a[i].push_back(A);t[i].push_back(T);
			b[A].push_back({i,T});
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=0;j<b[i].size();j++){
			for(int k=j+1;k<b[i].size();k++){
				int u=b[i][j].v,v=b[i][k].v;
				ll w_u=b[i][j].w,w_v=b[i][k].w;
				dis[u][v]=min(dis[u][v],w_u+w_v);
				dis[v][u]=min(dis[v][u],dis[u][v]);
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i==j) continue;
				if(!dis[i][k]||!dis[k][j]) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=min(dis[j][i],dis[j][k]+dis[k][i]);
			}
		}
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(int i=0;i<b[x].size();i++){
			for(int j=0;j<b[y].size();j++){
				ans=min(ans,w[x]+w[y]+b[x][i].w+b[y][j].w+dis[b[x][i].v][b[y][j].v]);
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

