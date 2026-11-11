// 袁梓焜 西安交通大学附属中学 SN-S00341
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+510,M=510;
int c,n,m,d,q;
int a[N];
vector<pair<int,int>> edge[N];
int dis[M][M];

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>a[i];
	for(int i=1,v,w,k; i<=n; i++) {
		cin>>k;
		while(k--) {
			cin>>v>>w;
			edge[v].emplace_back(i,w);
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1; i<=n; i++) dis[i][i]=0;
	for(int i=1; i<=m; i++) {
		for(pair<int,int> j:edge[i]) {
			for(pair<int,int> k:edge[i]) {
				int u=j.first,v=k.first;
				dis[u][v]=dis[v][u]=min(dis[u][v],j.second+k.second);
			}
		}
	}
//	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cout<<dis[i][j]<<" \n"[j==n];
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

	while(q--) {
		int l,r,ans=numeric_limits<int>::max();
		cin>>l>>r;
		for(pair<int,int> i:edge[l]) {
			for(pair<int,int> j:edge[r]) {
				ans=min(ans,dis[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<ans+a[l]+a[r]<<'\n';
	}
}
