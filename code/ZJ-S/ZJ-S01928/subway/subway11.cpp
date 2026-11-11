#include<bits/stdc++.h>
using namespace std;
#define int long long

//const int NN=607,N=207,M=407,Q=207;
const int NN=1507,N=507,M=1007,Q=207;
const int INF=1e17;
//const int INF=1e2;
int c,n,m,d,q;
int dis[NN][NN];
int w[M];
//int x[Q],y[Q];

//void print(){
//	cerr << "---\n";
//	for(int i=1;i<=m+n;i++){
//		for(int j=1;j<=m+n;j++){
//			cerr << dis[i][j] << '\t';
//		}
//		cerr << '\n';
//	}
//}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway2.err","w",stderr);
	
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int aa,tt;
			cin >> aa >> tt;
			dis[aa][m+i]=tt;
			dis[m+i][aa]=tt;
		}
	}
	
	//floyd
	for(int k=1;k<=m+n;k++){
		for(int i=1;i<=m+n;i++){
			for(int j=1;j<=m+n;j++){
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j]; 
				}
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		cout << w[x]+w[y]+dis[x][y] << '\n';
	}
}
