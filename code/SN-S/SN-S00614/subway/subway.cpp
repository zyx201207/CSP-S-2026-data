#include<iostream>
#include<vector>
#define  int  long long
using namespace std;
constexpr int N=5e5+5,M=505,INF=1e18;
bool Beg;
int C,n,m,d,q,w[N];
struct Node{
	int u,v;
};
vector<Node> v[N];
int dis[M][M];
bool End;
signed main(){
//	system("fc subway.out subway7.ans /w");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,a,t; cin>>k;
		while(k--)cin>>a>>t,
			v[a].push_back(Node{i,t});
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)dis[i][j]=INF;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)
		for(Node c:v[i])for(Node d:v[i])
			dis[c.u][d.u]=dis[d.u][c.u]=min(dis[c.u][d.u],c.v+d.v);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=q;i++){
		int x,y,rs=INF; cin>>x>>y;
		for(Node c:v[x])
			for(Node d:v[y])
				rs=min(rs,c.v+dis[c.u][d.u]+d.v);
		rs+=w[x]+w[y];
		cout<<rs<<'\n';
	}
	cerr<<(&Beg-&End)/1024.0/1024.0<<" MB\n";
	return 0;
}
