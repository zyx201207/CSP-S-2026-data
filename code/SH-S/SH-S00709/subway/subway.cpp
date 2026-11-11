#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define rrep(i,r,l) for(int i=r;i>=l;i--)
#define fi first
#define sc second
#define pb push_back
#define pq priority_queue
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5,D=22;
int c,n,m,d,q;
ll W[M];
vector<pair<int,ll>>V[M];
ll dis[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m){
		cin>>W[i];
	}
	rep(i,1,n){
		int k;
		cin>>k;
		rep(j,1,k){
			ll a,b;
			cin>>a>>b;
			V[a].pb({i,b});
		}
	}
	rep(i,1,n){
		rep(j,1,n){
			if(i!=j){
				dis[i][j]=1e18;
			}
		}
	}
	rep(i,1,m){
		for(auto x:V[i]){
			for(auto y:V[i]){
				dis[x.fi][y.fi]=min(dis[x.fi][y.fi],x.sc+y.sc);
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
	rep(i,1,q){
		int s,t;
		cin>>s>>t;
		ll ans=1e18;
		for(auto x:V[s]){
			for(auto y:V[t]){
				ans=min(ans,x.sc+y.sc+dis[x.fi][y.fi]);
//				cerr<<x.fi<<" "<<y.fi<<"  "<<x.sc<<" "<<y.sc<<" "<<dis[x.fi][y.fi]<<"\n";
			}
		}
//		cerr<<ans<<" "<<W[s]<<" "<<W[t]<<"\n";
		cout<<ans+W[s]+W[t]<<"\n";
	}
	return 0;
}
