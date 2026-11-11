#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500005],f[505][505];
vector<pair<int,int> > a[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int t,b;cin>>t>>b;
			a[t].push_back({i,b});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int k=1;k<=m;k++){
		for(auto i:a[k]){
			for(auto j:a[k]){
				if(i==j) continue;
				f[i.first][j.first]=min(f[i.first][j.first],i.second+j.second),f[j.first][i.first]=f[i.first][j.first];
			}
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]),f[j][i]=f[i][j];
	while(q--){
		int u,v,ans=0x3f3f3f3f3f3f3f3f;
		cin>>u>>v;
		for(auto i:a[u]) for(auto j:a[v]) ans=min(ans,f[i.first][j.first]+i.second+j.second);
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
} 
