#include <bits/stdc++.h>
#include <assert.h>
#include <limits.h>
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back 
#define fi first
#define se second
#define pct(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
#define lowbit(x) ((x)&-(x))
#define dbg(x) cerr<<"Line= "<<__LINE__<<" : "<<#x<<"= "<<x<<endl;
using namespace std;
constexpr int N=510,M=500010,base=389,mod=998244353;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;

template<class T> inline void ckmin(T &x,T y){x=(x<y)?x:y;}
template<class T> inline void ckmax(T &x,T y){x=(x>y)?x:y;}

namespace Zhchz{
	ll C,n,m,D,Q;
	ll W[M];
	int K[N];
	vector<ll> a[N],t[N];
	vector<pll> b[M];
	
	ll mp[N][N];
	
	signed main(){
		ios::sync_with_stdio(0);cin.tie(0);
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		cin>>C>>n>>m>>D>>Q;
		for(int i=1;i<=m;i++) cin>>W[i];
		memset(mp,0x3f,sizeof mp);
		for(int i=1;i<=n;i++) mp[i][i]=0;
		for(int i=1;i<=n;i++){
			cin>>K[i];
			a[i].reserve(K[i]);
			t[i].reserve(K[i]);
			for(int j=1;j<=K[i];j++){
				int x,y;cin>>x>>y;
				for(pii t:b[x]){
					int cur=y+t.se;
					ckmin(mp[i][t.fi],cur);
					ckmin(mp[t.fi][i],cur);
				}
				a[i].pb(x);t[i].pb(y);
				b[x].pb({i,y});
			}
		}
		
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					ckmin(mp[i][j],mp[i][k]+mp[k][j]);
		
		while(Q--){
			int x,y;cin>>x>>y;
			ll ans=INF;
			for(pii t1:b[x])
				for(pii t2:b[y]){
					ckmin(ans,mp[t1.fi][t2.fi]+t1.se+t2.se);
				}
			cout<<W[x]+W[y]+ans<<"\n";
		}
		return 0;
	}
}signed main(){return Zhchz::main();}
