#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ve vector
#define pb push_back
#define pii pair<ll,ll>
#define p_q priority_queue
#define mk make_pair
#define endl '\n'
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define lowbit(x) ((x)&(-x))
namespace cute_fzj_kuai_ruarua{
	int c,n,m,d,q;
	ll w[500005];
	ve<pii>l[500005];
	ve<pii>a[505];
	ll g[505][505];
	void main(){
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int x,y;
				cin>>x>>y;
				a[i].pb(mk(x,y));
				l[x].pb(mk(i,y));
			}
		}
		memset(g,INF,sizeof g);
		for(int i=1;i<=n;i++) g[i][i]=0;
		for(int i=1;i<=m;i++){
			for(auto x:l[i]){
				for(auto y:l[i]){
					g[x.fi][y.fi]=min(g[x.fi][y.fi],x.se+y.se);
					g[y.fi][x.fi]=min(g[y.fi][x.fi],x.se+y.se);
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			ll ans=1e18;
			for(auto _:l[x]){
				for(auto __:l[y]){
					ans=min(ans,w[x]+w[y]+_.se+__.se+g[_.fi][__.fi]);
				}
			}
			cout<<ans<<endl;
		}
	}
}
using namespace cute_fzj_kuai_ruarua;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cute_fzj_kuai_ruarua::main();
	return 0;
}

