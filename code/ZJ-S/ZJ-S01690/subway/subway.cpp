#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10;
const int inf=1e15;
int c,n,m,d,q,w[M];
vector<pair<int,int>> v[M];
int f[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(;k--;){
			int x,y;
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=inf;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<j;k++){
				int x=v[i][j].first,y=v[i][k].first,z=v[i][j].second+v[i][k].second;
				f[x][y]=min(f[x][y],z);
				f[y][x]=min(f[y][x],z);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cerr<<i<<" "<<j<<" "<<f[i][j]<<"\n";
//		}
//	}
	for(int x,y;q--;){
		cin>>x>>y;
		int ans=inf;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				ans=min(ans,f[v[x][i].first][v[y][j].first]+v[x][i].second+v[y][j].second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}