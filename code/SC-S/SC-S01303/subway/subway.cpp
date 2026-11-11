#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f
const int MAXM=2e3+10;
int c,n,m,d,q;
//vector<vector<int> > dis;
int dis[MAXM][MAXM];
vector<int> node;
//vector<vector<bool> >edge;
//bool edge[MAXM][MAXM];
int w[MAXM];
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f3f3f3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; ++i) {
		cin>>w[i];
	}
	int cnt=m;
	for(int i=1; i<=n; ++i) {
		int k;
		cin>>k;
		cnt++;
		for(int j=1; j<=k; ++j) {
			int a,t;
			cin>>a>>t;
			dis[a][cnt]=t;
			dis[cnt][a]=t;
//			cout<<dis[a][cnt]<<' '<<dis[cnt][a]<<endl;
//			edge[a][cnt]=edge[cnt][a]=true;
//			node.push_back(a);
//			node.push_back(cnt);
		}
	}
	for(int k=1; k<=m+cnt; ++k) {
		for(int i=1; i<=m+cnt; ++i) {
			for(int j=1; j<=m+cnt; ++j) {
//				if(edge[i][j]==true) {
//					dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
//				}
//				else {
//					dis[i][j]=dis[i][k]+dis[k][j];
//					edge[i][j]=true;
//				}
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	while(q--) {
		int s,e;
		cin>>s>>e;
		cout<<dis[s][e]+w[s]+w[e]<<endl;
	}
	return 0;
}