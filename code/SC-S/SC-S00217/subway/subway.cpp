#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+7,inf=1e18;
int f[502][N],num[502],edge2[22][N];
ll dist[502][502];
bool b[N];
int num2[N];
ll a[N];
int c,n,m,d,q;
vector<pair<int,int>>edges[503];
vector<int>edge[502];
void add(int x){
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
	for(int i=1;i<=520;i++)b[i]=false;
	dist[x][x]=0;
	q.push({0,x});
	while(!q.empty()){
		auto y=q.top();
		q.pop();
		if(b[y.second]){
			continue;
		}
		b[y.second]=true;
		for(auto z:edges[y.second]){
			if(dist[x][y.second]+z.first<dist[x][z.second]){
				q.push({dist[x][y.second]+z.first,z.second});
				dist[x][z.second]=dist[x][y.second]+z.first;
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>num[i];
		for(int j=1;j<=num[i];j++){
			int x,w;
			cin>>x>>w;
			edge[i].push_back(x);
			edge2[++num2[x]][x]=i;
			f[i][x]=w;
		}
	}
	for(int i=1;i<=n;i++){
		memset(b,false,sizeof(b));
		for(auto y:edge[i]){
			b[y]=true;
		}
		for(int j=i+1;j<=n;j++){
			for(auto z:edge[j]){
				if(b[z]){
					edges[j].push_back({f[i][z]+f[j][z],i});
					edges[i].push_back({f[i][z]+f[j][z],j});	
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=inf;
		}
		add(i);
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		ll ans=inf;
		for(int j=1;j<=num2[u];j++){
			for(int z=1;z<=num2[v];z++){
				ans=min(f[edge2[j][u]][u]+f[edge2[z][v]][v]+a[u]+a[v]+dist[edge2[z][v]][edge2[j][u]],ans);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}