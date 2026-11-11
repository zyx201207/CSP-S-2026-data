#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline int read(){
	int ret=0;char ch=getchar();bool sgn=0;
	while(!isdigit(ch)) sgn^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return sgn?-ret:ret;
}
int c,n,m,d,Q,w[505],k[505],wht[505][50005];
struct mine{
	int wt,tim;
	bool operator <(const mine b)const{return wt<b.wt;}
}a[50005][25];
bool hv[50005][505],vis[505];
int f[505][505],tim[50005][505];
int dfs(int now,int to){
	if(now==to) return 0;
	if(f[now][to]!=0x3f3f3f3f) return f[now][to];
	if(vis[now]) return 0x3f3f3f3f;
	vis[now]=1;
	for(int i=1;i<=wht[now][0];i++){
		int use=wht[now][i];
		for(int j=1;j<=k[use];j++){
			f[now][to]=min(f[now][to],dfs(a[use][j].wt,to)+tim[use][now]+tim[use][a[use][j].wt]);
		}
	}
	vis[now]=0;
	return f[now][to];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),m=read(),n=read(),d=read(),Q=read();
	for(int i=1;i<=n;i++) w[i]=read();
	for(int i=1;i<=m;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			a[i][j].wt=read(),a[i][j].tim=read();
			hv[i][a[i][j].wt]=1;
			wht[a[i][j].wt][++wht[a[i][j].wt][0]]=i;
			tim[i][a[i][j].wt]=a[i][j].tim;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dfs(i,j);
	}                               
	while(Q--){
		int now=read(),to=read();
		printf("%d\n",dfs(now,to)+w[now]+w[to]);
	}
//	cerr<<clock()<<endl;
	return 0;
	
}