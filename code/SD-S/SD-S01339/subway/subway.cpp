#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=500005;
int c,n,m,d,q;
int w[M];
int dis[N][N];
vector<pair<int,int> >vec[M];
void solve() {
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; ++i) cin>>w[i];
	for(int i=1; i<=n; ++i) {
		int len;
		cin>>len;
		for(int j=1; j<=len; ++j) {
			int x,ti;
			cin>>x>>ti;
			vec[x].push_back({i,ti});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1; i<=n; ++i) dis[i][i]=0;
	for(int x=1; x<=m; ++x) {
//		cout<<"stop #"<<x<<"\n";
		for(int ii=0; ii<vec[x].size(); ++ii) {
			for(int jj=ii+1; jj<vec[x].size(); ++jj) {
				int i=vec[x][ii].first,ti=vec[x][ii].second;
				int j=vec[x][jj].first,tj=vec[x][jj].second;
//				cout<<"line #"<<i<<" #"<<j<<"\n";
//				cout<<"time: "<<ti<<" "<<tj<<"\n";
				dis[i][j]=min(dis[i][j],ti+tj);
				dis[j][i]=min(dis[j][i],ti+tj);
			}
		}
	}
	//this part can be up to md^2=200,000,000=2e8
	//but sum vec[x]<=5e5，it must be ok! 
	for(int k=1; k<=n; ++k) {
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) {
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	//n^3=125,000,000=1.25e8
	while(q--) {
		int x,y;
		cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int ii=0; ii<vec[x].size(); ++ii) {
			for(int jj=0; jj<vec[y].size(); ++jj) {
				int i=vec[x][ii].first,ti=vec[x][ii].second;
				int j=vec[y][jj].first,tj=vec[y][jj].second;
				ans=min(ans,w[x]+ti+dis[i][j]+tj+w[y]);
			}
		}
		cout<<ans<<"\n";
	}
	//qd^2=4e7
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(0),cin.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
/*
哈哈哈 15:25 过两题啦 
能过全部7个样例 应该不会挂分吧 
*/

