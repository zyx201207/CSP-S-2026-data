#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x;
}
using pii=pair<int,int>;
const int N=505,M=500005,inf=1e18;
int c,n,m,d,q;
int w[M],k[N];
vector<pii> line[M];
vector<pii> ve[N];
int dis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			int a=read(),t=read();
			ve[i].push_back({a,t});
			line[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) dis[i][j]=inf;
	for(int i=1;i<=n;i++)
		for(auto p:ve[i]){
			int u=p.first;
			for(auto q:line[u]){
				int j=q.first;
				if(i>j)  dis[j][i]=min(dis[i][j],p.second+q.second);
				else dis[i][j]=min(dis[i][j],p.second+q.second);
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=i+1;k<=j-1;k++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x=read(),y=read();
		int ans=inf;
		for(auto p1:line[x])
			for(auto p2:line[y]){
				int u=p1.first,v=p2.first;
				if(u>v) swap(u,v);
				ans=min(ans,dis[u][v]+p1.second+p2.second);
			}
		printf("%lld\n",ans+w[x]+w[y]);
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
//什么叫还没切T1就把T2切了？
//大洋里都过了
//CCF 让我过T2吧
//过T2我就是7 dog了
//球球了
//不要炸 
//15:27一发过样例
//O(d\sum k+n^3+qd^2)
//1e7+2e7+4e7 = 7e7 
/*
能跑过吗？
大洋里好像很水
subway7只跑了0.45s 
希望CCF是少爷机 
自己写的生成器老是RE 
*/
