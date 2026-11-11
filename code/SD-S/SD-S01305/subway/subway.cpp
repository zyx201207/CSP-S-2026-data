#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5,INF=2e16;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while ('0'>ch||ch>'9'){
		if (ch=='-') f*=-1;
		ch=getchar();
	}
	while ('0'<=ch&&ch<='9'){
		x=(x<<1ll)+(x<<3ll)+ch-'0';
		ch=getchar();
	}return f*x;
}
int c,n,m,d,q,w[maxn];
int tot[maxn],dis[505][505];
struct node{int pos,t;}sta[maxn][50];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),
	d=read(),q=read();
	for (int i=1;i<=m;i++) w[i]=read();
	for (int i=1;i<=n;i++){
		int k=read();
		for (int j=1;j<=k;j++){
			int a=read(),t=read();
			node tmp={i,t};
			sta[a][++tot[a]]=tmp;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) dis[i][j]=INF;
	for (int i=1;i<=m;i++){
		int len=tot[i];
		for (int j=1;j<=len;j++)
			for (int k=1;k<=len;k++){
				int p1=sta[i][j].pos,p2=sta[i][k].pos;
				if (p1==p2){dis[p1][p2]=0;continue;}
				dis[p1][p2]=min(dis[p1][p2],sta[i][j].t+sta[i][k].t);
			}
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while (q--){
		int x=read(),y=read(),res=INF;
		for (int i=1;i<=tot[x];i++)
			for (int j=1;j<=tot[y];j++){		
				int p1=sta[x][i].pos,p2=sta[y][j].pos;
				res=min(res,dis[p1][p2]+sta[x][i].t+sta[y][j].t);
			}
		cout<<res+w[x]+w[y]<<'\n';
	}return 0;
}

