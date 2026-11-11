#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
constexpr int mod=998244353;
inline int MOD(int a){return (a%mod+mod)%mod;}
inline int add(int a,int b){return (a+b)%mod;}
inline int red(int a,int b){return (a-b+mod)%mod;}
inline int mul(int a,int b){return a*b%mod;}
constexpr int N=2e6+5;
int n,k,a[N],vis[N],mn,dis[N],vq[N];
vector<int>e[N];
struct edge{int u,v;}eg[N];
void dfs(int x,int sum){
	if(sum>k)return;
	if(x==n+1){
		if(sum==k){
			int dt=k;
			for(int i=1;i<n;i++){
				int u=eg[i].u,v=eg[i].v;
				if(!vis[u]||!vis[v])continue;
				dt--;
			}
			if(dt>2)return;
			queue<int>q;
			for(int i=1;i<=n;i++){
				dis[i]=1e18;
				vq[i]=0;
			}
			for(int i=1;i<=k;i++){
				dis[a[i]]=0;
				vq[a[i]]=1;
				q.push(a[i]);
			}
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int i=0;i<(int)e[u].size();i++){
					int v=e[u][i];
					if(vq[v])continue;
					vq[v]=1;
					dis[v]=dis[u]+1;
					q.push(v);
				}
			}
			int mx=-1e18;
			for(int i=1;i<=n;i++)mx=max(mx,dis[i]);
			mn=min(mn,mx);
		}
		return;
	}
	a[sum+1]=x;
	vis[x]=1;
	dfs(x+1,sum+1);
	vis[x]=0;
	dfs(x+1,sum);
}
void solve(){
	for(int i=1;i<=n;i++)e[i].clear();
	mn=1e18;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		eg[i]={u,v};
	}
	dfs(1,0);
	cout<<mn<<endl;
}
/*
*/
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T=1;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
