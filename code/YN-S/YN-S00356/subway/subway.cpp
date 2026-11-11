#include<bits/stdc++.h>
using namespace std;
const int N=510,M=2e4+100;
int c,n,m,d,q,w[M],k[N],a[N][M],t[N][M],dis[M][M];
struct node{
	int to,w;
};
vector<node>g[M];
int l[M];
struct node1{
	long long di;
	int now;
	bool operator<(const node1&x)const{
		return x.di>di;
	}
};
priority_queue<node1>qu;
void dijk(){
	for(int i=1;i<=m;i++){
		while(qu.size())qu.pop();
		for(int j=1;j<=m;j++)
			dis[i][j]=2e9;
		dis[i][i]=0;
		qu.push({0,i});
		while(qu.size()){
			int y=qu.top().now;
			qu.pop();
			for(node v:g[y]){
				if(dis[i][v.to]>=dis[i][y]+v.w){
					dis[i][v.to]=dis[i][y]+v.w;
					qu.push({dis[i][v.to],v.to});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			l[a[i][j]]=i;
			if(j!=1){
				g[a[i][j-1]].push_back({a[i][j],t[i][j]+t[i][j-1]});
				g[a[i][j]].push_back({a[i][j-1],t[i][j]+t[i][j-1]});
			}
		}
	}
	dijk();
	int x,y;
	while(q--){
		cin>>x>>y;
		if(x==y)cout<<0<<"\n";
		else cout<<w[x]+w[y]+dis[x][y]<<"\n";
	}
	return 0;
}
