#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,dis[40005],o1,o2;
vector<int>g[40005];
int a[40005];
bool is[40005];
queue<int>q;
inline void BFS(){
	for(int i=1;i<=n;++i)if(is[i])q.push(i),dis[i]=0;
	while(q.size()){
		int t=q.front();
		q.pop();
		for(int v:g[t]){
			if(dis[v]>n)dis[v]=dis[t]+1,q.push(v);
		}
	}
}int check(){
	for(int i=1;i<=n;++i)is[i]=0,dis[i]=1e9;
	for(int i=1;i<=k;++i)is[a[i]]=1;
	int cnt=k,maxn=0;
	BFS();
	for(int i=1;i<=n;++i){
		maxn=max(maxn,dis[i]);
		for(int j:g[i]){
			if(is[i]&&is[j]&&i<j){
				--cnt;
			}
		}
	}if(cnt<=2)return maxn;
	else return 1e9;
}int dfs(int stp,int cnt){
	if(stp>n){
		if(cnt==k)return check();
		else return 1e9;
	}int ret=1e9;
	if(n-stp+1+cnt>k)ret=min(ret,dfs(stp+1,cnt));
	a[cnt+1]=stp;
	if(cnt<k)ret=min(ret,dfs(stp+1,cnt+1));
	return ret;
}signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}if(n<=10){
			printf("%d\n",dfs(1,0));
		}else{
			int minx=1e9;
			for(o1=1;o1<=n;++o1){
				for(o2=o1+1;o2<=n;++o2){
					int maxn=0;
					for(int i=1;i<=n;++i)dis[i]=1e9,is[i]=0;
					is[o1]=is[o2]=1;
					BFS();
					for(int i=1;i<=n;++i){
						maxn=max(maxn,dis[i]);
					}minx=min(minx,maxn);
				}
			}printf("%d\n",minx);
		}for(int i=1;i<=n;++i)g[i].clear();
	}
}