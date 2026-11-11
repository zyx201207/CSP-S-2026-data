#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
//#define popcnt __builtin_popcount
const int M=5e5+5;
const int N=505;
vector<pii>g[M*4+N];
int dis[3*M]; 
int c,n,m,d,q; 
vector<int>a[N],t[N]; 
bool vis[M*3+N]; 
int sk[N];
int cnt=0; 
void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii> >pq;
	pq.push({0,s});
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto pp:g[u]){
			int v=pp.first;
			int w=pp.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		} 
	}
}
void solve(){
	for(int i=0;i<M*3+N;i++)g[i].clear();
	cin>>c>>n>>m>>d>>q;
	for(int i=1,w;i<=m;i++)cin>>w,g[i].push_back({i+m,w}),g[i+m].push_back({i,w});
	int sumk=0; 
////	cout<<99<<endl;
	cnt=2*m+1; 
	for(int i=1,k;i<=n;i++){
	//	cout<<"000\n";
		cin>>k;
		sumk+=k;
		sk[i]=sumk; 
		a[i].resize(k+1);
		t[i].resize(k+1);
		for(int j=1;j<=k;j++)cin>>a[i][j]>>t[i][j],g[cnt++].push_back({a[i][j]+m,t[i][j]}),g[a[i][j]+m].push_back({cnt,t[i][j]});
		for(int j=2;j<=k;j++)g[cnt-j+1].push_back({cnt-j,0}),g[cnt-j].push_back({cnt-j+1,0});
	}
//	for(int i=1;i<=n;i++){
//		unordered_set<int>st;
//		unordered_map<int,int>mp;
//		for(int j=1;j<a[i].size();j++)st.insert(a[i][j]),mp[a[i][j]]=j; 
//		for(int j=i+1;j<=n;j++){
//			wei[i][j]=1e18;
//			for(int k=1;k<a[j].size();k++){
//				if(st.count(a[j][k])){
//					wei[i][j]=min(wei[i][j],t[i][mp[a[j][k]]]+t[j][k]);
//				}
//			}
//		}
//		
//	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=stops[i];j++){
//			for(int k)
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			for(int k:stops[i]){
//				if(k==i)continue;
//				g[4*m+i].push_back({j,wei[i][j]});
//				g[4*m+j].push_back({i,wei[i][j]}); 
//			}
//		} 
//		for(int j:a[i])if(j!=0)g[4*m+i].push_back({j+sk[i-1]+2*m,0}),g[j+sk[i-1]+2*m].push_back({4*m+i,0});
//	} 
//	for(int i=1;i<=n;i++)dijkstra(i);
//	while(q--){
//	//	cout<<0x3f<<endl;
//		int x,y;
//		cin>>x>>y;
//		int ans=1e18;
//		for(int i=1;i<=n;i++){
//			ans=min(ans,dis[i][x]+dis[i][y]);
//	//		cout<<dis[i][x]<<" "<<dis[i][y]<<endl;
//		}
//		cout<<ans<<endl;
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<dis[y]<<endl; 
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
//	cin>>c>>T;
	while(T--)solve();
	return 0;
}
