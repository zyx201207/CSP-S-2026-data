#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define mp make_pair
#define fst first
#define snd second

using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int LOG=9;

int c,n,m,d,q;
vector<ll> w;
vector<vector<ll>> t,cost;
vector<vector<pii>> bl;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>c>>n>>m>>d>>q;
	cost.assign(n+1,vector<ll>(n+1,inf));
	bl.assign(m+1,vector<pii>());
	w.assign(m+1,0LL);
	t.assign(n+1,vector<ll>());
	rep(i,1,m) cin>>w[i];
	rep(i,1,n){
		int ki;
		cin>>ki;
		t[i].assign(ki+1,0LL);
		rep(j,1,ki){
			int sta;
			cin>>sta>>t[i][j];
			if(bl[sta].size()){
				for(auto k:bl[sta]){
					ll c=t[i][j]+t[k.fst][k.snd];
					cost[k.fst][i]=c; cost[i][k.fst]=c;
				}
			}
			bl[sta].push_back(mp(i,j));
		}
	}
	
	rep(i,1,n) cost[i][i]=0;
	rep(k,1,n) rep(i,1,n) rep(j,1,n){
		cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
		cost[j][i]=cost[i][j];
	}
	while(q--){
		ll ans=inf;
		int a,b;
		cin>>a>>b;
		for(auto i:bl[a]) for(auto j:bl[b]){
			ans=min(ans,t[i.fst][i.snd]+t[j.fst][j.snd]+cost[i.fst][j.fst]);
		}
		cout<<ans+w[a]+w[b]<<'\n';
	}

	return 0;
}
