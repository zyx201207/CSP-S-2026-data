#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1000006;
const int maxm=(maxn<<1);
struct node{
	int to,nxt;
}edge[maxm];
int head[maxn],n,k,c,T,cnt,ans;
bool b[maxn],v[maxn];
inline void add(int u,int v){
	cnt++;
	edge[cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}        
inline void dfs_mark(int x,int fa){
	v[x]=1;
	for(int i=head[x];i;i=edge[i].nxt){
		int y=edge[i].to;
		if(y==fa||v[y]||b[y]==0)continue;
		dfs_mark(y,x);
	}
}
inline int dfs_dis(int x,int fa){
//	cerr<<x<<"0453\n";
	if(b[x])return 0;
	int dist=10000000000;
	for(int i=head[x];i;i=edge[i].nxt){
		int y=edge[i].to;
		if(y==fa)continue;
		dist=min(dist,dfs_dis(y,x));
	}
	return dist+1;
}
inline void solve(){
	int tot=0;
	for(int i=1;i<=n;i++){
		v[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(b[i]&&v[i]==0){
			dfs_mark(i,0);
			tot++;
		}
	}
	if(tot!=2)return;
	int cost=-1;
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			cost=max(cost,dfs_dis(i,0));
//			if(T==0)cerr<<dfs_dis(i,0)<<'\n';
		}
	}
	ans=min(ans,cost);
}
inline void dfs(int i,int x,int cnt){
	if(i==n){
		if(cnt!=k)return;
		for(int j=1;j<=n;j++){
			if(x&(1<<j))b[j]=1;
			else b[j]=0;
		}
		solve();
		return;
	}
	dfs(i+1,x,cnt);
	if(cnt<k){
		dfs(i+1,x|(1<<(i+1)),cnt+1);
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		cnt=0;
		memset(head,0,sizeof head);
		memset(edge,0,sizeof edge);
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		ans=LLONG_MAX;
		dfs(0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
