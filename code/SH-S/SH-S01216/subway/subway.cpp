#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N=500010;
struct node{
	ll v,w;
};
struct node2{
	ll x,y,id;
};
ll c,n,m,d,qu,extra[N],k[510],dis[N+500],ans[N];
vector <node> g[N+500];
queue <ll> q;
node2 xy[N];
bool cmp(node2 xx,node2 yy){
	if (xx.x>yy.x)  return 0;
	else  return 1;
}
ll spfa(ll x,ll y){
	for (int i=1;i<=n+m;i++)  dis[i]=4e18;
	q.push(x+n);
	dis[x+n]=0;
	while (!q.empty()){
		ll u=q.front();
		q.pop();
		for (int i=0;i<(int)g[u].size();i++){
			ll v=g[u][i].v,w=g[u][i].w;
			if (dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qu;
	for (int i=1;i<=m;i++)  cin>>extra[i];
	for (int i=1;i<=n;i++){
		cin>>k[i];
		ll a=0,t=0;
		for (int j=1;j<=k[i];j++){
			cin>>a>>t;
			g[i].push_back({a+n,t});
			g[a+n].push_back({i,t});
		}
	}
	for (int i=1;i<=qu;i++){
		cin>>xy[i].x>>xy[i].y;
		xy[i].id=i;
	}
	sort(xy+1,xy+qu+1,cmp);
	ll now=-1;
	for (int i=1;i<=qu;i++){
		ll x=xy[i].x,y=xy[i].y;
		if (x!=now){
			memset(dis,0,sizeof(dis));
			spfa(x,y);
			now=x;
		}
		ans[xy[i].id]=dis[y+n]+extra[x]+extra[y];
	}
	for (int i=1;i<=qu;i++)  cout<<ans[i]<<"\n";
	return 0;
}
