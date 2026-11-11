#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int mod=1e9+7;
const int N=5e5+10;
const int M=505;
auto getmax=[](auto &a,auto b){a=max(a,b);};
auto getmin=[](auto &a,auto b){a=min(a,b);};
#define fir first
#define sec second

int c,m,n,d,q,a[N];
vector<pll> to[N];
ll dis[M][M];


signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>a[i];
	for(int i=1,len,u,w; i<=n; i++){
		cin>>len;
		while(len--) cin>>u>>w, to[u].push_back({i,w});
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1; i<=n; i++) dis[i][i]=0;
	for(int i=1; i<=m; i++){
		for(auto u:to[i])
			for(auto v:to[i])
				getmin(dis[u.fir][v.fir],u.sec+v.sec);
	}
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				getmin(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int u,v; cin>>u>>v;
		ll res=4e18;
		for(auto p:to[u])
			for(auto q:to[v])
				getmin(res,dis[p.fir][q.fir]+p.sec+q.sec);
		res+=a[u]+a[v];
		cout<<res<<endl;
	}
	
	return 0;
}