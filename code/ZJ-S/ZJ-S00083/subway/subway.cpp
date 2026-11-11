#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,n,a[500005],m,d,q,val[500005];
vector<pair<int,int>> ve[500005];
int dis[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>val[i];
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1,x,v;j<=k;j++){
			cin>>x>>v;
			for(auto t:ve[x])dis[t.first][i]=dis[i][t.first]=min(v+t.second,dis[t.first][i]);
			ve[x].push_back({i,v});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++)dis[j][k]=min(dis[j][i]+dis[i][k],dis[j][k]);
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		int ans=1e18;
		for(auto t1:ve[x]){
			for(auto t2:ve[y]){
				ans=min(ans,dis[t1.first][t2.first]+val[x]+val[y]+t1.second+t2.second);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}