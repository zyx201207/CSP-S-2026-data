#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int>G[214514];
bool vis[20];
int ans[20];
vector<int>vec;
int _get(int x){
	int res=0;
	while(x){
		if(x&1){
			res++;
		}
		x>>=1;
	}
	return res;
}
void dfs(int u){
	vis[u]=1;
	for(int v:G[u]){
		if(vis[v]||!binary_search(vec.begin(),vec.end(),v))continue;
		dfs(v);
	}
}
bool check(){
	memset(vis,0,sizeof vis);
	int cnt=0;
	for(int i=0;i<vec.size();i++){
		if(!vis[vec[i]]){
			dfs(vec[i]);
			cnt++;
		}
	}
	return cnt<=2;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int mn=0x3f3f3f3f;
		for(int i=1;i<(1<<n);i++){
			if(_get(i)==k){
				int mx=0;
				vec.clear();
				memset(ans,0,sizeof ans);
				memset(vis,0,sizeof vis);
				queue<int>q;
				for(int j=1;j<=n;j++){
					if(i>>(j-1)&1){
						q.push(j);
						vis[j]=1;
						vec.push_back(j);
					}
				}
				while(!q.empty()){
					int u=q.front();q.pop();
					for(int v:G[u]){
						if(vis[v])continue;
						vis[v]=1;
						ans[v]=ans[u]+1;
						q.push(v);
					}
				}
				for(int j=1;j<=n;j++){
					mx=max(mx,ans[j]);
				}
				if(check()){
					mn=min(mn,mx);
				}
				
			}
			
		}
		cout<<mn<<'\n';
		for(int i=1;i<=n;i++)G[i].clear();
	}
	return 0;
}