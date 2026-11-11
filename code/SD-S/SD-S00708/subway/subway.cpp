#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int M=5e5+20,N=6e2+10;
int c,n,m,d,q;
int w[M];
int k,a,tt;
int dis[N][N];
int S,T;
vector<pii> t[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i]; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=1e18;
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>tt;
			t[a].push_back({i,tt});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto x:t[i]){
			for(auto y:t[i]){
				if(x.first!=y.first){
					dis[x.first][y.first]=min(dis[x.first][y.first],x.second+y.second);
					dis[y.first][x.first]=min(dis[y.first][x.first],x.second+y.second);
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
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout<<dis[i][j]<<" ";
		cout<<"\n";
	}*/
	while(q--){
		cin>>S>>T;
		int ans=1e18;
		for(auto i:t[S]){
			for(auto j:t[T]){
				ans=min(ans,dis[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<ans+w[S]+w[T]<<"\n";
	}
} 
