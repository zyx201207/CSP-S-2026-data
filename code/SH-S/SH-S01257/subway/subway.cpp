#include<bits/stdc++.h>
using namespace std;
const int M=5.1e5,N=510,Q=1.1e5;
int c,n,m,d,q,k[N],w[M],qx[Q],qy[Q];
vector<int>a[N],t[N];
void file(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
void input(){
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		a[i].push_back(0),t[i].push_back(0);
		scanf("%d",&k[i]);
		for(int j=1,at,tt;j<=k[i];j++)scanf("%d%d",&at,&tt),a[i].push_back(at),t[i].push_back(tt);
	}
	for(int i=1;i<=q;i++)scanf("%d%d",&qx[i],&qy[i]);
}
namespace sub1_15{
	long long dis[N][N];
	vector<pair<int,int>>LOS[M];
	//priority_queue<pair<int,int>>pq;
	void func(){
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
			for(int j=1;j<=k[i];j++){
				LOS[a[i][j]].push_back({i,t[i][j]});
			}
		}
		for(int i=1;i<=m;i++){
			for(pair<int,int> u:LOS[i]){
				for(pair<int,int> v:LOS[i]){
					if(u.first!=v.first)dis[u.first][v.first]=min(dis[u.first][v.first],(long long)(u.second+v.second));
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int h=1;h<=n;h++){
					dis[i][j]=min(dis[i][j],dis[i][h]+dis[h][j]);
				}
			}
		}/*for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%d ",dis[i][j]);
			}
			printf("\n");
		}*/
		for(int i=1;i<=q;i++){
			long long ans=1e18;
			for(pair<int,int> u:LOS[qx[i]]){
				for(pair<int,int> v:LOS[qy[i]]){
					//if(ans>dis[u.first][v.first]+u.second+v.second)printf("<%d %d %lld>",u.first,v.first,dis[u.first][v.first]);
					ans=min(ans,dis[u.first][v.first]+u.second+v.second);
				}
			}
			//printf("%lld ",ans);
			ans+=w[qx[i]]+w[qy[i]];
			printf("%lld\n",ans);
		}
	}
}//O((M+Q)d^2+n^3) 可过60分
namespace subSolve{
	long long dis[N][N];
	vector<pair<int,int>>LOS[M];
	//priority_queue<pair<int,int>>pq;
	void func(){
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
			for(int j=1;j<=k[i];j++){
				LOS[a[i][j]].push_back({i,t[i][j]});
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];i++){
				int u=a[i][j],w=t[i][j];
				for(pair<int,int>e:LOS[u]){
					dis[i][e.first]=min(min(dis[i][e.first],dis[e.first][i]),(long long)(w+e.second));
					dis[e.first][i]=dis[i][e.first];
				}
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%d ",dis[i][j]);
			}
			printf("\n");
		}*/
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int h=1;h<=n;h++){
					dis[i][j]=min(dis[i][j],dis[i][h]+dis[h][j]);
				}
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%d ",dis[i][j]);
			}
			printf("\n");
		}*/
		for(int i=1;i<=q;i++){
			long long ans=1e18;
			for(pair<int,int> u:LOS[qx[i]]){
				for(pair<int,int> v:LOS[qy[i]]){
					//if(ans>dis[u.first][v.first]+u.second+v.second)printf("<%d %d %lld>",u.first,v.first,dis[u.first][v.first]);
					ans=min(ans,dis[u.first][v.first]+u.second+v.second);
				}
			}
			//printf("%lld ",ans);
			ans+=w[qx[i]]+w[qy[i]];
			printf("%lld\n",ans);
		}
	}
}//O(kd+Qd^2+n^3) 本质和上面一样，但莫名其妙的就快了
int main(){
	file();
	input();
	//sub1_15::func();
	subSolve::func();
	return 0; 
}
