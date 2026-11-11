#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	return x;
}
const int N=1e6+10;
vector<int> e[N];
int n,k,ans=-1,vis[N],fa[N],vis2[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int check(){
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		for(auto j:e[i]){
			if(!vis[j]) continue;
			int u=find(i),v=find(j);
			if(u!=v) fa[u]=v;
		}
	}
	int cnt=0,res=0;
	for(int i=1;i<=n;i++) if(i==fa[i]&&vis[i]) cnt++;
	if(cnt>2||cnt==0) return -1; 
	for(int i=1;i<=n;i++){
		queue<pair<int,int> > q;
		q.push({i,0}),vis2[i]=1;
		while(!q.empty()){
			int x=q.front().first,y=q.front().second;
			q.pop();
			if(vis[x]){
				res=max(res,y);
				break;
			}
			for(auto j:e[x]){
				if(vis2[j]) continue;
				vis2[j]=1,q.push({j,y+1});
			}
		}
		for(int i=1;i<=n;i++) vis2[i]=0;
	}
	return res;
}
void dfs(int x,int d){
	if(d>k) return ;
	if(x==n+1){
		int res=check();
		if(res!=-1){
			if(ans==-1) ans=res;
			else ans=min(ans,res);
		}
		return ;
	}
	vis[x]=1,dfs(x+1,d+1);
	vis[x]=0,dfs(x+1,d);
	return ;
}
void work(){
	n=read(),k=read(),ans=-1;
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	cout <<ans<<"\n";
	for(int i=1;i<=n;i++) e[i].clear();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while(t--) work();
	return 0;
}