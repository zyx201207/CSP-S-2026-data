#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=500005;

int c,n,m,d,q;
int w[N],t[505][N];

ll dt[505][505];
vector <int> g[505];
vector <int> s[N];

void Disj(int x){
	priority_queue <pair<int,int>> q;
	bool b[505];
	for(int i=1;i<=n;i++) b[i]=0;
	q.push({-0,x});dt[x][x]=0;
	
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(b[u]) continue;
		b[u]=1;
		for(auto v:g[u]){
			for(auto ee:s[v]){
				if(ee==u) continue;
				if(dt[x][ee]>dt[x][u]+t[u][v]+t[ee][v]){
					dt[x][ee]=dt[x][u]+t[u][v]+t[ee][v];

					q.push({-dt[x][ee],ee});
				} 
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,b;
			cin>>a>>b;
			t[i][a]=b;
			g[i].push_back(a);
			s[a].push_back(i);
		}
		for(int j=1;j<=n;j++) dt[i][j]=1e18;
	}
	

	for(int i=1;i<=n;i++) Disj(i);

	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(auto i:s[x]){
			for(auto j:s[y]){
				ans=min(ans,dt[i][j]+t[i][x]+t[j][y]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}


















