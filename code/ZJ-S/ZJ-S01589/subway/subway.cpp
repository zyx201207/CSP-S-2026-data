#include<bits/stdc++.h>
using namespace std;
#define int long long
 int n,m,q,ans=0;
 int a[500010];
 int ds[510][510];
 vector<pair<int,int> >vr[500010];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _;
	cin>>_>>n>>m>>_>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1,w,x,t;i<=n;i++){
		cin>>w;
		while(w--){
			cin>>x>>t;
			vr[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)ds[i][j]=1e18;
	for(int i=1;i<=m;i++)
		for(auto u:vr[i])
			for(auto v:vr[i])
				ds[u.first][v.first]=min(ds[u.first][v.first],u.second+v.second);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ds[i][j]=min(ds[i][j],ds[i][k]+ds[k][j]);
	while(q--){
		int x,y,as=1e18;
		cin>>x>>y;
		for(auto u:vr[x])for(auto v:vr[y])as=min(as,u.second+v.second+ds[u.first][v.first]);
		cout<<as+a[x]+a[y]<<"\n";
	}
	return 0;
}