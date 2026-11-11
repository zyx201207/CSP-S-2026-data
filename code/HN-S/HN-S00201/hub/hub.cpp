#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,u,v,ans,vis[105];
vector<int> e[105];
int bianli(int x,int fa){
	if(vis[x]){
		return 0;
	}
	int res=1e9;
	for(auto i:e[x]){
		if(i!=fa){
			res=min(res,bianli(i,x)+1);
		}
	}
	return res;
}
void bianli22(int x,int fa){
	if(!vis[x]){
		return;
	}
	vis[x]=0;
	for(auto i:e[x]){
		if(i!=fa){
			bianli22(i,x);
		}
	}
}
void dfs(int x,int s){
	if(s==k){
		int res=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				res=max(res,bianli(i,-1));
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i]){
				cnt++;
				bianli22(i,-1);
			}
		}
		if(cnt<=2){
			ans=min(ans,res);
		}
		return;
	}
	if(x>n){
		return;
	}
	vis[x]=1;
	dfs(x+1,s+1);
	vis[x]=0;
	dfs(x+1,s);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=30;i++){
			e[i].clear();
		}
		for(int i=1;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		ans=INT_MAX;
		memset(vis,0,sizeof vis);
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
67 83 80 82 80 43 61 73 78 70 70 33
*/
