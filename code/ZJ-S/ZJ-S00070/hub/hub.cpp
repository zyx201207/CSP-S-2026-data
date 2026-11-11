#include<bits/stdc++.h>
using namespace std;

int c,t,n,k,dist[1000005],d[1000005],vis[1000005];
vector<int> edges[1000005];
bool ch[1000005];

void bfs(int x){
	queue<int> q;
	q.push(x);
	for(int i=1;i<=n;i++)
		vis[i]=0,dist[i]=-1;
	dist[x]=0;
	while(!q.empty()){
		int cur=q.front();q.pop();
		for(auto i:edges[cur]){
			if(vis[i])
				continue;
			dist[i]=dist[cur]+1;
			vis[i]=1;
			q.push(i);
		}
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(;t--;){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			d[i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		if(k==2){
			int ans=INT_MAX;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j)
						continue;
					for(int l=1;l<=n;l++){
						if(l==i||l==j){
							d[l]=0;
							continue;
						}
						bfs(l);
						d[l]=min(dist[j],dist[i]);
					}
					int sum=0;
					for(int i=1;i<=n;i++)
						sum=max(sum,d[i]);
					ans=min(ans,sum);
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}