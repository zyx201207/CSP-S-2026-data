#include<bits/stdc++.h>
#define eps 1e-7
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
#define fi first
#define se second
#define MAXN 500005
int n,m,d,Q,w[MAXN];
LL dis[505][505];
vector<pii>v[MAXN];
void solve(){
	int C;cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int sz=v[i].size();
		for(int i1=1;i1<sz;i1++)
		for(int i2=0;i2<i1;i2++){
			auto[x,v1]=v[i][i1];
			auto[y,v2]=v[i][i2];
			dis[x][y]=dis[y][x]=min(dis[x][y],0ll+v1+v2);
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)dis[i][j]=dis[j][i];
	while(Q--){
		int x,y;cin>>x>>y;
		LL ans=INF;
		for(auto[i,v1]:v[x])
			for(auto[j,v2]:v[y]){
				ans=min(ans,0ll+w[x]+w[y]+v1+v2+dis[i][j]);
			}
		cout<<ans<<'\n';
	}
}
signed main(){
	auto ST=clock();
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;//cin>>T;
	while(T--)solve();
	auto EN=clock();
	cerr<<LD(EN-ST)/CLOCKS_PER_SEC<<endl;

	return 0;
}