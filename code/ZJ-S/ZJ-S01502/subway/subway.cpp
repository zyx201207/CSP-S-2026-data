#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int dis[500005];
int w[500005],k[501];
int a[501][5005],t[501][5005];
int c,n,m,d,q;
bool vis[500005];
struct edge{
	int s,e,val,l,r;
}p[50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d %d",&a[i][j],&t[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int x=1;x<=k[i];x++){
				for(int y=1;y<=k[i];y++){
					if((i==j&&a[i][x]!=a[j][y])||(i!=j&&a[i][x]==a[j][y])){
						cnt++;
						p[cnt].s=a[i][x];	
						p[cnt].e=a[j][y];
						p[cnt].l=i;
						p[cnt].r=j;
						if(i==j) p[cnt].val=0;
						else p[cnt].val=t[i][x]+t[j][y];
					}
				}
			}
		}
	}
	for(int op=1;op<=q;op++){
		int minn=INF;
		int x,y;
		scanf("%d %d",&x,&y);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					memset(vis,0,sizeof(vis));
					vis[x]=1;
					for(int opo=1;opo<=m;opo++){
						dis[opo]=INF;
					}
					dis[x]=0;
					int js;
					queue<int> q;
					q.push(x);
					while(!q.empty()){
						int o=q.front();
						q.pop();
						for(int i=1;i<=cnt;i++){
							if(p[i].s==p[i].e||p[i].l==p[i].r){
								if(p[i].s==o){
									dis[p[i].e]=min(dis[p[i].s]+p[i].val,dis[p[i].e]);
									if(vis[p[i].e]==0){
										q.push(p[i].e);
										vis[p[i].e]=1;
										if(p[i].e==y) js=p[i].r;
									}
								}
							}
						}
					}
					minn=min(minn,dis[y]+t[i][j]+t[js][y]);
				}
			}
		}
		printf("%d\n",minn);
	}
	return 0;
}
