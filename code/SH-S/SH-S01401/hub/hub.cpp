#include<bits/stdc++.h>
using namespace std;
int c,t,n,kk;
bool exist[32],vst[32];
vector<int> uv[32];
void dfs(int x){
	if(vst[x]) return;
	vst[x]=1;
	for(int i=0;i<uv[x].size();i++){
		if(exist[uv[x][i]]) dfs(uv[x][i]);
	}
	return;
}
struct Node{
	int d,u;
};
queue<Node> q;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>kk;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			uv[u].push_back(v);
			uv[v].push_back(u);
		}
		int ans=1e9;
		for(int i=1;i<(1<<n);i++){
			int cc=0;
			for(int j=0;j<n;j++){
				exist[j+1]=i&(1<<j);
				if(i&(1<<j)) cc++;
			}
			if(cc!=kk) continue;
			int bl=0;
			for(int j=1;j<=n;j++) vst[j]=0;
			for(int j=1;j<=n;j++){
				if(exist[j]&&!vst[j]){
					bl++;
					if(bl==3) break;
					dfs(j);
				}
			}
			if(bl==3) continue;
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(exist[j]) continue;
				for(int k=1;k<=n;k++) vst[k]=0;
				q.push((Node){0,j});
				while(!q.empty()){
					Node nw=q.front();
					q.pop();
					if(exist[nw.u]){
						cnt=max(cnt,nw.d);
						while(!q.empty()) q.pop();
						break;
					}
					if(vst[nw.u]) continue;
					vst[nw.u]=1;
					for(int k=0;k<uv[nw.u].size();k++){
						q.push((Node){nw.d+1,uv[nw.u][k]});
					}
				}
			}
			ans=min(ans,cnt);
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) uv[i].clear();
	}
	return 0;
}
