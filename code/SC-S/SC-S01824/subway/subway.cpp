#include<bits/stdc++.h>
#define p pair<int,long long>
#define a first
#define t second 
using namespace std;
const int N=5e5+5,M=505;
int c,n,m,d,q;
int w[N];
vector<p>v[M];
long long dis[M][M];
vector<p>di[N];
void floyd(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(i==j || j==k || i==k) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin>>c>>m>>n>>d>>q;
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		dis[i][i]=0;
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x;long long y;cin>>x>>y;
			v[i].push_back({x,y});
			//cout<<x<<" "<<y<<endl;
			//cout<<di[x].size();
			di[x].push_back({i,j-1});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			int x=v[i][j].a;
			//cout<<i<<" "<<x<<"\n";
			for(int k=0;k<di[x].size();k++){
				int l=di[x][k].a,o=di[x][k].t;
				if(i==l) continue;
				dis[i][l]=min(dis[i][l],v[i][j].t+v[l][o].t);
				//cout<<x<<"\n"<<i<<" "<<v[i][x].t<<"\n"<<l<<" "<<v[l][x].t<<"\n";
				//cout<<i<<" "<<l<<" "<<dis[i][l]<<endl;
			}
		}
	}
	floyd();
	while(q--){
		int x,y;cin>>x>>y;
		long long minn=9e18;
		for(int i=0;i<di[x].size();i++){
			for(int j=0;j<di[y].size();j++){
				int uu=di[x][i].a,uuu=di[x][i].t;
				int vv=di[y][j].a,vvv=di[y][j].t;
				minn=min(minn,dis[uu][vv]+v[uu][uuu].t+v[vv][vvv].t);
			}
		}
		cout<<minn+w[x]+w[y]<<endl;
	}
	return 0;
}