#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int M=5e5+5,N=505;
const long long inf=1e18;
int w[M];
ll dis[N][N];
vector<pair<int,int> >g[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=((i==j)?0:inf);
		}
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,t;
			cin>>u>>t;
			g[u].pb({i,t});
		}
	}
	
	for(int i=1;i<=m;i++){
		int len=g[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				int a=g[i][j].first,b=g[i][k].first;
				dis[a][b]=dis[b][a]=min(dis[a][b],(ll)g[i][j].second+(ll)g[i][k].second);
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
		int x,y;
		cin>>x>>y;
		int len1=g[x].size(),len2=g[y].size();
		ll ans=inf;
		
//		int ansl1=0,ansl2=0;
		
		for(int i=0;i<len1;i++){
			for(int j=0;j<len2;j++){
				int l1=g[x][i].first,t1=g[x][i].second;
				int l2=g[y][j].first,t2=g[y][j].second;
				ans=min(ans,t1+t2+dis[l1][l2]);
//				if(ans==t1+t2+dis[l1][l2]){
//					ansl1=l1;
//					ansl2=l2;
//				}
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
//		cout<<ansl1<<' '<<ansl2<<'\n';
	}
	return 0;
}
