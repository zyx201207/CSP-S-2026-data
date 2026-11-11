#include<bits/stdc++.h>
using namespace std;
#define int long long
int b[114],idx,n,k;
vector<vector<int>>ng;
vector<vector<int>>g;
vector<int>p;
vector<int>vic,sy;
void ds(int x){
	vic[x]=1;
	for(int i:g[x]){
		if(vic[i]==1||sy[i]==0)continue;
		ds(i);
	}
}
bool check(){
	vic=sy=vector<int>(n+1);
	int cnt=0;
	for(int c:p)sy[c]=1;
	for(int c:p)if(vic[c]==0)ds(c),cnt++;
	if(cnt<=2)return 1;
	return 0;
}
void dfs(int x,int n,int k){
	if(x==k){
		int o=1;p.clear();
		for(int i=1;i<=k;i++){
			p.push_back(b[i]);
			if(b[i]==0)o=0;
		}if(o&&check())ng.push_back(p);
		return ;
	}
	for(int i=b[x]+1;i<=n;i++){
		b[x+1]=i;
		dfs(x+1,n,k);
		b[x+1]=0;
	}
}
void solve(){
	cin>>n>>k;
	if(n<=30){
		g=vector<vector<int>>(n+1);
		ng.clear();
		idx=0;
		int ans=1e18;
		for(int i=1;i<=k;i++)b[i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}dfs(0,n,k);
		for(int i=0;i<ng.size();i++){
			vector<int>deep(n+1,1e18),vis(n+1);
			queue<int>q;
			for(int c:ng[i]){
				deep[c]=0;
				q.push(c);
				vis[c]=1;
			}int u=0;
			while(q.size()){
				int t=q.front();q.pop();
				u=max(u,deep[t]);
				for(int c:g[t]){
					if(deep[c]==1e18){
						deep[c]=deep[t]+1;
						q.push(c);
					}
				}
			}
			ans=min(ans,u);
		}
		cout<<ans<<'\n';
		return;
	}
	int ox=1,m=0;
	if(!(n&1))ox=0;
	else m=n/2;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		if(i<=m&&(u!=i||v!=i+1))ox=0;
		if(i>m&&(u!=i-m||v!=i+1))ox=0;
	}
	if(ox==0){cout<<(n-k)/3+1<<'\n';return;}
	cout<<(m-k)/3+1<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}


