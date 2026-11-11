#include<bits/stdc++.h>
using namespace std;
#define N 4010
int c,T,n,k,u[N],v[N],depu[N],depv[N],far,dep[N],maxd[N],maxd2[N],son[N],vis[N],res[2][N],ans;
vector<int> e[N];
void dfs1(int u,int fa,int *dep){
	if(dep[u]>dep[far]) far=u;
	for(int v:e[u]){
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		dfs1(v,u,dep);
	}
}
void dfs2(int u,int fa){
	maxd[u]=maxd2[u]=0,son[u]=u;
	for(int v:e[u]){
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		dfs2(v,u);
		if(maxd[v]+1>maxd[u]) maxd2[u]=maxd[u],maxd[u]=maxd[v]+1,son[u]=v;
		else if(maxd[v]+1>maxd2[u]) maxd2[u]=maxd[v]+1;
	}
}
void work(int rt,int *ans){
//	printf("rt=%d\n",rt);
	for(int i=1;i<=n;i++) depu[i]=depv[i]=-1;
	depu[rt]=0,far=rt;
	dfs1(rt,0,depu);
	int x=far;
	depu[x]=0,far=x;
	dfs1(x,0,depu);
	int y=far,mid=x;
	depv[y]=0;
	dfs1(y,0,depv);
//	printf("x=%d,y=%d\n",x,y);
//	for(int i=1;i<=n;i++) printf("%d ",depu[i]);
//	printf("\n");
//	for(int i=1;i<=n;i++) printf("%d ",depv[i]);
//	printf("\n");
	for(int i=1;i<=n;i++)
		if(depu[i]+depv[i]==depu[y]&&depu[i]==depu[y]/2)
			mid=i;
	dfs2(mid,0);
//	printf("mid=%d\n",mid);
	int now=1;
	priority_queue<pair<int,int> > q;
	for(int i=1;i<=n;i++) vis[i]=0;
	vis[mid]=1;
	for(int v:e[mid])
		q.push({maxd[v],v});
	while(!q.empty()){
		ans[now]=q.top().first+1;
		int u=q.top().second;
		q.pop();
		vis[u]=1;
		now++;
		for(int v:e[u])
			if(!vis[v])
				q.push({maxd[v],v});
	}
	for(int i=now;i<=n;i++) ans[i]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&k);
		if(c==13||c==14){
			k=n-k;
			if(k==0) printf("0\n");
			else{
				k--;
				if(k<(n+1)/2) printf("1\n");
				else{
					k-=(n+1)/2;
					ans=2;
					while(1){
						if(k<4){
							printf("%d\n",ans);
							break;
						}
						k-=4,ans++;
					}
				}
			}
			for(int i=1;i<n;i++) scanf("%d%d",&u[1],&v[1]);
			continue;
		}
		for(int i=1;i<n;i++) scanf("%d%d",&u[i],&v[i]);
		for(int j=1;j<=n;j++) e[j].clear();
		for(int j=1;j<n;j++){
			e[u[j]].push_back(v[j]);
			e[v[j]].push_back(u[j]);
		}
		work(1,res[0]);
		ans=res[0][k];
		for(int i=1;i<n;i++){
			int x=u[i],y=v[i];
			for(int j=1;j<=n;j++) e[j].clear();
			for(int j=1;j<n;j++)
				if(j!=i){
					e[u[j]].push_back(v[j]);
					e[v[j]].push_back(u[j]);
				}
//			printf("cut(%d,%d)\n",x,y);
			work(x,res[0]);
			work(y,res[1]);
			for(int i=1;i<k;i++){
				ans=min(ans,max(res[0][i],res[1][k-i]));
//				printf("l(%d):%d,r(%d):%d\n",i,res[0][i],k-i,res[1][k-i]);
			}
		}
		printf("%d\n",ans);
	}
}