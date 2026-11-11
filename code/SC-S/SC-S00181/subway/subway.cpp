#include<bits/stdc++.h>
#define int long long
using namespace std;
struct E{
	int to,nxt,w;
}edge[2001005];
int head[2001005];
int vis[1000505],dis[1000505];
int c,n,m,d,q,cnt=1;
void add(int u,int v,int w){
	edge[cnt]={v,head[u],w};
	head[u]=cnt++;
}
deque<int>p;
void spfa(int x){
	vis[x]=1;
	dis[x]=0;
	p.push_back(x);
	while(!p.empty()){
		int u=p.front();
		//cout<<u<<" "<<endl;
		p.pop_front();
		vis[u]=0;
		for(int i=head[u];~i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].w){
				dis[v]=dis[u]+edge[i].w;
				if(!vis[v]){
					vis[v]=1;
					if(!p.empty() && dis[v]<=p.front())p.push_front(v);
					else p.push_back(v);
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	memset(head,-1,sizeof head);
	for(int i=1;i<=m;i++){
		int x;
		scanf("%lld",&x);
		add(i,i+500000,x);
		add(i+500000,i,x);//1~500000,500001~1000000
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%lld%lld",&a,&t);
			add(a+500000,i+1000000,t);
			add(i+1000000,a+500000,t);
		}
	}
	while(q--){
		p.clear();
		memset(vis,0,sizeof vis);
		for(int i=1;i<=1000505;i++)dis[i]=1e18;
		int x,y;
		scanf("%lld%lld",&x,&y);
		spfa(x);
		printf("%lld\n",dis[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}