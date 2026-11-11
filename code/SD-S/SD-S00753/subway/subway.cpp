#include <bits/stdc++.h>
#define int long long
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
/*
by qqqaaazzz

CSP - 2026 !

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
int c,n,m,d,q;
int w[500010];
int k[500010];
vector<pair<int,int> > v[500010];
int g[510][510];//correct ? correct!
const int inf = 1e18;

signed main()
{
//	system("fc 1.out subway7.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	FAST;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;x+=n;
			v[i].push_back({x,y});
			v[x].push_back({i,y});
		}
	}memset(g,0x3f,sizeof(g));
	
	for(int i=n+1;i<=n+m;i++){
		//均值不等式算吧算吧，复杂度是对的。 
		for(auto x : v[i]){
			for(auto y : v[i]){
//				cout<<x.first<<" "<<y.first<<"^\n";
				g[x.first][y.first]=min(g[x.first][y.first],x.second+y.second);
			}
		}
	}
	
//	int cnt=n+m;
	
	for(int i=1;i<=n;i++){
		g[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(auto a:v[x+n]){
			for(auto b:v[y+n]){
				ans=min(ans,g[a.first][b.first]+a.second+b.second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}

