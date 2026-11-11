#include<bits/stdc++.h>
#define int long long 
#define ll long long 
#define ld long double
#define db double
using namespace std;
const int N=505,M=5e5+5,inf=1e18;
int C,n,m,d,q,w[M],a[N][N];
struct node{
	int x,y;
};
vector<node> vt[M];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}

	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			vt[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			a[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		int s=vt[i].size();
		for(int j=0;j<s;j++){
			for(int k=j+1;k<s;k++){
				int x=vt[i][j].x,y=vt[i][k].x;
				int X=vt[i][j].y,Y=vt[i][k].y;
				a[x][y]=min(a[x][y],X+Y);
				a[y][x]=min(a[y][x],X+Y);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		int ans=inf;
		for(int j=0;j<vt[x].size();j++){
			for(int k=0;k<vt[y].size();k++){
				int X=vt[x][j].x,Y=vt[y][k].x;
				int xx=vt[x][j].y,yy=vt[y][k].y;
				ans=min(ans,a[X][Y]+xx+yy);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}