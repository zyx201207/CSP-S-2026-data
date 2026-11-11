#include<bits/stdc++.h>
#define int long long
#define double long double
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int N=2e6+10;
int n,d;
int x[N];
vector<int>g[N];
int dis[N];
bool vis[N];
int cnt[N];
priority_queue<pii>pq;
int dij(int s){
	for(int i=1;i<=n;i++){
		dis[i]=0x3f3f3f3f3f3f3f3f;
		vis[i]=0;
		cnt[i]=0;
	}
	dis[s]=0;
	cnt[s]=1;
	pq.push({0,s});
	while(pq.size()){
		int u=pq.top().se;
		pq.pop();
		if(vis[u])continue ;
		vis[u]=1;
		for(int v:g[u]){
			int ww=1;
			if(vis[v])continue ;
			if(dis[v]>dis[u]+ww){
				dis[v]=dis[u]+ww;
				cnt[v]=cnt[u];
				pq.push({-dis[v],v});
			}else if(dis[v]==dis[u]+ww){
				cnt[v]+=cnt[u];
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(cnt[i]==2)res++;
	}
	return res;
}
void solve1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=dij(i);
	}
	cout<<ans/2<<endl;
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c=0,T=0;
	cin>>c>>T;
	while(T--){
		solve1();
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
