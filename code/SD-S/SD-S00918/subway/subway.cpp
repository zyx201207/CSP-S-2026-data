bool m1;
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pil pair<int,ll>
const int N=5e3+10;

template<typename T> void chkmax(T &x,T y) {if(y>x) x=y;}
template<typename T> void chkmin(T &x,T y) {if(y<x) x=y;}

int c,n,m,d,q;
int k[N];
ll w[N],dis[N][N];
vector<int>a[N];
vector<ll>b[N];
map<pii,ll>mp;
vector<pil>z[N]; // 站点存在的路线 
vector<pil>g[N]; // 图 

struct node{
	int u;
	ll w;
	
	friend bool operator < (node x,node y){
		return x.w>y.w;
	}
	
};

int ha(int x,int y){
	return m*x+y;
}

void solve(int u){
	
	priority_queue<node>q;
	
	for(auto tmp:z[u]){
		q.push({ha(tmp.first,u),tmp.second});
		dis[u][ha(tmp.first,u)]=tmp.second;
	}
	
	while(!q.empty()){
		int uu=q.top().u;
		q.pop();
		for(auto tmp:g[uu]){
			int v=tmp.first;
			ll w=tmp.second;
			if(dis[u][v]>dis[u][uu]+w){
				dis[u][v]=dis[u][uu]+w;
				q.push({v,dis[u][v]});
			}
		}
	}
	
}

bool m2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
//	cerr<<abs(&m1-&m2)/1024/1024<<"MB\n";
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	
	memset(dis,0x3f3f,sizeof dis);
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			ll x,y; 
			cin>>x>>y;
			a[i].pb(x);
			b[i].pb(y);
			mp[{i,x}]=y;
			z[a[i][j]].pb({i,b[i][j]});
		}
		
		for(int j=0;j<k[i]-1;j++){
			g[ha(i,a[i][j])].pb({ha(i,a[i][j+1]),0});
			g[ha(i,a[i][j+1])].pb({ha(i,a[i][j]),0});
		}
//		cout<<'\n';
	} 
//	
	for(int i=1;i<=m;i++){
//		cout<<i<<'\n';
		int siz=z[i].size();
		for(int l=0;l<siz;l++){
			for(int r=l+1;r<siz;r++){
				int u=z[i][l].first;
				int v=z[i][r].first;
				ll ww=z[i][l].second;
				ll www=z[i][r].second;
//				cout<<ha(u,i)<<' '<<ha(v,i)<<' '<<ww<<' '<<www<<'\n'; 
				g[ha(u,i)].pb({ha(v,i),ww+www});
				g[ha(v,i)].pb({ha(u,i),ww+www});
			}
		}
//		cout<<'\n';
		for(int l=0;l<siz;l++){
			int u=z[i][l].first;
			ll ww=z[i][l].second;
			g[ha(0,i)].pb({ha(u,i),ww});
			g[ha(u,i)].pb({ha(0,i),ww});
		}
	}
	
	for(int i=1;i<=m;i++){
		solve(i);
	} 
//	
//	for(int i=1;i<=m;i++){
//		cout<<i<<'\n';
//		for(int j=0;j<=n;j++){
//			for(int u=1;u<=m;u++) cout<<dis[i][ha(j,u)]<<' ';
//			cout<<'\n';
//		}
//		cout<<'\n';
//		
//	}
//	
	while(q--){
		int l,r;
		cin>>l>>r; 
		ll ans=1e18;
		for(int i=1;i<=n;i++){
			chkmin(ans,dis[l][ha(i,r)]+mp[{i,r}]);
		}
//		chkmin(ans,dis[l][ha(i,r)]+b[l][r]);
		ans=ans+w[l]+w[r];
		cout<<ans<<'\n';
		
	}

	
	return 0;
}


