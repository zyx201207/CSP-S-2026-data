#include <cstdio>
#include <algorithm>
template <typename T>
bool tense(T &a,const T &b){return a>b?a=b,true:false;}

const int MAXN=5008,INF=0x3f3f3f3f;
long long x[MAXN];
long long dist[MAXN],cou[MAXN];
bool vis[MAXN],used[MAXN][MAXN];
int n;
int c,t;
long long d;
namespace force{
	void dfs(int from){
		int j=from;
		while(j>1&&x[--j]>=x[from]-d){
			if(!vis[j]){
				vis[j]=true;
				if(dist[j]==dist[from]+1){
					cou[j]++;
				}else tense(dist[j],dist[from]+1),cou[j]=0;
				dfs(j);
				vis[j]=false;
			}
		}
		j=from;
		while(j<n&&x[++j]<=x[from]+d){
			if(!vis[j]){
				vis[j]=true;
				if(dist[j]==dist[from]+1){
					cou[j]++;
				}else tense(dist[j],dist[from]+1),cou[j]=0;
				dfs(j);
				vis[j]=false;
			}
		}
	}
	void solve(){
		while(t--){
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int i=1;i<=n;i++) dist[i]=INF;
				vis[i]=true,dist[i]=0;
				dfs(i);
				vis[i]=false;
				for(int j=1;j<=n;j++){
					if(!used[i][j]&&!used[j][i]&&cou[j]==2) ans++,used[i][j]=true,used[j][i]=true;
					cou[j]=0,dist[j]=0;
				}
			}
			printf("%d\n",ans);
			for(int i=1;i<=n;i++) x[i]=0,dist[i]=0;
		}
	} 
} 
namespace special{
	void solve(){
		scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		if(x[2]-x[1]>=d)printf("0\n");
		else{
		int s=(x[2]-x[1]+d-1)/d;
			int ans=0;
			for(int i=1;i+s-1<=n;i++){
				ans+=std::min(n-i,s*2-1)-(s+1);
			}
			printf("%d\n",ans);
		}
	} 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c<=2) force::solve();
	else special::solve();
	return 0;
}
