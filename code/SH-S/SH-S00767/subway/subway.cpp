//有点慌。理一下思路。 
//首先建图。地铁线、站是点，站台到站厅是边。二分图。sum(k)条边。 
//然后给线路之间连边，求floyd。有点慢？ 
//对于每个问询，枚举分别上什么线路，O(d^2)。 
//瓶颈在floyd，n^3=125,000,000，有点极限
//实测还行，先去写后面的吧 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=600005;
int n,m,q,w[N],k[505],dis[505][505],tmp,ans;
struct edge{
	int v,w;
};
vector<edge> es[N];
inline int in(){
	char ch=getchar();
	int res=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0'; ch=getchar();
	}
	return res;
}
void write(int x){
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	tmp=in(); n=in(); m=in(); tmp=in(); q=in();
	for(int i=1;i<=m;++i){
		w[i]=in();
	}
	for(int i=1,k,a,t;i<=n;++i){
		k=in();
		for(int j=1;j<=k;++j){
			a=in(); t=in();
			es[i].push_back((edge){n+a,t});
			es[n+a].push_back((edge){i,t});
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i!=j) dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0,v,x;j<es[i].size();++j){
			v=es[i][j].v; 
			for(int k=0;k<es[v].size();++k){
				x=es[v][k].v;
				if(dis[i][x]>es[i][j].w+es[v][k].w) dis[i][x]=es[i][j].w+es[v][k].w;
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
	int u,v,i,j,x,y;
	while(q--){
		u=in(); v=in(); ans=1e18;
		u+=n; v+=n;
		for(i=0;i<es[u].size();++i){
			for(j=0;j<es[v].size();++j){
				x=es[u][i].v; y=es[v][j].v;
				ans=min(ans,es[u][i].w+es[v][j].w+dis[x][y]);
			}
		}
		ans+=w[u-n]+w[v-n];
		write(ans); putchar('\n');
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
