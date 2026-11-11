#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<cstring> 
#define ll long long 
using namespace std;
/*
maxn
long long  signed 
多测清空 
freopen不要注释 
*/
const int maxn=506,maxm=5e5+5;
int c,n,m,d,q,k[maxn];
struct node{
	int to;
	ll val;
}; 
vector<int> a[maxn];
vector<node> b[maxm];
vector<ll> t[maxn];
ll w[maxm],dist[maxn][maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(dist,0x3f3f,sizeof(dist));
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++) dist[i][i]=0;
	int jg;
	ll shijian;
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%lld",&jg,&shijian);
			a[i].push_back(jg);
			t[i].push_back(shijian);
			b[jg].push_back({i,shijian});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<b[i].size();j++){
			int u=b[i][j].to;
			ll w1=b[i][j].val;
			for(int k=j+1;k<b[i].size();k++){
				int v=b[i][k].to;
				ll w2=b[i][k].val;
				dist[u][v]=min(dist[u][v],w1+w2);
				dist[v][u]=dist[u][v];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	int x,y;
	while(q--){
		scanf("%d%d",&x,&y);
		ll ans=9e18;
		for(int i=0;i<b[x].size();i++){
			int u=b[x][i].to;
			ll w1=b[x][i].val;
			for(int j=0;j<b[y].size();j++){
				int v=b[y][j].to;
				ll w2=b[y][j].val;
				ans=min(ans,w1+dist[u][v]+w2);
			}
		}
		printf("%lld",ans+w[x]+w[y]);
		if(q) printf("\n");
	}
	return 0;
} 
