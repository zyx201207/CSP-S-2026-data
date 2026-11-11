//
#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rop(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define por(i,a,b) for(int i=a;i>=b;i--)
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double ld;
using namespace std;
int c,n,m,d,q,w[500005],k,a,t,dis[505][505],x,y;
vector<pii>v[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m)
		cin>>w[i];
	rep(i,1,n){
		rep(j,1,n)
			dis[i][j]=0x3f3f3f3f3f3f3f3f;
		dis[i][i]=0;
	}
	rep(i,1,n){
		cin>>k;
		rep(j,1,k){
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	rep(i,1,m)
		rop(j,0,v[i].size())
			rop(l,0,v[i].size())
				dis[v[i][j].fi][v[i][l].fi]=min(dis[v[i][j].fi][v[i][l].fi],v[i][j].se+v[i][l].se);
	rep(i,1,n)
		rep(j,1,n)
			rep(k,1,n)
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	while(q--){
		cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(auto i:v[x])
			for(auto j:v[y])
				ans=min(ans,w[x]+i.se+dis[i.fi][j.fi]+j.se+w[y]);
		cout<<ans<<endl;
	}
	return 0;
}
/*
15:00 100
*/

