#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],w[5005][5005],ans,l[200005],r[200005];
struct node{
	int p,dis,way;
	bool operator >(const node &x)const{
		return x.dis<dis||(x.dis==dis&&x.way<way);
	}
};
priority_queue<node,vector<node>,greater<node> >q;
long long dis[5005],vis[5005],way[5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		if(c<=10){
			for(int i=1;i<=n;i++){
				l[i]=r[i]=i;
			} 
			for(long long i=1;i<=n;i++){
				for(long long j=i;j<=n;j++){
					if(i==j)w[i][j]=0;
					else{
						if(max(x[j]-x[i],x[i]-x[j])<=d){
							w[i][j]=1;
							l[j]=min(l[j],i);
							r[i]=max(r[i],j);
						}
						else w[i][j]=1e18;
					}
				}
			}
			for(int s=1;s<=n;s++){
				for(int i=1;i<=n;i++){
					vis[i]=0;
					dis[i]=1e18;
					way[i]=0;
				}
				dis[s]=0;
				way[s]=1;
				q.push({s,0,1});
				while(!q.empty()){
					int u=q.top().p;
					q.pop();
					if(vis[u])continue;
					vis[u]=1;
					for(int i=l[u];i<=r[u];i++){
						if(!vis[i]){
							if(dis[u]+1<dis[i]){
								dis[i]=dis[u]+1;
								way[i]=way[u];
								q.push({i,dis[i],way[i]});
							}
							else if(dis[u]+1==dis[i]){
								way[i]+=way[u];
								q.push({i,dis[i],way[i]});
							}
						}
					}
				}
				for(int i=1;i<=n;i++){
					if(way[i]==2){
						ans++;
					}
				}
			}
			printf("%lld\n",ans/2);
		}
		else if(c==11||c==12){
			long long di=x[2]-x[1];
			if(di>d){
				printf("0\n");
			}
			else{
				long long tt=d/di;
				printf("%lld\n",n-tt+1);
			}
		}
	}
	return 0;
}
