#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define pb push_back

const int inf=1e18;
const int maxn=510;
const int maxm=5e5+10;
int cid,n,m,d,q,w[maxm],dis[maxn][maxn],a,t,k,x,yy;
vector<PII> sub[maxm]; //(id,time)

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		sub[i].reserve(d);
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			sub[a].pb(mk(i,t));
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto u:sub[i]) for(auto v:sub[i]){
			dis[u.fi][v.fi]=dis[v.fi][u.fi]=min(dis[u.fi][v.fi],u.se+v.se);
		}
	}
	for(int i=1;i<=n;i++)
		for(int k=1;k<=n;k++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		cin>>x>>yy;
		int ans=inf;
		for(auto u:sub[x]) for(auto v:sub[yy]){
			ans=min(ans,u.se+v.se+dis[u.fi][v.fi]);
		}
		cout<<ans+w[x]+w[yy]<<"\n";
	}
	return 0;
}

/*
O(qd^2) is ok

very easy,get every two subway route's dis O(n^3)
and than choose the x,y 's first subway route O(md^2)

and I can solve this problem.
let's go to T3 first

how to get two subway route's dis???
Oh,I can calc it on every point,this is O(nd^2)
*/
