#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,ll>

const int N=505,M=5e5+5;
int _,n,m,d,q,a[M];
vector<pii> vec[M];
ll dis[N][N];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			int a,t;cin>>a>>t;
			for(pii j:vec[a]) dis[j.first][i]=min(dis[j.first][i],j.second+t);
			vec[a].emplace_back(i,t);
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[j][i]);
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		ll res=1e18;
		for(pii i:vec[x]){
			for(pii j:vec[y]){
				res=min(res,i.second+j.second+dis[i.first][j.first]);
			}
		}
		cout<<res+a[x]+a[y]<<'\n';
	}
	return 0;
}
/*
rp++，想去WC/kel
*/