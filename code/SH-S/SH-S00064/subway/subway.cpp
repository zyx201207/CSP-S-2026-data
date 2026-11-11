#include<bits/stdc++.h>
using namespace std;
#define int long long
int pl[500005];
vector<pair<int,int> > g[510005];
int f[505][505];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>pl[i];
	}
	int cnt=m;
	for(int i=1;i<=n;i++) {
		cnt++;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) {
			int x,t;
			cin>>x>>t;
			g[x].push_back({cnt,t});
			g[cnt].push_back({x,t});
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			f[i][j]=1e18;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++) {
		for(int j=0;j<g[i].size();j++) {
			for(int k=j+1;k<g[i].size();k++) {
				f[g[i][j].first-m][g[i][k].first-m]=min(f[g[i][j].first-m][g[i][k].first-m],g[i][j].second+g[i][k].second);
				f[g[i][k].first-m][g[i][j].first-m]=f[g[i][j].first-m][g[i][k].first-m];
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<i;j++) {
			for(int k=1;k<i;k++) {
				f[i][k]=f[k][i]=min(f[i][k],f[i][j]+f[j][k]);
			}
		}
		for(int j=1;j<i;j++) {
			for(int k=j+1;k<i;k++) {
				f[j][k]=min(f[j][k],f[i][j]+f[i][k]);
				f[k][j]=f[j][k];
			}
		}
	}
	for(int i=1;i<=q;i++) {
		int s,t;
		cin>>s>>t;
		int ans=1e18;
		for(int j=0;j<g[s].size();j++) {
			for(int k=0;k<g[t].size();k++) {
				ans=min(ans,f[g[s][j].first-m][g[t][k].first-m]+g[s][j].second+g[t][k].second);
			}
		}
		cout<<ans+pl[s]+pl[t]<<'\n';
	}
	return 0;
}
