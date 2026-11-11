#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005];
int f[505][505];
vector<pair<int,int> >vec[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			vec[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)
		for(auto j:vec[i])
			for(auto k:vec[i]){
				if(j==k)continue;
				f[j.first][k.first]=min(f[j.first][k.first],j.second+k.second);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		int ans=LLONG_MAX;
		for(auto i:vec[x])
			for(auto j:vec[y])
				ans=min(ans,f[i.first][j.first]+i.second+j.second);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
//15:12 thinking end
//15:30 coding&debuging end
