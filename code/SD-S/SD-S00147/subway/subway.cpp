#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mid (l+r>>1)
#define PII pair<int,int>
#define ll long long
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define per(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define lbt(x) ((x)&(-x))
#define pb push_back

const int N = 510,M = 5e5 + 10;

int n,m,d_,q,c;  //i to j
vector<PII>to[M];
ll f[N][N],d[N][N],w[M];

void solve(){
	cin>>c>>n>>m>>d_>>q;
	rep(i,1,m)cin>>w[i];
	rep(i,1,n){
		int k;cin>>k;
		rep(j,1,k){
			int x,w;cin>>x>>w;
			to[x].pb({i,w});
		}
	}
	rep(i,1,n)rep(j,1,n)d[i][j]=f[i][j]=1e15;
	rep(i,1,m)for(auto e1 : to[i])
		for(auto e2 : to[i]) d[e1.F][e2.F]=min(d[e1.F][e2.F],(ll)e1.S+e2.S);
	rep(i,1,n)rep(j,1,n)f[i][j]=(i==j?0:d[i][j]);
	rep(k,1,n)rep(i,1,n)rep(j,1,n)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		ll ans=1e15;
		for(auto e1 : to[x])for(auto e2 : to[y]){
//			cout<<e1.S<<' '<<e2.S<<" "<<e1.F<<" "<<e2.F<<"\n";
			ans=min(ans,f[e1.F][e2.F]+e1.S+e2.S);
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin >> T;
	while (T--){
		solve();
	}
	return 0;
}
/*
检查空间，UB，未初始化变量，数组下标
别急

May the odds be always in your favour
*/

