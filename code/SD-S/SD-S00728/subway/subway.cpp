//32~60pt 
#include<bits/stdc++.h> //阅读理解题 
using namespace std;
const int N=505;
const int M=5e4+10;
const long long INF=1e18;
int c,n,m,d,q;
int w[N],k[N],a[N][M];
vector<pair<int,int> > num[N];//num[i]是第i个站台经过的线路 
long long dis[M][N],t[N][M];
//dis[i][j]表示从i的站厅到j的站厅的最短距离 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			dis[i][j]=INF;
	for(int i=1;i<=m;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
//	cout<<"OK\n";
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			num[a[i][j]].push_back({i,j});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto o:num[i]){
			for(int j=1;j<=k[o.first];j++){
				if(a[o.first][j]==i) continue;
				dis[i][a[o.first][j]]=min(dis[i][a[o.first][j]],t[o.first][o.second]+t[o.first][j]);
			}
		}
	}
	for(int o=1;o<=m;o++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][o]+dis[o][j]);
				}
			}
		}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	} 
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<'\n';
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
