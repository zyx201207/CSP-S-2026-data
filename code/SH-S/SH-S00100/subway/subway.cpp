#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+3;
const int F=N*N*N; 
int c,l,n,d,q;
int t[N],dis[504][504];
struct edge{
	int v,w;
};
vector<edge> G[N]; 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&l,&n,&d,&q);
	for(int i=1;i<=l;i++)
		for(int j=1;j<=l;j++)
			if(i!=j)
				dis[i][j]=F;
	for(int i=1;i<=n;i++)
		scanf("%lld",&t[i]);
	for(int r=1;r<=l;r++){
		int k; scanf("%lld",&k);
		for(int i=1;i<=k;i++){
			int s,w; scanf("%lld%lld",&s,&w);
			G[s].push_back((edge){r,w});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<G[i].size();j++){
			for(int k=0;k<j;k++){
				int vj=G[i][j].v,wj=G[i][j].w;
				int vk=G[i][k].v,wk=G[i][k].w;
				dis[vj][vk]=dis[vk][vj]=min(dis[vj][vk],wj+wk);
			}
		}
	}
	for(int k=1;k<=l;k++)
		for(int i=1;i<=l;i++)
			for(int j=1;j<=l;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=q;i++){
		int a,b; scanf("%lld%lld",&a,&b); int minn=F;
		for(int j=0;j<G[a].size();j++){
			for(int k=0;k<G[b].size();k++){
				int vj=G[a][j].v,wj=G[a][j].w;
				int vk=G[b][k].v,wk=G[b][k].w;
				minn=min(minn,dis[vj][vk]+wj+wk);
			}
		}
		printf("%lld\n",minn+t[a]+t[b]);
	}
} 
