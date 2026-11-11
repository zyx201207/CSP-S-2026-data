#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,T,n,k,ans,t[N],dis[N];
bool used[N],cv[N];
queue<int> q;
vector<int> e[N];
int bfs(){
	for(int i=1;i<=n;i++) dis[i]=n+1;
	//init
	for(int i=1;i<=k;i++) q.push(t[i]),dis[t[i]]=0;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int v:e[u])
			if(dis[v]>dis[u]+1) dis[v]=dis[u]+1,q.push(v);
	}
	int mx=0;
	for(int i=1;i<=n;i++)
		mx=max(mx,dis[i]);
	return mx;
}
void dfs(int cnt){
	if(cnt==k+1){
		for(int i=1;i<=n;i++) cv[i]=0;
		//init
		int m=0; //cout<<"new\n";
		for(int i=1;i<=n;i++)
			if(used[i]) t[++m]=i;//,cout<<i<<" ";
		int s=0; q.push(t[1]);
		while(!q.empty()){
			int u=q.front(); q.pop();
			cv[u]=1;s++;
			for(int v:e[u])
				if(used[v] && !cv[v]) q.push(v);
		}
		int pos=0;
		for(int i=1;i<=k;i++)
			if(!cv[t[i]]) pos=t[i];
		if(pos){
			q.push(pos);
			while(!q.empty()){
				int u=q.front(); q.pop();
				cv[u]=1;s++;
				for(int v:e[u])
					if(used[v] && !cv[v]) q.push(v);
			}
		}
		if(s<k) return;
//		cout<<bfs()<<"\n";
		ans=min(ans,bfs());
		return;
	}
	for(int i=1;i<=n;i++)
	if(!used[i]){
		used[i]=1;
		dfs(cnt+1);
		used[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		//init
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(k==n){printf("0\n");continue;}
		if(k>=n/2){printf("1\n");continue;}
		ans=n+1;
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
