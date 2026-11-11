#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,c,m,k,qq,t,tag[N],dis[N],dit[N][N],tg[N];
vector<int> v[N];
int s[N],top,vis[N],minn=0x3f3f3f3f,cnt;
void check(int x){
	cnt++;
	if(cnt==k) return ;
	tg[x]=1;
	for(int i=0;i<v[x].size();i++){
		int xx=v[x][i];
		if(!tg[xx]&&vis[xx]){
			check(xx);
		}
	}
}
void dfs(int x){
	if(x>k){
		int maxn=-1,b=0;
		cnt=0;
		memset(tg,0,sizeof(tg));
		for(int i=1;i<=k;i++){
			if(!tg[s[i]]){
				b++;
				if(b>2) return ;
				check(s[i]);
				if(cnt==k) break;
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i]) maxn=max(maxn,0);
			else{
				int minx=0x3f3f3f3f;
				for(int j=1;j<=k;j++){
					minx=min(dit[i][s[j]],minx);
				}
				maxn=max(maxn,minx);
			} 
		}
		minn=min(maxn,minn);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		s[x]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
queue<int> q;
int bfs(int x,int y){
	while(!q.empty()) q.pop();
	memset(tag,0,sizeof(tag));
	memset(dis,0,sizeof(dis));
	q.push(x);
	dis[x]=0;
	tag[x]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(u==y) return dis[y];
		for(int i=0;i<v[u].size();i++){
			int xx=v[u][i];
			if(!tag[xx]){
				q.push(xx);
				dis[xx]=dis[u]+1;
				tag[xx]=1;
			}
		}
	}
	return dis[y];
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		minn=0x3f3f3f3f;
		memset(dit,0,sizeof(dit));
		memset(vis,0,sizeof(vis));
		scanf("%d %d",&n,&k);
		for(int i=1;i<n;i++){
			int u,vv;
			scanf("%d %d",&u,&vv);
			v[u].push_back(vv);
			v[vv].push_back(u);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dit[i][j]=bfs(i,j);
				dit[j][i]=dit[i][j];
			}
		}
		dfs(1);
		printf("%d\n",minn);
		for(int i=1;i<=n;i++) v[i].clear();
	} 
	return 0;
}
