#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int maxn=500+10;
const int maxm=500000+10;
const int INF=0x3f3f3f3f3f3f3f3f;
priority_queue<pii,vector<pii>,greater<pii>> pq;
int c,n,m,d,q;
int wm;
int k;
int a[maxn],t[maxn];
int dist[maxm];
struct Edge{
	int v,w;
};
vector<Edge> ma[maxm*2];
struct Query{
	int x,y,ID,ans;
}Q[maxm];
bool cmp1(Query &a,Query &b){
	return a.x<b.x;
}
bool cmp2(Query &a,Query &b){
	return a.ID<b.ID;
}
void Dijkstra(){
	while(!pq.empty()){
		int D=pq.top().first,u=pq.top().second;
		pq.pop();
		if(dist[u]<D) continue;
		for(auto &e:ma[u]){
			int v=e.v;
			int w=e.w;
			if(dist[u]!=INF&&dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>wm;
		ma[i].push_back({m+i,wm});
		ma[m+i].push_back({i,wm});
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
		for(int l=1;l<k;l++){
			for(int r=l+1;r<=k;r++){
				ma[m+a[l]].push_back({m+a[r],t[l]+t[r]});
				ma[m+a[r]].push_back({m+a[l],t[l]+t[r]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>Q[i].x>>Q[i].y;
		if(Q[i].x>Q[i].y) swap(Q[i].x,Q[i].y);
		Q[i].ID=i;
	}
	sort(Q+1,Q+q+1,cmp1);
	for(int i=1;i<=q;i++){
		if(Q[i].x!=Q[i-1].x){
			memset(dist,0x3f,sizeof dist);
			dist[Q[i].x]=0;
			pq.push({0,Q[i].x});
			Dijkstra();
		}
		Q[i].ans=dist[Q[i].y];
	}
	sort(Q+1,Q+q+1,cmp2);
	for(int i=1;i<=q;i++) cout<<Q[i].ans<<endl;
	return 0;
}
//不辨真伪，勿论虚实