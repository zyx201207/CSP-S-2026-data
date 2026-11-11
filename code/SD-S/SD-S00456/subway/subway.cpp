#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e16;
int c,n,m,d,q;
int w[500010];
//vectoe<pair<int,int>> G[1000010];
int k[500010];
vector<pair<int,int> > h[500010];
int f[2550][2550];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for (int i=m+1;i<=m+n;i++) {
		for (int j=m+1;j<=m+n;j++) {
			f[i-m][j-m]=f[j-m][i-m]=inf;
		}
		f[i-m][i-m]=0;
	}
	int siz=m;
	for (int i=1;i<=n;i++) {
		siz++;
		cin>>k[i];
		for (int j=1;j<=k[i];j++) {
			int u,t;
			cin>>u>>t;
			h[u].push_back({siz,t});
		}
	}
	for (int i=1;i<=m;i++) {
		for (auto j:h[i]) {
			for (auto l:h[i]) {
				int gh=j.first,gh1=j.second;
				int gg=l.first,gg1=l.second;
				if (f[gg-m][gh-m]>gh1+gg1) {
					f[gg-m][gh-m]=f[gg-m][gh-m]=gh1+gg1;
				}
			}
		}
	}
	for (int i=m+1;i<=m+n;i++) {
		for (int j=m+1;j<=m+n;j++) {
			for (int l=m+1;l<=m+n;l++) {
				if (f[i-m][j-m]>f[i-m][l-m]+f[l-m][j-m]) {
					f[i-m][j-m]=f[j-m][i-m]=f[i-m][l-m]+f[l-m][j-m];
				}
			}
		} 
	}
	/*for (int i=m+1;i<=m+n;i++) {
		//cout<<f[i][i]<<" ";
		for (int j=m+1;j<=m+n;j++) {
			cout<<f[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	while (q--) {
		int l,r;
		cin>>l>>r;
		int ans=1e17;
		for (auto i:h[l]) {
			for (auto j:h[r]) {
				int x=i.first,y=j.first;
				int x1=i.second,x2=j.second;
				//cout<<x1<<" "<<x<<"\n";
				ans=min(ans,f[x-m][y-m]+x1+x2+w[l]+w[r]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//AC
