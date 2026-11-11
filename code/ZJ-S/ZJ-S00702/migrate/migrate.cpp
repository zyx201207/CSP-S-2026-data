#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 2000005
int c,t,n,dis[maxn];//rp=inf
ll x[maxn],ans,st[maxn];
struct node{
	int u,step;
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);ll d;
	while(t--){
		scanf("%d%lld",&n,&d);
		ans=0;
		for(int i=1;i<=n;i++)scanf("%lld",x+i);
		for(int i=1;i<=n;i++){
			queue<node>q;
			memset(dis,0,sizeof(int)*(n+1));
			q.push({i,0});
			//printf("d1%lld\n",d);
			while(!q.empty()){
				int u=q.front().u,step=q.front().step+1;q.pop();
				//printf("%d %d\n",u,step);
				for(int v=u+1;v<=n;v++){
					if(x[v]-x[u]<=d){
						//printf("d%d %d %d\n",x[v]-x[u],u,v);
						if(dis[v]==0){
							q.push({v,step});
							dis[v]++,st[v]=step;
						}else if(dis[v]==1&&st[v]==step){
							dis[v]++,ans++;
							q.push({v,step});
						}else if(dis[v]==2&&st[v]==step){
							dis[v]++,ans--;
							q.push({v,step});
						}
					}
					else break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
