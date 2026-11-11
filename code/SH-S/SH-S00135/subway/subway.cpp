#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

using namespace std;
const int M=5e5+5;
const int N=500+5;
const long long myinf=2e18;

int c,n,m,D,q;
long long w[M];
//vector<int> g[N];//ditiexian you naxie dian
struct node{
	int di;
	long long t;
};
vector<node> d[M];//zhege dian you naxie ditiexian 
long long mp[N][N];
long long dis[N][N];
void init(){
	rep(i,1,n)
		rep(j,1,n)
			if(i!=j)
				mp[i][j]=myinf;
}
void floy(){
	rep(k,1,n)
		rep(i,1,n)
			rep(j,1,n)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
void solve(){
	cin>>c>>n>>m>>D>>q;
	rep(i,1,m)cin>>w[i];
	rep(i,1,n){
		int k;
		cin>>k;
		rep(j,1,k){
			int a;
			long long t;
			cin>>a>>t;
			d[a].push_back({i,t});
		}
	}
	
	init();
	rep(i,1,m){
		int s=d[i].size();
		rep(j,0,s-1)
			rep(k,j+1,s-1){
				long long u=d[i][j].di,v=d[i][k].di;
				long long w=d[i][j].t+d[i][k].t;
				mp[u][v]=min(mp[u][v],w);
				mp[v][u]=mp[u][v];
			}
	}
	rep(i,1,n)
		rep(j,1,n)
			dis[i][j]=mp[i][j];
	floy();
	//cout<<dis[1][2]<<endl;
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=myinf;
		for(auto i:d[x])
			for(auto j:d[y])
				ans=min(ans,dis[i.di][j.di]+i.t+j.t);
		//cout<<ans<<endl;
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	//cout<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int TEST=1;
	//cin>>TEST;
	while(TEST--)
		solve();
	return 0;
}
