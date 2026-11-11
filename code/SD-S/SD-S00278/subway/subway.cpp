#include<bits/stdc++.h>
#define ll long long
#define infll 0x3f3f3f3f3f3f3f3f
#define N 600005
#define M 2000005
#define endl '\n'
#define ls root<<1
#define rs root<<1|1
#define F first
#define S second
using namespace std;
ll cc,n,m,d,q,w[N],a[N],t[N],ans[N];
ll xx[N],yy[N];
ll dis[N];
bool vis[N];
vector<pair<ll,ll> > v[N];
void dij(ll s){
	for(int i=1;i<=n+m;i++){
		vis[i]=0;dis[i]=infll;
	}
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
	q.push({0,s});dis[s]=0;
	while(!q.empty()){
		ll x=q.top().S;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=0;i<v[x].size();i++){
			ll to=v[x][i].F,len=v[x][i].S;
			if(dis[to]>dis[x]+len){
				dis[to]=dis[x]+len;
				q.push({dis[to],to});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		ll k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			v[a[j]].push_back({m+i,t[j]});
			v[m+i].push_back({a[j],t[j]});	
		}
	}
	for(int i=1;i<=q;i++) cin>>xx[i]>>yy[i];
	memset(ans,0x3f,sizeof ans);
	for(int i=1;i<=n;i++){
		dij(i+m);
		for(int i=1;i<=q;i++){
			ans[i]=min(ans[i],dis[xx[i]]+dis[yy[i]]+w[xx[i]]+w[yy[i]]);
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
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
*/

