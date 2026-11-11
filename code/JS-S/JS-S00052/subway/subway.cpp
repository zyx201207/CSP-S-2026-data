#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<ll,int> //dist id
const int N=5e5+534,INF=0X3f3f3f3f;
ll c,n,d,qq;
int m;
bool fa=1;
struct zhou{
	int to;
	ll v;
};
vector<vector<zhou>> g(N,vector<zhou>());
priority_queue<pii,vector<pii>,greater<> > q;
vector<ll> dist(N);
void dij(int x){
	for(int i=1;i<=n+m;i++)dist[i]=INF;
	dist[x]=0;
	q.push({dist[x],x});
	while(!q.empty()){
		ll d=q.top().first,u=q.top().second;q.pop();
		if(d>dist[u])continue;
		for(auto &t:g[u]){
			ll v=t.v,to=t.to;
			if(dist[to]>d+v){
				dist[to]=d+v;
				q.push({dist[to],to});
			}
		}
	}						
}
int w[N];
queue<ll> q;
bool v[N];
ll bfs(ll l,ll r){
	q.clear();
	q.push(l);
	for(int i=1;i<=n+m;i++)dist[i]=v[i]=0;
	v[l]=1;
	while(q.size()){
		ll u=q.front();q.pop();
		for(auto &t:g[u]){
			ll to=t.to,v=t.v;
			if(v[to]==0){
				v[to]=1;
				q.push(to);
				dist[to]=dist[u]+v;
				if(to==r){
					return dist[to];
				}
			}
		}
	}
}




int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>qq;// n stop m point 1-m ,m+1 - m+n
	for(int i=1;i<=m;i++)cin>>w[i];
	ll p=-78917887;
	for(int i=1;i<=n;i++){	
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int to;
			ll v;
			cin>>to>>v;
			if(p==-78917887)p=v;
			else if(p!=v)fa=0;
			g[m+i].push_back({to,v});
			g[to].push_back({m+i,v});
		}
	}
	if(fa=1){
		while(qq--){
			int l,r;
			cin>>l>>r;
			cout<<w[l]+w[r]+bfs(l,r)<<endl;
		}
		return 0;
	}
	while(qq--){
		int l,r;
		cin>>l>>r;
		dij(l);
		cout<<w[l]+w[r]+dist[r]<<endl;
	}
	return 0;
}

















