#include <bits/stdc++.h>
#define R register
#define LL long long
using namespace std;
const int N=505,M=2505,QQ=1e5+10;
const LL inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,Q,s[N][M],W[M];
struct Que{
	int x,y,id;
}r[QQ];
LL dis[N][M],ans,res[QQ];
struct Edge{
	int u,t;
};
vector<Edge>e[N],g[N][N];
struct Node{
	int c,way;
	LL t;
	bool operator<(const Node &u)const{
		return u.t<t;
	}
};
inline void dij(int way,int st,int tim,int t){
	priority_queue<Node>q;
	q.push({st,way,tim});
	dis[way][st]=tim;
	while(q.size()){
		Node u=q.top();
		q.pop();
		if(dis[u.way][u.c]<u.t) continue;
		for(R int i=0;i<g[u.way][u.c].size();i++){
			int v=g[u.way][u.c][i].u,t=g[u.way][u.c][i].t;
			if(dis[u.way][v]>dis[u.way][u.c]+t){
				dis[u.way][v]=dis[u.way][u.c]+t;
				q.push({v,u.way,dis[u.way][v]});
				for(R int j=1;j<=n;j++)
					if(j!=u.way&&s[j][v]){
						if(dis[j][v]>dis[u.way][v]+s[j][v]){
							dis[j][v]=dis[u.way][v]+s[j][v];
							q.push({v,j,dis[j][v]});
						}
					}
			}
		}
	}
}
inline bool cmp(Que a,Que b){
	return a.x<b.x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(R int i=1;i<=m;i++) cin>>W[i];
	for(R int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(R int j=1;j<=l;j++){
			int a,t;
			cin>>a>>t;
			s[i][a]=t;
			e[i].push_back({a,t});
		}
		for(R int j=0;j<l;j++){
			for(R int k=0;k<l;k++){
				if(j==k) continue;
				int u=e[i][j].u,v=e[i][k].u,t=e[i][k].t;
				g[i][u].push_back({v,t});
			}
		}
	}
	for(R int i=1;i<=Q;i++) cin>>r[i].x>>r[i].y,r[i].id=i;
	sort(r+1,r+1+Q,cmp);
	for(R int i=1;i<=Q;i++){
		ans=inf;
		if(r[i].x!=r[i-1].x){
			memset(dis,0x3f,sizeof(dis));
			for(R int j=1;j<=n;j++)
				if(s[j][r[i].x])
					dij(j,r[i].x,s[j][r[i].x],r[i].y);
		}
		for(R int j=1;j<=n;j++)
			if(s[j][r[i].y])
				ans=min(ans,dis[j][r[i].y]);
		res[r[i].id]=W[r[i].x]+W[r[i].y]+ans;
	}
	for(R int i=1;i<=Q;i++) cout<<res[i]<<'\n';
	return 0;
}
