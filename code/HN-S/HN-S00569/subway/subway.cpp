#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,D,q,w[M];
vector<int>a[M],t[M];
int d[N][N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(d,0x3f,sizeof d);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			int x,y;cin>>x>>y;
			a[x].push_back(i);
			t[x].push_back(y);
		}
	}
	for(int i=1;i<=m;i++){
		int k=a[i].size();
		for(int j=0;j<k;j++)
			for(int p=0;p<k;p++)
				d[a[i][j]][a[i][p]]=min(
					d[a[i][j]][a[i][p]],
					t[i][j]+t[i][p]
				);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		int ans=1e18;
		for(int i=0,l1=a[x].size();i<l1;i++)
			for(int j=0,l2=a[y].size();j<l2;j++)
				ans=min(
					ans,
					w[x]+w[y]+
					t[x][i]+t[y][j]+
					d[a[x][i]][a[y][j]]
				);
		cout<<ans<<'\n';
	}
	return 0;
}