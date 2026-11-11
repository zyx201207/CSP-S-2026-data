#include<bits/stdc++.h>
#define ll long long
#define N 2000
const ll INF=1e18;
using namespace std;
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
struct Query{int l,r,id;}ask[100100];vector<Query>tong_ask[100100];
struct node{int x;ll val;};vector<node>v[10001000];priority_queue<node>q;
bool operator<(node a,node b){return a.val>b.val;}
int c,n,m,l,r,d,Q,len,k[505],w[500100],cnt[500100];bool vis[10001000];
ll ans[100100],dis[10001000];
vector<int>a[N],t[N],A[N];set<int>S;
vector<node>que[500100];
void bfs(int s){
	for(auto g:S)dis[g]=INF,vis[g]=false;;
	dis[s]=0,vis[s]=0;q.push({s,0});
	while(!q.empty()){
		node u=q.top();q.pop();
		if(vis[u.x])continue;vis[u.x]=true;
		for(auto g:v[u.x]){
			if(vis[g.x])continue;
			if(dis[g.x]>dis[u.x]+g.val){
				dis[g.x]=dis[u.x]+g.val;
				q.push({g.x,dis[g.x]});
			}
		}
	}
	for(auto g:tong_ask[s])ans[g.id]=dis[g.r]+w[g.l]+w[g.r];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),Q=read();
	for(int i=1;i<=m;++i)w[i]=read();
	for(int i=1;i<=n;++i){
		k[i]=read();
		a[i].push_back(0),t[i].push_back(0),A[i].push_back(0);
		for(int j=1;j<=k[i];++j)
			a[i].push_back(read()),t[i].push_back(read());
		for(int j=1;j<=k[i];++j)A[i].push_back(a[i][j]+(++cnt[a[i][j]])*m),S.insert(A[i][j]),S.insert(a[i][j]);
		for(int j=1;j<=k[i];++j)
			v[a[i][j]].push_back({A[i][j],t[i][j]}),
			v[A[i][j]].push_back({a[i][j],t[i][j]});
		for(int j=1;j<=k[i]-1;++j)
			v[A[i][j]].push_back({A[i][j+1],0});
		for(int j=1;j<=k[i];++j)que[a[i][j]].push_back({A[i][j],t[i][j]});
	}
	for(int k=1;k<=m;++k){
		len=que[k].size();
		for(int i=0;i<=len-1;++i)
			for(int j=i+1;j<=len-1;++j){
				v[que[k][i].x].push_back({que[k][j].x,que[k][i].val+que[k][j].val});
				v[que[k][j].x].push_back({que[k][i].x,que[k][i].val+que[k][j].val});
			}
	}
	for(int i=1;i<=Q;++i)ask[i]={read(),read(),i},tong_ask[ask[i].l].push_back(ask[i]);
	for(int i=1;i<=m;++i)if(tong_ask[i].size())bfs(i);
	for(int i=1;i<=Q;++i)cout<<ans[i]<<"\n";
	return 0;
}

