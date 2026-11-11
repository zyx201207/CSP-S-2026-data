#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
int c,n,m,d,q;
ll w[N],dis[505][505];
unordered_map<int,int> t[505];
vector<pair<int,int>> a[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++) cin>>w[i];
	for(int i = 1,k;i<=n;i++){
		cin>>k;
		for(int j = 1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[x].push_back(make_pair(i,y));
			t[i][x] = y;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1;i<=n;i++) dis[i][i] = 0;
	for(int i = 1;i<=m;i++){
		int sz = a[i].size();
		for(int j = 0;j<sz;j++){
			for(int k = j+1;k<sz;k++){
				int x = a[i][j].first,y = a[i][k].first;
				ll co = (ll)a[i][j].second+a[i][k].second;
				dis[x][y] = dis[y][x] = min(dis[x][y],co);
			}
		}
	}
	for(int k = 1;k<=n;k++)
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++)
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		ll res = LLONG_MAX;
		for(auto i:a[x]){
			for(auto j:a[y]){
				res = min(res,dis[i.first][j.first]+t[i.first][x]+t[j.first][y]);
			}
		}
		cout<< res+w[x]+w[y] <<'\n';
	}
	return 0;
}
