#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int> > line[500005];
//vec[i]表示i号点位经过第j条铁/铁路到站台距离k 
int w[500005]; 
int dis[505][505];
const int maxx=1e18;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			line[a].push_back(make_pair(i,t));
		}
	}
	memset(dis,0x3f3f3f3f3f3f3f3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<line[i].size();j++){
			for(int k=0;k<j;k++){
				int x1=line[i][j].first;
				int x2=line[i][j].second;
				int x3=line[i][k].first;
				int x4=line[i][k].second;
				dis[x1][x3]=x2+x4;
				dis[x3][x1]=x2+x4;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int anss=maxx;
		for(int j=0;j<line[x].size();j++){
			for(int k=0;k<line[y].size();k++){
				int x1=line[x][j].first;
				int x2=line[x][j].second;
				int y1=line[y][k].first;
				int y2=line[y][k].second;
				anss=min(anss,x2+y2+dis[x1][y1]);
			}
		}
		anss=anss+w[x]+w[y];
		cout<<anss<<'\n';
	}
	return 0;
}
