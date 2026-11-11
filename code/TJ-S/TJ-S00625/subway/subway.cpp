#include <cstdio>
#include <algorithm>
#include <vector>

template <typename T>bool tense(T &a,const T &b){return b<a?a=b,true:false;}

const int INF=0x3f3f3f3f;
const int maxn=505,maxm=500005;

int w[maxm];
int a[maxm],t[maxm];
int n,m;

int dis[maxn][maxn];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int id,d,q;
	scanf("%d%d%d%d%d",&id,&m,&n,&d,&q);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int tmp=1;tmp<=m;tmp++){
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++) scanf("%d%d",&a[i],&t[i]);
		
		for(int i=1;i<=k;i++)
			for(int j=1;j<=k;j++){
				if(dis[a[i]][a[j]]) tense(dis[a[i]][a[j]],w[i]+w[j]+t[i]+t[j]);
				else dis[a[i]][a[j]]=w[i]+w[j]+t[i]+t[j];
			}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				tense(dis[a[i]][a[j]],dis[a[i]][a[k]]+dis[a[k]][a[j]]);
			}
		}
	}
	
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",dis[u][v]);
	}
	return 0;
}
