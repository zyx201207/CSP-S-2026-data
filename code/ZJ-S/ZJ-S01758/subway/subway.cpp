#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 510;
const int M = 130000;
const int K = 5e4 + 10;
int c,n,m,d,q;
int w[M];
int k[N];
int a[N][K];
int t[N][K];
    int u,v;
    int T;
    int ans;

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	
	int ans = 0;
	for(int i=1;i<=m;++i) cin >> w[i];
	for(int i=1;i<=n;++i){
		cin >> k[i];
		for(int j=1;j<=k[i];++j){
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--){
		cin >> u >> v;
		int ans = w[u]+w[v];
		for(int i=1;i<=n;++i){
			for(int j=1;j<=k[i];++j){
				if(u == a[i][j]){
					ans+=t[i][j];
					u = a[i][j];
				//	cout << a[i][j]<<" "<<u<<"\n";
				}
			}
		}
		cout <<ans<<"\n";
	}
	return 0;
}
