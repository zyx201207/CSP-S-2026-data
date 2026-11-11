#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int N = 500+5;
const int M = 500+5;
const int D = 20+5;
const int INF = 2147483647;
int w[M];
int k[N];
int a[N][M];
int t[N][M];

int fa[M];
int dis[M][D][M][D];//0 is zhanting

void dsuinit(){
	for(int i=0;i<=n;i++){
		fa[i]=i;
	}
}
int dsufindx(int x){
	if(fa[x]!=x){
		fa[x]=dsufindx(fa[x]);
	}
	return fa[x];
}
void dsumerge(int x,int y){
	if(dsufindx(x)!=dsufindx(y)){
		fa[dsufindx(x)]=dsufindx(y);
	}
}

void flydinit(){
	for(int i=1;i<=m;i++){
		for(int zi=0;zi<=d;zi++){
			for(int j=1;j<=m;j++){
				for(int zj=0;zj<=d;zj++){
					if(i==j&&zi==zj){
						dis[i][zi][j][zj]=0;
					}else{
						dis[i][zi][j][zj]=INF;
					}
				}
			}
		}
	}
}

void debug(){
	for(int i=1;i<=m;i++){
		for(int zi=0;zi<=d;zi++){
			for(int j=1;j<=m;j++){
				for(int zj=0;zj<=d;zj++){
					cout<<i<<" "<<zi<<" "<<j<<" "<<zj<<" :"<<dis[i][zi][j][zj]<<"\n";
				}
			}
			cout<<"\n";
		}
	}
}
signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	
	flydinit();
	dsuinit();
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			dis[a[i][j]][0][a[i][j]][i]=t[i][j];
			dsumerge(a[i][1],a[i][j]);
		}
		for(int k=1;k<=m;k++){
			for(int j=1;j<=m;j++){
				if(k==j){
					continue;
				}
				if(dsufindx(k)==dsufindx(j)){
					dis[k][i][j][i]=0;
				}
			}
		}
		dsuinit();
//		debug();
	}
	
//	debug();
	
	for(int k=1;k<=m;k++){
		for(int zk=0;zk<=d;zk++){
			for(int i=1;i<=m;i++){
				for(int zi=0;zi<=d;zi++){
					for(int j=1;j<=m;j++){
						for(int zj=0;zj<=d;zj++){
							if(dis[i][zi][k][zk]==INF||dis[k][zk][j][zj]==INF){
								continue;
							}
							if(dis[i][zi][k][zk]+dis[k][zk][j][zj]<dis[i][zi][j][zj]){
								dis[i][zi][j][zj]=dis[i][zi][k][zk]+dis[k][zk][j][zj];
							}
						}
					}
				}
			}
		}
	}
	
//	debug();
	
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][0][y][0]<<"\n";
	}
	
	return 0;
}
