 #include<bits/stdc++.h>
 using namespace std;
 #define For(a,b,c) for(int a=b;a<=c;a++)
 #define Rof(a,b,c) for(int a=b;a>=c;a--)
 #define ll long long

 const int N=5e5+505;
 
 int c,n,m,d,q;
int a[N];
 vector<pair<int,int> >gr[N];

ll ds[505][505],dis[N];
bool vis[N];
vector<pair<int,int> > ha[N];
priority_queue<pair<ll,int>,vector<pair<ll,int> > ,greater<pair<ll,int> > >pq;
 
 
 void djstl(){
 	For(i,1,n){
 		For(j,1,n+m)dis[j]=0x3f3f3f3f3f3f3f3f,vis[j]=false;
 		dis[m+i]=0;
 		pq.push({0,m+i});
 		while(!pq.empty()){
 			int u=pq.top().second;
 			pq.pop();
 			if(vis[u])continue;
 			vis[u]=true;
 			for(auto& it:gr[u]){
 				if(vis[it.second])continue;
 				if(dis[it.second]>dis[u]+it.first){
 					dis[it.second]=dis[u]+it.first;
 					pq.push({dis[it.second],it.second});
				 }
			}
		 }
		 For(j,m+1,m+n)ds[i][j-m]=dis[j];
	 }
 }
 
 signed main(){
 	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 	freopen("subway.in","r",stdin);
 	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	For(i,1,m)cin>>a[i];
	For(i,1,n){
		int k;cin>>k;
		For(j,1,k){
			int u,w;cin>>u>>w;
			gr[i+m].push_back({w,u});
			gr[u].push_back({w,i+m});
			ha[u].push_back({i,w});
		}
	}
	djstl();
	For(i,1,q){
		int S,T;cin>>S>>T;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(auto& it1:ha[S]){
			for(auto& it2:ha[T]){
				ans=min(ans,1ll*a[S]+it1.second+ds[it1.first][it2.first]+it2.second+a[T]);
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0; 
 }
