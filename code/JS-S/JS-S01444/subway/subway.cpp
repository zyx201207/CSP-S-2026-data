#include<bits/stdc++.h>
#define ll long long
#define PLL pair<ll,ll>
#define N 505
#define M 500005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

ll n,c,m,d,q;
ll dist[N][N],w[M];
vector<ll>sta[M];
map<PLL,ll>a,t;
//a[i][j] line i jst sta -> x
//t[i][j] time of i -> j
//               sta  line

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll x,y;
			cin>>x>>y;
			a[{i,j}]=x,t[{x,i}]=y;
			sta[x].push_back(i);
		}
	}

	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i!=j)dist[i][j]=INF;
		}
	}

	for(ll i=1;i<=m;i++)
		for(auto u : sta[i])
			for(auto v : sta[i])
				dist[u][v]=min(t[{i,u}]+t[{i,v}],dist[u][v]);

	for(ll k=1;k<=n;k++)
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
				dist[i][j]=min(dist[i][k]+dist[j][k],dist[i][j]);

	while(q--){
		ll x,y;
		cin>>x>>y;
		ll minn=INF;
		for(auto l1 : sta[x]){
			for(auto l2 : sta[y]){
				minn=min(minn,dist[l1][l2]+t[{x,l1}]+t[{y,l2}]);
			}
		}
		cout<<minn+w[x]+w[y]<<"\n";
	}
	return 0;
}