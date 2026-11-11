#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
template <typename T >bool relax(T &a,const T &b){return b>a?a=b,true:false;}
template <typename T >bool tense(T &a,const T &b){return b<a?a=b,true:false;}
const int N=505,M=500005;
const long long INF=0x3f3f3f3f3f3f3f3fll;
int C,n,m,D,q;
int w[M],len[N];
struct rec{
	int x,t;
};
std::vector<rec> a[N],b[M];
long long dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&D,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&len[i]);
		for(int j=1;j<=len[i];j++){
			int x,t;
			scanf("%d%d",&x,&t); 
			b[x].push_back((rec){i,t});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		dis[i][j]=INF;
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(rec j:b[i]) for(rec k:b[i]){
			//printf("%d %d %d %d %d\n",i,j.x,j.t,k.x,k.t);
			tense(dis[j.x][k.x],(long long)j.t+k.t);
		}
		for(rec j:b[i]) for(rec k:b[i]){
			tense(dis[k.x][j.x],(long long)j.t+k.t);
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		tense(dis[i][j],dis[i][k]+dis[j][k]);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=INF;
		for(rec j:b[x]) for(rec k:b[y]){
			tense(ans,dis[j.x][k.x]+j.t+k.t);
		}
		printf("%lld\n",ans+w[x]+w[y]); 
	}
	return 0;	
}
