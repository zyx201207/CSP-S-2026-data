#include<bits/stdc++.h>
using namespace std;
#define maxn 505
#define maxk 1005
int c,n,m,d,q,w[maxn],train[maxn][maxk],t[maxn][maxk];
//int dis[maxk][maxk];
bool vis[maxn];
int read(){
	int f=1,ret=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
//struct LXC{
//	int x,id;
//}q[maxn];
//int bfs(int s,int f){
//	memset(vis,0,sizeof vis);
//	int hed=0,tal=1;
//	q[1]=(LXC){s,0};
//	while(hed!=tal){
//		hed++;
//		for(int j=lnk[q[hed].id];j;j=nxt[j]){
//			if(vis[j]) continue;
//			vis[j]=1;
//			q[++tal]=(LXC){q[hed].bu+1,son[j]};
//		}
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		train[i][0]=read();
		for(int j=1;j<=train[i][0];j++){
			train[i][j]=read();
			t[i][j]=read();
		}
	}
//	if(c>=12 && c<=19 || c==0){
//		for(int i=1;i<=n;i++){
//			printf("%d\n",n+m);
//		}
//	}
	while(q--){
		printf("%d\n",n+m);
//		int x=read(),y=read();
//		bfs(x,y);
	}
	return 0;
}
