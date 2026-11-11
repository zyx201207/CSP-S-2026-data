#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define fi first
#define se second
const int N=500+6,M=5e5+6;
int dis[N][N];
int w[M];
int len[M];
vector<pii> g[M];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	f(i,1,m)cin>>w[i];
	f(i,1,n){
		cin>>len[i];
		f(j,1,len[i]){
			int x,num;cin>>x>>num;
			//to[i].push_back(x);
			g[x].push_back({i,num});
		}
	}f(i,1,n)f(j,1,n)dis[i][j]=1e18;
	f(i,1,n)dis[i][i]=0;
	f(i,1,m){
		f(j,0,g[i].size()-1){
			f(k,0,g[i].size()-1){
				dis[g[i][j].fi][g[i][k].fi]=min(g[i][j].se+g[i][k].se,dis[g[i][j].fi][g[i][k].fi]);
			}
		}
	}f(k,1,n)f(i,1,n)f(j,1,n){
		dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	}
	while(q--){
		int x,y;cin>>x>>y;
		int ans=1e18;
		f(i,0,g[x].size()-1){
			f(j,0,g[y].size()-1){
				ans=min(ans,dis[g[x][i].fi][g[y][j].fi]+g[x][i].se+g[y][j].se);
			}
		}//cout<<ans<<"\n";
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}