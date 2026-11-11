#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > >qu;
int c,n,m,d,q,k,a,t;
int w[N],mx[1000][1000];
vector<pair<int,int> > v[N];
vector<pair<int,int> > ve[1000];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			mx[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int ij=0;ij<v[i].size();ij++){
				int x=v[i][j].first,y=v[i][ij].first;
				if(x!=y){
					int ls=v[i][j].second,lz=v[i][ij].second;
					mx[x][y]=min(mx[x][y],ls+lz );
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j and mx[i][j]!=1e18){
				ve[i].push_back({j,mx[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mx[i][j]=1e18;
		}
		mx[i][i]=0;
		qu.push({i,0});
		while(qu.size() ){
			int x=qu.top().first;
			qu.pop();
			for(int j=0;j<ve[x].size();j++){
				int xx=ve[x][j].first,y=ve[x][j].second;
				if(mx[i][xx]>mx[i][x]+y){
					mx[i][xx]=mx[i][x]+y;
					qu.push({xx,mx[i][xx]});
				}
			}
		}
	}
	while(q--){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				int xx=v[x][i].first,yy=v[y][j].first;
				if(xx==yy){
					ans=min(ans,v[x][i].second+v[y][j].second);
				}
				else{
					ans=min(ans,mx[xx][yy]+v[x][i].second+v[y][j].second);
				}
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}