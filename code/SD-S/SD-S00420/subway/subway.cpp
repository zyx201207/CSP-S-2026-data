#include<bits/stdc++.h>
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define all(x) (x).begin(),(x).end()
#define tmax(a,b) (a)=max((a),(b))
#define tmin(a,b) (a)=min((a),(b))
#define cout(x) cout<<fixed<<setprecision(x)

using namespace std;
typedef long long LL;typedef pair<int,int> PII;
typedef vector<int> vi;typedef vector<PII> vp;
typedef array<int,3> a3;typedef vector<a3> va3;

const int N=5e2+5,M=5e5+5;
const LL Inf=1e18+7;
int c,n,m,d,q,w[M];
LL dis[N][N];
vp bel[M];

signed main(){
//	system("fc subway7.ans subway.out");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int u=1,k;u<=n;u++){
		cin>>k;
		for(int i=1,a,t;i<=k;i++){
			cin>>a>>t;
			for(auto tmp:bel[a]){
				int v,cost;tie(v,cost)=tmp;
				tmin(dis[u][v],(LL)cost+t);
				tmin(dis[v][u],(LL)cost+t);
			}
			bel[a].pb({u,t});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(dis[i][k]>=0x3f3f3f3f3f3f3f3f) continue;
			for(int j=1;j<=n;j++){
				tmin(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		LL ans=Inf;
		for(auto tmp1:bel[x]){
			int u,cu;tie(u,cu)=tmp1;
			for(auto tmp2:bel[y]){
				int v,cv;tie(v,cv)=tmp2;
				tmin(ans,cu+cv+dis[u][v]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

15:23
*/

