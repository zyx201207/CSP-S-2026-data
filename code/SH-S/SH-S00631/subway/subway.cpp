#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=509,M=5e5+9,D=22,Q=1e5+9;
const int INF=1e15;
int c,n,m,d,q;
int w[M];
vector<pair<int,int> > to[M];//t,idn
int dis[N][N]; 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
//	cout<<INF<<endl;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int k,za,zt;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>za>>zt;
			to[za].push_back(make_pair(zt,i));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			dis[i][j]=dis[j][i]=INF;
		}
	}
	int u,v;
	for(int i=1;i<=m;i++){
		for(auto e1:to[i]){
			for(auto e2:to[i]){
				if(e1==e2) continue;
				u=e1.second,v=e2.second,zt=e1.first+e2.first;
				if(dis[u][v]>zt) dis[u][v]=dis[v][u]=zt;
//				cout<<u<<' '<<v<<'\n';
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(k==i||k==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	int x,y,ans;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=INF;
		for(auto e1:to[x]){
			for(auto e2:to[y]){
//				cout<<e1.second<<' '<<e2.second<<' '<<dis[e1.second][e2.second]<<'\n';
				ans=min(ans,e1.first+e2.first+dis[e1.second][e2.second]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
		
	}
	return 0;
} 
