#include <bits/stdc++.h> 
#define int long long
using namespace std ;

bool M1 ;
const int N=510,M=5e5+10 ;
int dis[N][N] ; int w[M] ;
int type1,n,m,d,q ; unordered_map<int,int> t[M] ;
vector<int> hav[M] ;
bool M2 ;

signed main() {
	freopen("subway.in","r",stdin) ;
	freopen("subway.out","w",stdout) ;
	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	
	memset(dis,0x3f,sizeof(dis)) ;
	cin>>type1>>n>>m>>d>>q ;
	for(int i=1;i<=m;i++) cin>>w[i] ;
	for(int p=1;p<=n;p++) dis[p][p]=0 ;
	for(int p=1;p<=n;p++) {
		int k ; cin>>k ;
		for(int j=1;j<=k;j++) {
			int x1,x2 ; cin>>x1>>x2 ;
			t[p][x1]=x2 ;
			if(!hav[x1].empty()) for(int p1:hav[x1]) {
				dis[p1][p]=t[p][x1]+t[p1][x1] ;
				dis[p][p1]=t[p][x1]+t[p1][x1] ;				
			}
			hav[x1].push_back(p) ;
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) 
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]) ;
	while(q--) {
		int u,v ; cin>>u>>v ; int ans=1e18 ;
		for(int p:hav[u]) for(int p1:hav[v]) {
			ans=min(ans,dis[p][p1]+w[u]+w[v]+t[p][u]+t[p1][v]) ;
		}
		cout<<ans<<"\n" ;
	}
	
	return 0 ;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17

*/