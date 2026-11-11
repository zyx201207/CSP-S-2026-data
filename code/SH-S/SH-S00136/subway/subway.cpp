//subway
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+9;
const int INF=0x3f3f3f3f3f3f3f3f;
int nt,n,m,maxd,q;
int kou[N];//地铁口走到站厅的距离 
int k[N];//第i条线路经过几个站台 
int d[N][N];
void add(int u,int v,int cost){
	d[u][v]=min(d[u][v],cost);
	d[v][u]=min(d[v][u],cost);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>nt>>n>>m>>maxd>>q;
	for(int i=1;i<=m;i++) cin>>kou[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=j) d[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){//线路i 
		cin>>k[i];
		vector<int> tempd,tempw;
		for(int j=1;j<=k[i];j++){
			int x,t; cin>>x>>t;//站台x的线路i站走过去要t 
			for(int p=0;p<tempd.size();p++){
				add(x,tempd[p],tempw[p]+t);
			}
			tempd.push_back(x); tempw.push_back(t);
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	while(q--){
		int x,y; cin>>x>>y;
		cout<<d[x][y]+kou[x]+kou[y]<<endl;
	}
	return 0;
}
