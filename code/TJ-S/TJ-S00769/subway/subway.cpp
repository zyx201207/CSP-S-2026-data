#include <cstdio>
#include <algorithm>
template <typename T>
bool tense(T &a,const T &b){return a>b?a=b,true:false;}
template <typename T>
bool relax(T &a,const T &b){return a<b?a=b,true:false;}
const int MAXN=508,INF=0x3f3f3f3f,MAXM=5e5+8;
int w[408];
int a[MAXN][28],t[MAXN][MAXN];
namespace force{
	int dist[408][408];
	void solve(){
		for(int i=1;i<=n;i++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) dist[i][j]=
		init();
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",dist[x][y]);
		}
	}
}
namespace simple{
	bool vis[]
	void solve(){
		
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",dist[x][y]);
		}
	}
}
int main(){
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j]=INF;
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++) {
		scanf("%d",&c);
		for(int j=1;j<=c;j++) scanf("%d%d",&a[i][j],&t[i][j]);
	}
	if(c<=8) force::solve(); 
	else if(12<=c&&c<=19){
		simple::solve();
	}
	return 0;
}
