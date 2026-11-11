#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=502,M=5e5+2;
int ids,n,m,dm,ask,k[N],cnt[M];

LL dist[N][N];

int C[M];
struct node{
	int v;
	int dis;
}rem[M][22];
int S,T;

void floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				
}

void solve(){
	scanf("%d%d",&S,&T);
	LL res=1e18;
	
	for(int i=1;i<=cnt[S];i++){
		int a=rem[S][i].v,b;
		LL tmp;
		for(int j=1;j<=cnt[T];j++){
			b=rem[T][j].v;
			if(dist[a][b]!=1e12)
				tmp=(LL)C[S]+(LL)C[T]+dist[a][b]+rem[S][i].dis+rem[T][j].dis;
			res=min(res,tmp);
		}
	}
	
	printf("%lld\n",res);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&ids,&n,&m,&dm,&ask);
	for(int i=1;i<=m;i++) scanf("%d",&C[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int x,d;
			scanf("%d%d",&x,&d);
			rem[x][++cnt[x]]={i,d};
		}
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j) dist[i][j]=0;
			else dist[i][j]=1e12;
			
	for(int i=1;i<=m;i++){
		for(int p=1;p<cnt[i];p++){
			for(int q=p+1;q<=cnt[i];q++){
				int a=rem[i][p].v,b=rem[i][q].v;
				int d1=rem[i][p].dis,d2=rem[i][q].dis;
				dist[a][b]=min(dist[a][b],(LL)d1+(LL)d2);
				dist[b][a]=dist[a][b];
			}
		}
	}
	
	floyd();
	
	while(ask--) solve();
	
	return 0;
}
