#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=505,mod=998244353,INF=5e17;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define rep(i,l,r)	for(int i=(l);i<=(r);i++)
#define atrep(i,l,r)	for(int i=(r);i>=(l);i--)
vector<pii>G[N];
vector<pii>P[M];
int w[N];
int dis[M][M],bg[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	int c,n,m,d,Q;
	cin>>c>>n>>m>>d>>Q;
	rep(i,1,m){
		cin>>w[i];
	}
	rep(i,1,n){
		rep(j,1,n){
			if(i==j)	dis[i][j]=0;
			else dis[i][j]=INF;
		}
	}
	rep(i,1,n){
		int sz;
		cin>>sz;
		rep(j,1,sz){
			int x,y;
			cin>>x>>y;
			P[i].push_back({x,y});
			G[x].push_back({i,j});
		}
		bg[i]=sz;
	}	
	rep(i,1,m){
		if(G[i].size()<=1)	continue;
		rep(l,0,(int)G[i].size()-1){
			rep(r,l+1,(int)G[i].size()-1){
				int x=G[i][l].first,y=G[i][r].first;
				int posl=G[i][l].second,posr=G[i][r].second;
				dis[x][y]=min(dis[x][y],P[x][posl-1].second+P[y][posr-1].second);
				dis[y][x]=min(dis[y][x],P[x][posl-1].second+P[y][posr-1].second);
			}
		}
	}
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	rep(i,1,Q){
		int x,y;
		cin>>x>>y;
		int res=INF;
		for(auto itl:G[x]){
			for(auto itr:G[y]){
				int p=itl.first,q=itr.first;
				res=min(res,dis[p][q]+w[x]+w[y]+P[p][itl.second-1].second+P[q][itr.second-1].second);
			}
		}
		cout<<res<<'\n';
	}
}