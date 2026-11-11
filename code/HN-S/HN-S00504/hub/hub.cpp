#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,dfn[15],b[15],vis[15],ans;
vector<int> e[15];
inline void df(int x){
	dfn[x]=1;
	for(auto i:e[x]){
		if(b[i]&&(!dfn[i])){
			df(i);
		}
	}
}
inline bool chk(){
	int col=0;
	for(int i=1;i<=n;i++){
		dfn[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(b[i]&&dfn[i]==0){
			col++;
			df(i);
		}
	}
	return col<=2;
}
inline void gx(){
	int res=0;
	for(int i=1;i<=n;i++){
		queue<int> q;
		memset(vis,0,sizeof(vis));
		q.push(i);
		vis[i]=1;
		while(!q.empty()){
			int t=q.front();
			q.pop();
			if(b[t]){
				res=max(res,vis[t]-1);
				break;
			}
			for(auto i:e[t]){
				if(!vis[i]){
					vis[i]=vis[t]+1;
					q.push(i);
				}
			}
		}
	} 
	ans=min(ans,res);
}
inline void dfs(int x,int su){
	if(x==n+1){
//		cout <<su << '\n';
		if(su==k&&chk()){
			gx();
		}
		return;
	}
	b[x]=1;
	dfs(x+1,su+1);
	b[x]=0;
	dfs(x+1,su);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		ans=INT_MAX;
		for(int i=1;i<n;i++){
			int x,y;
			cin >> x >> y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1,0);
		cout << ans << '\n';
	}
	return 0;
} 
