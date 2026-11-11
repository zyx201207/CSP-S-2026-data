#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+5;
vector<pair<int,int> > g[N];
int c,n,m,d,q;
int dis[505][505],INF,t[505][505],w[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(t,0x3f,sizeof t);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		t[i][i]=0;
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	for(int a=1;a<=m;a++){
	//	cout<<a<<' '<<g[a].size()<<endl;
		for(int i=0;i<=g[a].size()-1;i++){
			for(int j=i+1;j<=g[a].size()-1;j++){
				int u=g[a][i].first,wu=g[a][i].second;
				int v=g[a][j].first,wv=g[a][j].second;
				t[u][v]=t[v][u]=min(t[u][v],wu+wv);
			}
		}
	}
	/*
	cout<<endl<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=t[i][j];
			cout<<dis[i][j]<<' ';
		}
		cout<<endl;	cout<<endl<<endl;
	}*/

	while(q--){
		int u,v,ans=1e18;
		cin>>u>>v;
		//floyd
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
			dis[i][j]=t[i][j];
		for(int i=0;i<=g[u].size()-1;i++)
		for(int j=0;j<=g[v].size()-1;j++) {
			int st=g[u][i].first,en=g[v][j].first;
			int cost=g[u][i].second+g[v][j].second;
		//	cout<<st<<' '<<en<<' '<<cost<<endl;
			for(int k=1;k<=n;k++){
			for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				if(i==st&&j==en)
				{
					ans=min(dis[i][j]+cost,ans);
				//	cout<<ans<<"-------"<<endl;
				}
						
			}
			}
			}
		}
		
		ans+=w[u]+w[v];
		cout<<ans<<endl;
		
	}
	return 0;
}

