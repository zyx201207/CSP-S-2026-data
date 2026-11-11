#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,k,ans,tmp[105],dis[105][105];
vector<int>ed[105];
bool in[105],vis[105],b[105];
void bj(int x){
	b[x]=true;
	for(int i:ed[x])
		if(in[i]&&!b[i]) bj(i);
}
bool check(){
	if(k!=2){
		memset(b,0,sizeof(b));
		bj(tmp[1]);
		for(int i=1;i<=k;i++){
			if(!b[tmp[i]]){
				bj(tmp[i]);
				break;
			}
		}
		for(int i=1;i<=k;i++)
			if(!b[tmp[i]]) return false;
	}
	return true;
}
int tqbj(){
	int Max=0;
	for(int i=1;i<=n;i++){
		if(in[i]) continue;
		int Min=998244353;
		for(int j=1;j<=k;j++) Min=min(Min,dis[i][tmp[j]]);
		Max=max(Max,Min);
	}
	return Max;
}
void dfs(int x){
	if(x==k+1){
		if(check()) ans=min(ans,tqbj());
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			tmp[x]=i;
			in[i]=true;
			dfs(x+1);
			vis[i]=false;
			in[i]=false;
		}
	}
}
queue<int>que;
bool yfw[105];
void cl(int x){
	memset(yfw,0,sizeof(yfw));
	que.push(x);
	yfw[x]=true;
	dis[x][x]=0;
	while(!que.empty()){
		int t=que.front();que.pop(); 
		for(int i:ed[t]){
			if(!yfw[i]){
				yfw[i]=true;
				dis[x][i]=dis[x][t]+1;
				que.push(i);
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		ans=998244353;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			ed[u].push_back(v);ed[v].push_back(u);
		}
		for(int i=1;i<=n;i++) cl(i);
		dfs(1);
		printf("%d\n",ans);
		for(int i=1;i<=n;i++) ed[i].clear();
	}
	return 0;
}