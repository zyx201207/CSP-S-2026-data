#include<bits/stdc++.h>
#define N 510
#define M 500010
using namespace std;
int c,n,m,d,q,in[M];
long long f[N][N];
struct edge{int v,w;};
vector<edge>e[M];
inline int read(){
	int res=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res*f;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	//scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)in[i]=read();//scanf("%d",&in[i]);
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		int ki;
		ki=read();//scanf("%d",&ki);
		for(int j=1,u,w;j<=ki;j++){
			//scanf("%d%d",&u,&w);
			u=read();w=read();
			e[u].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++){
		int len=e[i].size();
		for(int j=0;j<len;j++){
			int u=e[i][j].v;
			for(int k=0;k<len;k++){
				int v=e[i][k].v;
				f[u][v]=min(f[u][v],(long long)e[i][j].w+e[i][k].w);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x=read(),y=read();
		//scanf("%d%d",&x,&y);
		long long res=1e18;
		for(edge u:e[x])
			for(edge v:e[y])
				res=min(res,f[u.v][v.v]+u.w+v.w);
		printf("%lld\n",res+in[x]+in[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
//Nagasaki Soyo
