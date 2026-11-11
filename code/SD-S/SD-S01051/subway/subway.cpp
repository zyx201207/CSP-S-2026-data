#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define int long long
using namespace std;
int op,n,m,l,qu,w[500100],k[510],p[510][1010],v[1010][510],v2[1010],id[1010][510],vis[1010],d[1010];
struct node{
	int x,id,w;
};
bool operator < (node x,node y){
	return x.w>y.w;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&op,&n,&m,&l,&qu);
	for(int i=1;i<=m;i++) scanf("%lld",w+i);
	for(int i=1;i<=n;i++){
		scanf("%lld",k+i);
		for(int j=1;j<=k[i];j++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			p[i][j]=x;
			v[p[i][j]][i]=y;
			id[p[i][j]][i]=1;
		}
	}
	while(qu--){
		int uu,vv;
		scanf("%lld%lld",&uu,&vv);
		memset(d,0x3f,sizeof d);
		memset(vis,0,sizeof vis);
		priority_queue<node> q;
		for(int i=1;i<=n;i++){
			if(id[uu][i]) q.push(node{uu,i,v[uu][i]});
		}
		while(!q.empty()){
			node t=q.top();
//			cout<<t.x<<" "<<t.id<<" "<<t.w<<endl;
			q.pop();
			if(vis[t.id]) continue;
			vis[t.id]=1;
			for(int i=1;i<=k[t.id];i++){
				int y=p[t.id][i];
//				cout<<y<<endl;
				if(d[y]>t.w+v[y][t.id]){
					d[y]=t.w+v[y][t.id];
					for(int j=1;j<=n;j++){
						if(id[y][j]&&!vis[j]){
//							cout<<"*"<<y<<" "<<j<<" "<<d[y]+v[y][j]<<endl;
							q.push(node{y,j,d[y]+v[y][j]});
						}
					}
				}
			}
		}
		printf("%lld\n",d[vv]+w[uu]+w[vv]);
	}
	return 0;
}

