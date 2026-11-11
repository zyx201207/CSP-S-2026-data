#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N=5e5+10;
const int INF=9223372036854775807;

int w[N];
int f[5010][5010];
vector<int> num[N];
int a[N],t[N];
vector<pair<int,int> > e[N];

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=m; j++) {
			f[i][j]=INF;
		}
		f[i][i]=0;
	}
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			cin>>a[j]>>t[j];
		}
		for(int j=1; j<=k; j++) {
			for(int l=1; l<=k; l++) {
				f[a[j]][a[l]]=min(f[a[j]][a[l]],t[j]+t[l]);
				f[a[l]][a[j]]=min(f[a[l]][a[j]],t[j]+t[l]);
			}
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=m; j++) {
			for(int k=1; k<=m; k++) {
				if(f[j][i]!=INF&&f[i][k]!=INF) {
					f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
					f[k][j]=min(f[k][j],f[j][i]+f[i][k]);
				}
			}
		}
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		cout<<ans+f[x][y]<<endl;
	}
}
