#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+10;
int w[N]; //每个地铁站的地铁口走到站厅需要的时间
int k[N]; //第i条线路经过的地铁站数
vector<int> a[550]; //a[i][j]表示第i条线路经过的第j个地铁站
vector<int> b[N]; //b[i][j]表示第i个地铁站经过的第j条线路
int t[N][550]; //，t[i][j]表示从i地铁站的站厅走到第j条线路的站台需要的时间
//x条线上从站点y站厅到z站厅 :  t[y][x]+t[z][x]
ll ans=1e18+10;
bool vis[N];
void F(int x,int y,ll tt){
//	if(tt>100) return;
	if(x==y){
		ans=min(ans,tt);
		return;
	}
	for(auto c:b[x]){
		if(vis[c]==1) continue;
		vis[c]=1;
		for(auto d:a[c]){
			F(d,y,tt+t[x][c]+t[d][c]);
		}
		vis[c]=0;
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q; //测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y; cin>>x>>y;
			a[i].push_back(x);
			t[x][i]=y;
		}
	}
	for(int i=1;i<=n;i++){
		for(auto c:a[i]){
			b[c].push_back(i);
		}
	}
	while(q--){
		int x,y; cin>>x>>y;
		F(x,y,0);
		cout<<ans+w[x]+w[y]<<'\n';
		ans=1e18+10;
		for(int i=1;i<=n;i++) vis[i]=0;
	}
	return 0;
} 
