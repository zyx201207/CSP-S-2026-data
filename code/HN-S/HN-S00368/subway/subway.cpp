#include<bits/stdc++.h>
#define int long long
const int N=510,M=5e5+10;
using namespace std;
int c,n,m,d,q;
int w[M];
int k[N];
vector<pair<int,int > > in[M];//记录每个站连接的路
int dis[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,31,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) {
			int a,t;
			cin>>a;cin>>t;
			in[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++) {//直达时 
		for(auto xx:in[i]) {
			for(auto yy:in[i]) {
				int x=xx.first,y=yy.first;
				int tx=xx.second,ty=yy.second;
				if(x!=y) {
					int kkk=tx+ty;
					dis[x][y]=min(dis[x][y],kkk);
					dis[y][x]=dis[x][y];
				}
			}
		}
	}	
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(i!=j&&j!=k&&i!=k){
					dis[i][j]=min((long long)dis[i][j],(long long)(dis[i][k]+dis[k][j]));
				}
			}
		}
	}
	for(int i=1;i<=q;i++) {
		int st,to;
		cin>>st>>to;
		int diss=dis[501][0];
		for(auto xx:in[st]) {
			for(auto yy:in[to]) {
				int x=xx.first,y=yy.first,tx=xx.second,ty=yy.second;
				diss=min(diss,dis[x][y]+w[st]+w[to]+tx+ty);
			} 
		} 
		cout<<diss<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3 
//1 2

//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3

