#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=2e6+10;
int n;
ll ans[3010][3010];
ll d,x[N];
vector<int> g[N];
void dij(int s){
	priority_queue<pii,vector<pii>,greater<pii>> q;
	vector<ll> dis(n+1,INF);
	q.push({0,s});
	dis[s]=0;
	while(!q.empty()){
		int u=q.top().second,d=q.top().first;
		q.pop();
		if(dis[u]!=d) continue;
		for(int v : g[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				ans[s][v]=ans[s][u];
				q.push({dis[v],v});
			}
			else if(dis[v]==dis[u]+1) ans[s][v]+=ans[s][u];
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,T,id=0;
	cin>>c>>T;
	while(T--){
		id++;
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>x[i];
		for(int i=1;i<=n;++i){
			g[i].clear();
			for(int j=1;j<=n;++j) ans[i][j]=0;
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(llabs(x[i]-x[j])<=d){
					g[i].push_back(j);
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			ans[i][i]=1;
			dij(i);
			for(int j=1;j<=n;++j){
//				cout<<ans[i][j]<<" ";
				if(ans[i][j]==2) cnt++;
			}
//			cout<<"\n";		
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
