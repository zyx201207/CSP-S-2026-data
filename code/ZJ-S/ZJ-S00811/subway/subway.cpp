#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+507;
int a,t,k,c,n,m,d,q,w[maxn],vis[507],new_road[507][507],dis[507],T[507][507];
struct Line{
	int v,w;
};
struct Point{
	int dis,pos;
	friend bool operator < (Point A,Point B){
		return A.dis>B.dis;
	}
};
vector<Line>road[maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a,&t);
			Line Q;
			Q.v=i,Q.w=t;
			road[a].push_back(Q);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			new_road[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<road[i].size()-1;j++){
			for(int h=j+1;h<road[i].size();h++){
				int now=road[i][j].v;
				int pre=road[i][h].v;
				new_road[now][pre]=new_road[pre][now]=min(new_road[pre][now],road[i][j].w+road[i][h].w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) vis[j]=0,dis[j]=1e18;
		priority_queue<Point>Q;
		Point N_P;
		N_P.dis=0,N_P.pos=i;
		Q.push(N_P);
		dis[i]=0;
		while(!Q.empty()){
			Point Tmp=Q.top();
			Q.pop();
			int now=Tmp.pos;
			if(vis[now]) continue;
			vis[now]=1;
			for(int j=1;j<=n;j++){
				int pre=j,s=new_road[now][j];
				if(dis[pre]>dis[now]+s){
					Point P_P;
					P_P.dis=dis[now]+s,P_P.pos=pre;
					dis[pre]=dis[now]+s;
					Q.push(P_P);
				}
			}
		}
		for(int j=1;j<=n;j++) T[i][j]=dis[j];
	}
	while(q--){
		int x,y,ans=1e18;
		scanf("%lld%lld",&x,&y);
		for(int i=0;i<road[x].size();i++){
			for(int j=0;j<road[y].size();j++){
				ans=min(T[road[x][i].v][road[y][j].v]+road[y][j].w+road[x][i].w,ans);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
