#include <bits/stdc++.h>
using namespace std;

const int N=1010;

int c,T,n,vis[N],dis[N],sum[N];
long long d,x[N];

queue<int>q;
vector<int>a[N];

void bfs(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(sum,0,sizeof(sum));
	q.push(st);
	dis[st]=0; sum[st]=1;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=0;i<int(a[u].size());++i){
			int v=a[u][i];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				sum[v]=sum[u];
				q.push(v);
			}
			else if(dis[v]==dis[u]+1)
				sum[v]+=sum[u];
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;++i)
			scanf("%lld",&x[i]);
		for(int i=1;i<=n;++i)
			a[i].clear();
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(abs(x[i]-x[j])<=d){
					a[i].push_back(j);
					a[j].push_back(i);
				}
		
		int cnt=0;
		for(int i=1;i<=n;++i){
			bfs(i);
			for(int j=1;j<=n;++j)
				if(sum[j]==2)
					++cnt;
		}
		printf("%d\n",cnt/2);
	}
	return 0;
}
