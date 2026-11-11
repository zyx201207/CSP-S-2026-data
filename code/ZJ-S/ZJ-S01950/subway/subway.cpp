#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
const int N=501005;
int tes,n,m,D,Q,a[N];
ll dis[505][505];
vector<pii> rh[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>tes>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1,nn;i<=n;i++){
		cin>>nn;
		for(int x,y;nn;nn--){
			cin>>x>>y;
			rh[x].push_back({i,y});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=m;k++){
		for(auto it1:rh[k]){
			int i=it1.first,z1=it1.second;
			for(auto it2:rh[k]){
				int j=it2.first,z2=it2.second;
				dis[i][j]=dis[j][i]=min(dis[j][i],(ll)z1+z2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		ll ans=2e18;
		for(auto it1:rh[x]){
			int i=it1.first,z1=it1.second;
			for(auto it2:rh[y]){
				int j=it2.first,z2=it2.second;
				ans=min(ans,dis[i][j]+z1+z2);
			}
		}
		cout<<a[x]+a[y]+ans<<'\n';
	}
	return 0;
}