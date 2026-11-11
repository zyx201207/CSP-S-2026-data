#include<bits/stdc++.h>
#define int long long
#define endl '\n';
using namespace std;
//priority_queue<int>q;
int c,t,n,k,vis[100010],viss[100010],tt[100010],f[10010],ans=1e18;
vector<int>G[100010];
int ye;
void dfs(int x,int fa){
	f[x]=fa;
	int cnt=0;
	for(int y:G[x]){
		if(y!=fa){
			cnt++;
			dfs(y,x);
		}
	}
	if(cnt==0){
		ye++;
	}
}
void dfsss(int x){
	for(int y:G[x]){
		if(tt[y]==-1){
			tt[y]=tt[x]+1;
			dfsss(y);
		}
	}
}
void dff(int x){
	for(int y:G[x]){
		if(vis[y]==1&&viss[y]==0){
			viss[y]=1;
			dff(y);
		}
	}
}
void dfss(int x){
	if(x==k){
		int anss=0;
		memset(viss,0,sizeof(viss));
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1&&viss[i]==0){
				dff(i);
				cnt++;
			}
		}
		if(cnt>2){
			return;
		}
		for(int i=1;i<=n;i++){
			tt[i]=vis[i]-1;
		}
		for(int i=1;i<=n;i++){
			if(tt[i]==0)dfsss(i);
		}
		for(int i=1;i<=n;i++){
			anss=max(anss,tt[i]);
		}
		ans=min(ans,anss);
	}else{
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				dfss(x+1);
				vis[i]=0;
			}
		}
	}
}
void solve(){
	memset(vis,0,sizeof(vis));
	ye=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)G[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(k==n){
		cout<<0<<endl;
		return;
	}
	dfs(1,0);
	if(k>=n-ye){
		cout<<1<<endl;
		return;
	}
	dfss(0);
	cout<<ans<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}

