#include<bits/stdc++.h>
#define ll long long
#define infll 0x3f3f3f3f3f3f3f3f
#define N 500005
#define M 2000005
#define endl '\n'
#define ls root<<1
#define rs root<<1|1
#define F first
#define S second
using namespace std;
ll cc,t,n,d,x[N],ans;
vector<ll> v[N];
ll dis[N],cnt[N];
bool vis[N];
void dij(ll s){
	for(int i=1;i<=n;i++){
		vis[i]=cnt[i]=0;
		dis[i]=infll;
	}
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
	q.push({0,s});dis[s]=0;cnt[s]=1;
	while(!q.empty()){
		ll x=q.top().S;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=0;i<v[x].size();i++){
			ll to=v[x][i];
			if(dis[to]==dis[x]+1){
				cnt[to]+=cnt[x];
				q.push({dis[to],to});
			}
			else if(dis[to]>dis[x]+1){
				dis[to]=dis[x]+1;
				cnt[to]=cnt[x];
				q.push({dis[to],to});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cc>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2) ans++; 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

