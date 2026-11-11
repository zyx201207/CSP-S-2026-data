#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,p;
int dx[4]= {-1,1,0,0};
int dy[4]= {0,0,-1,1};
int w[500005];
int k[5005];
vector<array<int,3> > wi[500005];
queue<pair<int,int> > q;
map<int,map<int,int> > a;
map<int,map<int,int> > t;
map<int,map<int,int> > vis;
map<int,map<int,int> > dist;
void solve() {
	cin>>c>>n>>m>>d>>p;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
			wi[a[i][j]].push_back({t[i][j],i,j});
		}
	}
	for(int temp=1; temp<=p; temp++) {
		int X,Y;
		cin>>X>>Y;
		vis.clear();
		for(array<int,3> v:wi[X]) {
			q.push({v[1],v[2]});
			vis[v[1]][v[2]]=1;
			dist[v[1]][v[2]]=0;
		}
		while(!q.empty()) {
			pair<int,int> t=q.front();
			int x=t.first;
			int y=t.second;
			q.pop();
			for(int j=0; j<4; j++) {
				int xx=x+dx[j];
				int yy=y+dy[j];
				if(xx<1||xx>n||yy<1||yy>k[xx]) {
					continue;
				}
				if(!vis[xx][yy]) {
					vis[xx][yy]=1;
					dist[xx][yy]=dist[x][y]+1;
					q.push({xx,yy});
//					cout<<temp<<" "<<xx<<" "<<yy<<"\n\n";
				}
			}
		}
		int ans=inf;
		for(array<int,3> v:wi[Y]) {
			ans=min(ans,dist[v[1]][v[2]]);
//			cout<<v[1]<<" "<<v[2]<<"\n";
		}
		cout<<ans*t[1][1]+w[X]+w[Y]<<"\n";
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

