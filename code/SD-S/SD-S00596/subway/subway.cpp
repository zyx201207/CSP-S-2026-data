#include<bits/stdc++.h>
using namespace std;
#define int long long
using pii=pair<int,int>;
void work1();

const int N=1e6+10,M=34;
const int INF=2e17;
const int MOD=1e9+7;
int csd,n,m,d,qq,w[N],k[N],dis[N],vis[N],dy[N],f[N][34],sum[N];
vector<int> a[N],t[N];
vector<pii> bt[N],vc[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
int getid(int x,int i){
	return (i-1)*m+x;
}
void dijstra(int x){
	for(int i=1;i<=m*n+m;i++){
		dis[i]=INF;
		vis[i]=0;
	}
//	cerr<<"HEAD: "<<getid(x,n+1)<<'\n';
//	for(int i=1;i<=n;i++){
		dis[getid(x,n+1)]=0;
		q.push({0,getid(x,n+1)});
//	}
	while(!q.empty()){
		auto p=q.top();
		q.pop();
		auto u=p.second;
		if(vis[u])continue;
		vis[u]=1;
//		cerr<<u<<' '<<p.first<<'\n';
		for(auto e:vc[u]){
			auto v=e.first,w=e.second;
//			cerr<<"fs: "<<v<<' '<<w<<'\n';
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
//int ccc=0;
//void dfs(int u,int fa){
//	if(vis[u]){
//		cerr<<u<<'\n';
//		exit(0);
//	}
//	vis[u]=1;
//	f[u][0]=fa;
//	dis[u]=dis[fa]+1;
//	
//	for(int i=1;i<M;i++){
//		f[u][i]=f[f[u][i-1]][i-1];
//	}
//	for(auto e:vc[u]){
//		auto ef=e.first,es=e.second;
//		if(ef==fa){continue;}
//		sum[ef]=sum[u]+es;
//		cerr<<ef<<' '<<sum[ef]<<' '<<u<<'\n';
//		ccc++;
//		if(ccc>100){
//			exit(0);
//		}
//		dfs(ef,u);
//	}
//}
//int zlca(int a,int b){
//	if(dis[a]<dis[b]){
//		swap(a,b);
//	}
//	for(int i=M-1;i>=0;i--){
////		cerr<<a<<' '<<b<<'\n';
//		if(dis[f[a][i]]>=dis[b]){
//			a=f[a][i];
//		}
//	}
//	
//	if(a==b){
//		return a;
//	}
//	for(int i=M-1;i>=0;i--){
//		if(f[a][i]!=f[b][i]){
//			a=f[a][i];
//			b=f[b][i];
//		}
//	}
//	return f[a][0];
//}
void work1(){
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int x,ti;cin>>x>>ti;
			a[i].push_back(x);
			t[i].push_back(ti);
//			dy[getid(x,i)]=ti;
//			bt[x].push_back({i,ti});
			vc[getid(x,n+1)].push_back({getid(x,i),ti});
			vc[getid(x,i)].push_back({getid(x,n+1),ti});
			if(j>1){
				vc[getid(x,i)].push_back({getid(a[i][j-1],i),0});
				vc[getid(a[i][j-1],i)].push_back({getid(x,i),0});
			}
		}
	}
//	cerr<<"OK!!!\n";
//	for(int p=1;p<=m;p++){
//		for(auto x:bt[p]){
//			for(auto y:bt[p]){
//				if(x==y){
//					continue;
//				}
//				auto xf=x.first;
//				auto xs=x.second;
//				auto yf=y.first;
//				auto ys=y.second;
//				if(getid(p,xf)==2&&getid(p,yf)==7||getid(p,xf)==7&&getid(p,yf)==2){
//					continue;
//				}
//				vc[getid(p,xf)].push_back({getid(p,yf),xs+ys});
//				vc[getid(p,yf)].push_back({getid(p,xf),xs+ys});
//			}
//		}
//	}
	map<pii,int> mp;
	for(int p=1;p<=m*n+m;p++){
		for(auto e:vc[p]){
			auto xx=p,yy=e.first;
			if(xx>yy)swap(xx,yy);
			mp[{xx,yy}]=e.second;
		}
	}
//	for(int p=1;p<=m*n+m;p++){
//		vc[p].clear();
//	}
//	for(auto e:mp){
//		cerr<<e.first.first<<' '<<e.first.second<<' '<<e.second<<'\n';
//		vc[e.first.first].push_back({e.first.second,e.second});
//		vc[e.first.second].push_back({e.first.first,e.second});
//	}
//	cerr<<"OK!!!\n";
//	dfs(getid(1,n+1),0);
//	cerr<<sum[12]<<'\n';
//	cerr<<zlca(13,4)<<'\n';
	while(qq--){
		int x,y;
		cin>>x>>y;
		dijstra(x);
		int ans=dis[getid(y,n+1)];
//		cerr<<zlca(getid(x,n+1),getid(y,n+1))<<'\n';
		ans+=w[x]+w[y];
//		for(int i=1;i<=m*n+m;i++){
//			if(dis[i]==INF){
//				cerr<<"! ";
//				continue;
//			}
//			cerr<<dis[i]<<' ';
//		}
//		cerr<<'\n';
//		cerr<<"THE ANS: "<<ans<<'\n';
		cout<<ans<<'\n';
	}
}
void solve(){
	cin>>csd>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
//	if(csd<=8){
		work1();
//		return;
//	}
	
}
signed main(){
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>csd;
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

