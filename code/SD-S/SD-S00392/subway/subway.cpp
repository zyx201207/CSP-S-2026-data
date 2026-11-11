#include <bits/stdc++.h>
using namespace std;
//¿ªlonglong
bool mlest;

double tlest,tleed;

const long long M=1000;

const long long N=5e5+10;

const long long inf=1e18;

long long c,n,m,d,q,mp[M][M],w[N];

struct edge{
	long long v,w;
};

vector<edge> e[N];

void read(){
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			mp[i][j]=inf;
		}
		mp[i][i]=0;
	}
	for(long long i=1;i<=n;i++){
		long long k; cin>>k;
		for(long long j=1;j<=k;j++){
			long long v,x;
			cin>>v>>x;
			e[v].push_back({i,x});
		}
	}
	for(long long i=1;i<=m;i++){
		for(auto x:e[i]){
			for(auto y:e[i]){
				long long u=x.v;
				long long v=y.v;
				long long w=x.w+y.w;
				mp[u][v]=min(mp[u][v],w);
				mp[v][u]=min(mp[v][u],w);
			}
		}
	}
}

void init(){
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
}

void compute(){
	while(q--){
		long long a,b;
		cin>>a>>b;
		long long ans=inf;
		for(auto x:e[a]){
			for(auto y:e[b]){
				long long u=x.v;
				long long v=y.v;
				ans=min(ans,mp[u][v]+x.w+y.w+w[a]+w[b]);
			}
		}
		cout<<ans<<'\n';
	}
}

void clear(){

}

void run(){
	read();
	init();
	compute();
	clear();
}

bool mleed;

void wa(){
	cerr<<"\n"<<tleed-tlest<<"ms\n"<<(&mleed-&mlest-1)/1024.0/1024.0<<"MB";
}

void fre(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	fre("subway");
	tlest=clock();
	run();
	tleed=clock();
//	wa();
	return 0;
}

