#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int c,n,m,d,q;const int N=505,D=25,M=5e5+5;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long dis[N][N];
pair<int,int>stk[M][D];
int top[M],w[M];
int rd(){
	int x=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	return x;
}
int _stk[50],_top;
void wt(long long x){
	do _stk[++_top]=x%10,x/=10;
	while(x);while(_top)putchar(_stk[_top--]+48);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++)w[i]=rd();
	for(int i=1;i<=n;i++){
		int k=rd(),a,t;dis[i][i]=0;
		for(int j=1;j<=k;j++){
			a=rd(),t=rd();
			stk[a][++top[a]]={i,t};
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=top[i];j>1;j--){
			int u=stk[i][j].fi;
			long long wu=stk[i][j].se;
			for(int k=j-1;k>=1;k--){
				int v=stk[i][k].fi;
				dis[u][v]=dis[v][u]=min(dis[u][v],wu+stk[i][k].se);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x=rd(),y=rd();long long ans=inf;
		for(int i=top[x];i>=1;i--){
			for(int j=top[y];j>=1;j--){
				ans=min(ans,dis[stk[x][i].fi][stk[y][j].fi]+stk[x][i].se+stk[y][j].se);
			}
		}
		wt(ans+w[x]+w[y]),putchar('\n');
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
