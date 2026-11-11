#include<bits/stdc++.h>
#define lon long long
#define qwq pair<lon,int>
#define INF 1e16
using namespace std;
const int M=510;
const int N=500010;
const int D=20;
const int Q=100010;
int cot,m,n,maxd,qst;
lon ww[500010];
struct station{
	int lx;
	lon t;
};
vector<station> d[500010];//floyd
lon f[510][510];
lon ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cot>>m>>n>>maxd>>qst;
	for(int i=1;i<=n;i++) cin>>ww[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			lon t;
			cin>>a>>t;
			d[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) if(i!=j) f[i][j]=INF;
	for(int i=1;i<=n;i++){
		for(int j=0;j<d[i].size();j++){
			int u=d[i][j].lx;
			for(int k=j+1;k<d[i].size();k++){
				int v=d[i][k].lx;
				f[v][u]=f[u][v]=min(f[u][v],d[i][j].t+d[i][k].t);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++) if(i!=k && j!=k){
				f[j][i]=f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=qst;i++){
		int x,y;
		cin>>x>>y;
		ans=INF;
		for(int j=0;j<d[x].size();j++){
			int u=d[x][j].lx;
			for(int k=0;k<d[y].size();k++){
				int v=d[y][k].lx;
				ans=min(ans,d[x][j].t+d[y][k].t+ww[x]+ww[y]+f[u][v]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//我求求你真是个floyd啊 ..
