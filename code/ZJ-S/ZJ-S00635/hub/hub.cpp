#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,dep[1000005],mx[1000005],mxd[1000005],ma[1000005],nxt[1000005],ans,dis[1000005];
bool vis[1000005],fl[1000005];
vector<int>e[1000005];
void DFS(int x,int fa){
	for(auto y:e[x]){
		if(y==fa)continue;
		dep[y]=dep[x]+1;DFS(y,x);
	}
}
void dfs(int x){
	vis[x]=1;
	for(auto y:e[x]){
		if(dep[y]<dep[x])continue;
		dfs(y);
	}
}
void dfsrt(int x){
	for(auto y:e[x]){
		if(dep[y]<dep[x])continue;
		dep[y]=dep[x]+1;dfsrt(y);
	}
}
void solve(int x,int lim){
	ma[x]=0;
	for(auto y:e[x]){
		if(dep[y]<dep[x])continue;
		if(fl[y])continue;
		solve(y,lim),ma[x]=max(ma[x],ma[y]+1);
	}
	if(ma[x]>=lim)fl[x]=1;
}
void work(int x,int lim){
	ma[x]=0;
	for(auto y:e[x]){
		if(dep[y]<dep[x])continue;
		work(y,lim);if(fl[y])continue;
		ma[x]=max(ma[x],ma[y]+1);
	}
	if(ma[x]>=lim)fl[x]=1;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==7||c==11||c==12){
		while(t--){
			scanf("%d%d",&n,&k);
			for(int i=1;i<n;i++){
				int x,y;scanf("%d%d",&x,&y);
				e[x].push_back(y),e[y].push_back(x);
			}DFS(1,0);ans=1e9;
			for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dep[j]=1e9;dep[i]=0;dfsrt(i);
			int L=0,R=ans;
			while(L<=R){
				int mid=L+R>>1,val=0;for(int j=1;j<=n;j++)fl[j]=0;
				fl[i]=1;work(i,mid);for(int j=1;j<=n;j++)if(fl[j])val++;
				if(val>k)L=mid+1;else
				R=mid-1,ans=min(ans,mid);
			}
		}
			printf("%d\n",ans);
			for(int i=1;i<=n;i++)e[i].clear();
		}
		return 0;
	}
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int x,y;scanf("%d%d",&x,&y);
			e[x].push_back(y),e[y].push_back(x);
		}
		DFS(1,0);ans=1e9;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dis[j]=1e9,vis[j]=0;dfs(i);
			dis[i]=0;queue<int>q;
			q.push(i);
			while(!q.empty()){
				int x=q.front();q.pop();
				for(auto y:e[x])
				if(dis[y]>dis[x]+1)dis[y]=dis[x]+1,q.push(y);
			}
			int L=0;
			for(int j=1;j<=n;j++)if(!vis[j])L=max(L,dis[j]);
			if(L>=ans)continue;
			int R=ans;
			while(L<=R){
				for(int l=1;l<=n;l++)fl[l]=0;
				int mid=L+R>>1,val=0;fl[i]=1;
				solve(i,mid);
				for(int l=1;l<=n;l++)if(vis[l]&&fl[l])val++;
				if(val>k)L=mid+1;else
				R=mid-1,ans=min(ans,mid);
			}
		}
		for(int i=1;i<=n;i++)
		for(int z=i+1;z<=n;z++){
			for(int j=1;j<=n;j++)dis[j]=1e9,vis[j]=0;dfs(i),dfs(z);
			dis[i]=dis[z]=0;queue<int>q;
			q.push(i),q.push(z);
			while(!q.empty()){
				int x=q.front();q.pop();
				for(auto y:e[x])
				if(dis[y]>dis[x]+1)dis[y]=dis[x]+1,q.push(y);
			}
			int L=0;
			for(int j=1;j<=n;j++)if(!vis[j])L=max(L,dis[j]);
			if(L>=ans)continue;
			int R=ans;
			while(L<=R){
				for(int l=1;l<=n;l++)fl[l]=0;
				int mid=L+R>>1,val=0;fl[i]=1;fl[z]=1;
				if(dep[i]>dep[z])solve(i,mid),solve(z,mid);else
				solve(z,mid),solve(i,mid);
				for(int l=1;l<=n;l++)if(vis[l]&&fl[l])val++;
				if(val>k)L=mid+1;else
				R=mid-1,ans=min(ans,mid);
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)e[i].clear();
	}
	return 0;
}