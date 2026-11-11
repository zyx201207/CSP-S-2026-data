#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],a[20005][505],mp[505][505];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)cin>>w[i];
	for(int i=1,k; i<=n; i++) {
		cin>>k;
		for(int j=1,x,t; j<=k; j++)
			cin>>x>>t,a[x][i]=t;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			mp[i][j]=1e18;
	for(int i=1; i<=n; i++)
		mp[i][i]=0;
	for(int k=1; k<=m; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++) {
				if(i==j)continue;
				if(a[k][i]==0||a[k][j]==0)continue;
				mp[i][j]=min(mp[i][j],a[k][i]+a[k][j]);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=1;i<=n;i++){
			if(a[x][i]==0)continue;
			for(int j=1;j<=n;j++){
				if(a[y][j]==0)continue;
				ans=min(ans,mp[i][j]+a[x][i]+a[y][j]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}