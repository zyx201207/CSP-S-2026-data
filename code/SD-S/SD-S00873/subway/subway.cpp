#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rd read()
#define min(a,b) ((a<b)?a:b)
#define P pair<int,int>
#define x first
#define y second
int read(int u=0,bool f=false,char c=getchar()){
	for(;!isdigit(c);c=getchar()) f|=(c=='-');
	for(;isdigit(c);c=getchar()) u=(u<<1)+(u<<3)+(c^'0');
	return f?-u:u;
}void wt(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wt(x/10);
	putchar((x%10)^'0');
}void wt(ll x,char c){wt(x);putchar(c);}
const int N=510,M=5e5+10;
int c,n,m,d,q,w[M];ll dis[N][N];
vector<pair<int,int> >e[M];
main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd,n=rd,m=rd,d=rd,q=rd;
	for(int i=1;i<=m;i++) w[i]=rd;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			dis[i][j]=dis[j][i]=1e18;
	for(int i=1;i<=n;i++){
		int k=rd;
		for(int j=1;j<=k;j++){
			int x=rd,y=rd;
			e[x].push_back({y,i});
		}
	}for(int i=1;i<=m;i++){
		int sz=e[i].size();
		for(int j=0;j<sz;j++)
			for(int k=j+1;k<sz;k++){
				int x=e[i][j].y,y=e[i][k].y;ll ds=dis[x][y];
				dis[x][y]=dis[y][x]=min(ds,e[i][j].x+e[i][k].x);
			}
	}for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x=rd,y=rd;ll ans=1e18;
		for(P i:e[x])
			for(P j:e[y])
				ans=min(ans,i.x+j.x+dis[i.y][j.y]);
		wt(ans+w[x]+w[y],'\n');
	}
	return 0;
}/*
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
