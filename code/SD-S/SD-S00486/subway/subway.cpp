#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,minn=0x3f3f3f3f;
int t[110],k[110],vis[110],p[110][110];
int head[110],nxt[110],ver[110],tot;
map<int,int>mp;
struct node {
	int a,t;
} b[110];
void add(int x,int y) {
	tot++;
	ver[tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
void dfs(int x,int y,int ans) {
	if(x==y) {
		minn=min(minn,ans);
		return ;
	}
	for(int i=head[x]; i!=-1; i=nxt[i]) {
		//cout<<x<<":"<<ver[i]<<"\n";
		int ny=ver[i];
		if(!vis[ny]) {
			vis[ny]=1;
			dfs(ny,y,ans+p[mp[ny]][x]);
			vis[i]=0;
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof head);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1; i<=m; i++) {
		scanf("%d",&t[i]);
	}
	for(int i=1; i<=n; i++) {
		scanf("%d",&k[i]);
		for(int j=1; j<=k[i]; j++) {
			scanf("%d%d",&b[j].a,&b[j].t);
			if(j-1>0) {
				add(b[j-1].a,b[j].a);
				add(b[j].a,b[j-1].a);
			}
			//cout<<b[j-1].a<<" "<<b[j].a<<"\n";
			mp[b[j].a]=i;
			p[i][b[j].a]=b[j].t;
		}
	}
	while(q--) {
		int x,y;
		scanf("%d%d",&x,&y);
		dfs(x,y,0);
		printf("%d\n",minn+t[x]+t[y]);
		minn=0x3f3f3f3f;
	}
	return 0;
}
