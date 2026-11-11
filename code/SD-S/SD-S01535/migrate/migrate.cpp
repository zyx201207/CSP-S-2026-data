#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ls(x) (x<<1)
#define rs(x) (x<<1 | 1)
#define mid ((l+r)>>1)

using namespace std;
typedef long long ll;
int _,T;
const int N=2e6+10;
const int INF=4e18;
int a[N];
vector<int> g[N];
int dis[N];
bool vis[N];
int cnt[N];
int n,d;
priority_queue<pii, vector<pii>, greater<pii> > q;
void bfs(int x){
	while(q.size()) q.pop();
	q.push(mp(0,x));
	for(int i=1; i<=n; i++){
		vis[i]=0;
	}
	for(int i=1; i<=n; i++){
		dis[i]=INF;
	}
	dis[x]=0;
	cnt[x]=1;

	while(q.size()){
		pii t=q.top();
		q.pop();
		int d=t.fi;
		int u=t.se;
		if(dis[u]!=d) continue;
		for(int v:g[u]){

			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push(mp(dis[v],v));
				cnt[v]=1;
			} 
			else if(dis[v]==dis[u]+1){
				cnt[v]++;
			}
		}
	}
	return;
}
void init(){
	for(int i=1; i<=n; i++) g[i].clear(),cnt[i]=0,dis[i]=0,vis[i]=0,a[i]=0;
	n=0,d=0;
	while(q.size()) q.pop();
	return;
}

void solve(){
	cin>>n>>d;

	for(int i=1; i<=n; i++){
		cin>>a[i];

	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<i; j++){
			if(abs(a[i]-a[j])<=d){
				g[i].pb(j);
				g[j].pb(i);
				//cout<<i<<" "<<j<<"\n";
			} 
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		bfs(i);
//		for(int j=1; j<=n; j++){
//			cout<<dis[j]<<" ";
//		}
		for(int j=1; j<=n; j++){
			if(i==j) continue;
			if(cnt[j]==2){
				ans++;
			}
		}
		//cout<<"\n";
	}
	cout<<ans/2<<"\n";
	init();
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>_>>T;
	while(T--) solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
