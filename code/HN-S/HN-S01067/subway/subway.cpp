 #include<bits/stdc++.h>
 #define QwQ 0
 using namespace std;
 const int M=250010,N=502;
 int W[N],k[N],a[N][M],x[N][M];
 int c/*c** ju ran you niang xin le*/,n,m,d,q;
 struct nd{
 	int v,w;
 	bool operator>(const nd& x)const{
 		return w>x.w;
	 } 
 };
 vector<nd>g[N*2+M];
 void build(){//jian tu
 	for(int i=1;i<=m;i++){
 		g[i].push_back({i+m,W[i]});
 		g[i+m].push_back({i,W[i]});
	 }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			g[i+m*2].push_back({a[i][j]+m,x[i][j]});
			g[a[i][j]+m].push_back({i+m*2,x[i][j]});
		}
	}
 }
 int dis[N*2+M];
 int zu(int s,int t){
 	memset(dis,0x3f,sizeof dis);
 	priority_queue<nd,vector<nd>,greater<nd>>q;
 	q.push({s,0});
 	dis[s]=0;
 	while(!q.empty()){
 		auto t=q.top();
 		q.pop();
 		int u=t.v;
 		for(auto e:g[u]){
 			int v=e.v,w=e.w;
 			if(dis[v]>dis[u]+w){
 				dis[v]=dis[u]+w;
 				q.push({v,dis[v]});
			 }
		 }
	 }
 }
 int main(){
 	freopen("subway.in","r",stdin);
 	freopen("subway.out","w",stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>x[i][j];
		}
	}
	build();
	while(q--){
		int s,t;
		cin>>s>>t;	
		zu(s,t);
		cout<<dis[t]<<"\n";
	}
 	return QwQ;
 }
//maybe 32~44pts
