#include<cstdio>
#include<queue>

template <typename T> bool relax(T &a,const T &b){return a<b?a=b,true:false;}
template <typename T> bool tense(T &a,const T &b){return b<a?a=b,true:false;}
namespace zxz{
	namespace force{
		;
	}
	namespace zxzstd{
		const int N=505,M=20005,INF=0x3f3f3f3f;
		int T,n,m,d,Q,ic[N][M],cnt[M];
		int w[M];
		int oc[N][N];
		int a[M][25];
		struct node{
			int id,val;
		};
		int dist[N][N];
		bool has_d[N];
		bool operator <(node a,node b){
			return dist[a.id]>dist[b.id];
		}
		int dikstra(int src,int tgt){
			if(!has_d[src]){
				has_d[src]=true;
				for(int i=1;i<=n;i++) dist[src][i]=(i==src?0:INF);
			}
			std::priority_queue<node> q;
			q.push({src,0});
			while(!q.empty()){
//				printf("in\n");
				int frm=q.top().id,frmd=q.top().val;
				q.pop();
				if(dist[src][frm]!=INF&&frmd!=dist[src][frm]) continue;
				for(int to=1;to<=n;to++){
//					printf("%d %d %d\n",frm,to,oc[frm][to]);
					if(frm!=to&&oc[frm][to]&&tense(dist[src][to],dist[src][frm]+oc[frm][to])) q.push({to,dist[src][to]});
				}
//				for(int i=1;i<=n;i++) printf("%d%c",dist[i]," \n"[i==n]);
			}
			return dist[src][tgt];
		}
		void solve(){
			scanf("%d%d%d%d%d",&T,&n,&m,&d,&Q);
			for(int i=1;i<=m;i++) scanf("%d",&w[i]);
			for(int i=1;i<=n;i++){
				int l;
				scanf("%d",&l);
				int x,y;
				for(int j=1;j<=l;j++) scanf("%d%d",&x,&y),ic[i][x]=y;
			}
			for(int j=1;j<=m;j++){
				for(int i=1;i<=n;i++) if(ic[i][j]) a[j][++a[j][0]]=i;
				for(int x=1;x<=a[j][0];x++)
					for(int y=x+1;y<=a[j][0];y++)
						oc[a[j][x]][a[j][y]]=oc[a[j][y]][a[j][x]]=ic[a[j][x]][j]+ic[a[j][y]][j];
			}
			while(Q--){
				int x,y;
				scanf("%d%d",&x,&y);
				int ans=INF;
				for(int xi=1;xi<=a[x][0];xi++)
					for(int yi=1;yi<=a[y][0];yi++){
//						printf("%d %d %d %d\n",xi,a[x][xi],yi,a[y][yi]);
						int localans=dikstra(a[x][xi],a[y][yi])+ic[a[x][xi]][x]+ic[a[y][yi]][y];
						tense(ans,localans);
					}
				printf("%d\n",ans+w[x]+w[y]);
			}
		}
	}
	void solve(){
		zxzstd::solve();
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	zxz::solve();
	return 0;
}
