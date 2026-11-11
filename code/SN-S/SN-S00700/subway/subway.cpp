#include <bits/stdc++.h>
#define pr pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define For(i,l,r) for(int i=(l);i<=(r);i++)
#define Rep(i,r,l) for(int i=(r);i>=(l);i--)
#define ll long long
using namespace std;
const int N=5e5+5;
const ll inf=1e18;
int n,w[N],m,Cid,D,Q;
ll dis[505][505],ans;
vector<pr>to[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int K,x,y,T;
	cin>>Cid>>n>>m>>D>>Q;
	For(i,1,m) cin>>w[i];
	For(i,1,n)
	For(j,i+1,n)
		dis[i][j]=dis[j][i]=inf;
	For(i,1,n){
		cin>>K;
		while(K--){
			cin>>x>>T;
			to[x].push_back(mk(i,T));
		}
	}
//	return 0;
	For(i,1,m)
	for(pr j:to[i])
	for(pr k:to[i])
		dis[j.fi][k.fi]=min(dis[j.fi][k.fi],(ll)j.se+k.se);
	For(k,1,n)
	For(i,1,n)
	For(j,1,n)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(Q--){
		ans=inf;
		cin>>x>>y;
		for(pr i:to[x])
		for(pr j:to[y])
			ans=min(ans,i.se+dis[i.fi][j.fi]+j.se);
		cout<<ans+w[x]+w[y]<<'\n';
	} 
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
