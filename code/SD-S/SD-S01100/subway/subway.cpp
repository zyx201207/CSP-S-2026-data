#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
void IOS(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
const int N=505;
const int M=5e5+5;
const int INF=1e18;
int c,n,m,d,q1,a[M];
struct mp{
	int v,w;
};
vector<mp> g[M+N];
struct node{
	int num,dis;
	bool operator <(const node &b) const{
		return b.dis<dis;
	}
};
priority_queue<node> q;
int dis[N+M];
bool vis[N+M];
void dij(int st){
	for(int i=1;i<=m+n;++i)vis[i]=0,dis[i]=INF;
	node kl;
	kl.num=st,kl.dis=0;
	dis[st]=0;
	q.push(kl);
	while(!q.empty()){
		kl=q.top();
		q.pop();
		int p=kl.num;
		if(vis[p])continue;
		vis[p]=1;
		for(auto i:g[p]){
			if(dis[i.v]>dis[p]+i.w){
				dis[i.v]=dis[p]+i.w;
				kl.dis=dis[i.v];
				kl.num=i.v;
				q.push(kl);
			}
		}
	}
}
pair<pair<int,int>,int> kl[100005];
int ans[100005];
queue<int> qb;
void bfs(int st){
	for(int i=1;i<=n+m;++i)vis[i]=0,dis[i]=INF;
	qb.push(st);
	dis[st]=0;
	vis[st]=1;
	while(!qb.empty()){
		int p=qb.front();
		qb.pop();
		for(auto i:g[p]){
			if(vis[i.v])continue;
			vis[i.v]=1;
			dis[i.v]=dis[p]+1;
			qb.push(i.v);
		}
	}
}
signed main(){
	IOS();
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1,v,w;j<=k;++j){
			cin>>v>>w;
			g[i+m].push_back({v,w});
			g[v].push_back({i+m,w});
		}
	}
	for(int i=1;i<=q1;++i){
		cin>>kl[i].fi.fi>>kl[i].fi.se;
		if(kl[i].fi.fi>kl[i].fi.se)swap(kl[i].fi.fi,kl[i].fi.se);
		kl[i].se=i;
	}
	sort(kl+1,kl+1+q1);
	int k=0;
	for(int i=1;i<=q1;++i){
		if(kl[i].fi.fi!=k){
			k=kl[i].fi.fi;
			dij(k);
		}
		ans[kl[i].se]=a[k]+a[kl[i].fi.se]+dis[kl[i].fi.se];
	}
	for(int i=1;i<=q1;++i)cout<<ans[i]<<"\n";
	return 0;
}
