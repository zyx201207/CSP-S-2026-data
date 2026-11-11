#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=200005,N=505,D=25,Q=100005,C=30;
int c,n,m,d,q;
int w[M],k[N];
int a[N][M],t[N][M];
int x[Q],y[Q];
int ans;
struct node {
	int metro,val;
};
node vec[N][D];
int num[N];
int vis[N][D];
void dfs(int id,int spend,int goal,int underground) {
	if(spend>=vis[id][underground])return;
	vis[id][underground]=spend;
//	printf("%d %d %d\n",id,spend,underground);
	if(spend>=ans)return;
	if(id==goal) {
		ans=spend;
		return;
	}
	int u=vec[id][underground].metro;
	for(int i=1; i<=k[u]; i++) {
//		if(a[u][i]==id)continue;
		if(a[u][i]==goal) {
			dfs(goal,spend+t[u][i],goal,underground);
			break;
		}
		if(num[a[u][i]]==1)continue;
		for(int j=1; j<=num[a[u][i]]; j++) {
			if(u==vec[a[u][i]][j].metro)continue;
			dfs(a[u][i],spend+t[u][i]+vec[a[u][i]][j].val,goal,j);
		}
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	cin>>n>>m>>d>>q;
	//地铁线路数，地铁站数，最多几条路经过，出行计划数
	for(int i=1; i<=m; i++)cin>>w[i]; //地铁站口走到站厅时间
	for(int i=1; i<=n; i++) {
		cin>>k[i];//第i条路线经过的地铁站数
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
			//i经过的第j个地铁站,
			//从该地铁站的站厅走到第i条线路的站台需要的时间
			num[a[i][j]]++;
			vec[a[i][j]][num[a[i][j]]].metro=i;
			vec[a[i][j]][num[a[i][j]]].val=t[i][j];
		}
	}
	for(int i=1; i<=q; i++) {
		cin>>x[i]>>y[i];//起点，终点
		memset(vis,0x3f3f3f3f3f3f3f,sizeof vis);
		ans=0x3f3f3f3f3f3f3f;
		for(int j=1; j<=num[i]; j++)dfs(x[i],w[x[i]]+w[y[i]]+vec[x[i]][j].val,y[i],j);
		cout<<ans<<endl;
	}
}
