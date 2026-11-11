#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define int long long
const int N=5e5+5,M=505,Q=1e5+5;
int n,m,d,q;
int w[N],ans[Q];
struct que{
	int x,y,idx;
	friend bool operator < (const que &p,const que &q){
		return p.x<q.x;
	}
}ask[Q];
struct line{
	int k,a[25],t[25];
}p[M];
struct edge{
	int u,v,val;
	friend bool operator< (const edge &p,const edge &q){
		return p.val<q.val;
	}
};
vector<edge> edg;
struct edgg{
	int v,val;
};
vector<edgg> e[N];
int dis[N];
priority_queue<edge> qu;
void dij(int x){
	dis[x]=0;
	for(int j=0;j<e[x].size();j++){
		edgg now=e[x][j];
		qu.push({x,now.v,now.val});
	}
	while(!qu.empty()){
		edge Edge=qu.top();
		qu.pop();
		int u=Edge.u,v=Edge.v,val=Edge.val;
		if(dis[u]+val<dis[v]){
			dis[v]=dis[u]+val;
			for(int j=0;j<e[v].size();j++){
				edgg now=e[v][j];
				if(now.v==u) continue;
				qu.push({v,now.v,now.val});
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>p[i].k;
		for(int j=1;j<=p[i].k;j++)
			cin>>p[i].a[j]>>p[i].t[j];
		for(int j=1;j<=p[i].k;j++){
			for(int o=j+1;o<=p[i].k;o++){
				e[p[i].a[j]].push_back({p[i].a[o],p[i].t[j]+p[i].t[o]});
				e[p[i].a[o]].push_back({p[i].a[j],p[i].t[j]+p[i].t[o]});
				edg.push_back({p[i].a[j],p[i].a[o],p[i].t[j]+p[i].t[o]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>ask[i].x>>ask[i].y;
		ask[i].idx=i;
	}
	sort(ask+1,ask+q+1);
	for(int i=1;i<=q;){
		for(int j=1;j<=m;j++) dis[j]=1e18;
		int kkk=ask[i].x;
		dij(kkk);
		while(ask[i].x==kkk) ans[ask[i].idx]=dis[ask[i].y]+w[ask[i].x]+w[ask[i].y],i++;
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
	return 0;
}
