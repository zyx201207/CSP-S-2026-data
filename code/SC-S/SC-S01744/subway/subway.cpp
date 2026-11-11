#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
struct node{int id;long long x;};
vector<node>q[N];
long long w[N],f[550][550];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int cid,n,m,d,Q;
	scanf("%d %d %d %d %d",&cid,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k,id;scanf("%d",&k);
		long long t;
		while(k--){
			scanf("%d %lld",&id,&t);
			q[id].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++)
	 for(int u=q[i].size()-1;u>0;u--)
	  for(int v=u-1;v>=0;v--)
		f[q[i][u].id][q[i][v].id]=
		f[q[i][v].id][q[i][u].id]=
			min(f[q[i][u].id][q[i][v].id],
				q[i][u].x+q[i][v].x);
	for(int k=1;k<=n;k++)
	 for(int u=1;u<=n;u++)
	  for(int v=1;v<=n;v++)
	    f[u][v]=min(f[u][v],
			f[u][k]+f[v][k]);
	while(Q--){
		int u,v;
		long long ret=1e18;
		scanf("%d %d",&u,&v);
		for(int i=q[u].size()-1;i>=0;i--)
		 for(int j=q[v].size()-1;j>=0;j--)
		  ret=min(ret,q[u][i].x+q[v][j].x+
		  	f[q[u][i].id][q[v][j].id]);
		printf("%lld\n",ret+w[u]+w[v]);
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