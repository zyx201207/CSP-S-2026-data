#include<bits/stdc++.h>
using namespace std;
int c,ttt;
int n,k,idx;
int ans=2147483647;
int h[1145141],ne[2333333],to[2333333];
int dis[1145141];
bool builded[1145141];
vector<int> path;
void insert(int a,int b){
	to[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
struct node{
	int x;
	int step;
};
int bfs(int start){
	memset(dis,0x3f,sizeof dis);
	dis[start]=0;
	if(builded[start]) return 0;
	queue<node> q;
	q.push({start,0});
	while(!q.empty()){
		node op=q.front();
		q.pop();
		if(builded[op.x]) return op.step;
		for(int i=h[op.x];i!=-1;i=ne[i]){
			int e=to[i];
			if(op.step+1<dis[e]){
				dis[e]=op.step+1;
				q.push({e,op.step+1});
			}
		}
	}
}
void dfs(int now,int cnt){
	if(cnt==k){
		memset(builded,false,sizeof builded);
		for(auto i:path){
			builded[i]=true;
		}
		int ltk=k;
		for(auto i:path){
			builded[i]=false;
			for(int j=h[i];j!=-1;j=ne[j]){
				if(builded[to[j]]){
					builded[to[j]]=false;
					ltk--;
				}
			}
		}
		for(auto i:path){
			builded[i]=true;
		}
		if(ltk>2){
			return ;
		}
		int maxx=-1;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,bfs(i));
		}
		ans=min(ans,maxx);
		return ;
	}
	if(now==n+1){
		return ;
	}
	path.push_back(now);
	dfs(now+1,cnt+1);
	path.pop_back();
	dfs(now+1,cnt);
}
void solve(){
	memset(h,-1,sizeof h);
	memset(ne,0,sizeof ne);
	memset(to,0,sizeof to);
	idx=0;
	ans=2147483647;
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		insert(u,v);
		insert(v,u);
	}
	path.clear();
	dfs(1,0);
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&ttt);
	while(ttt--){
		solve();
	}
	return 0;
}
