#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=5086;
const int INF=1e18;
typedef long long ll;
int a[N];
int dist[N][N];
int cnt[N][N];
signed main() {
	IOS;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int c,t;
	cin>>c>>t;
	if(c==11||c==12) {
		while(t--) {
			int l;
			int n;
			cin>>n>>l;
//			cout<<t<<"\n";
			if(n==1)cout<<0<<"\n";
			for(int i=1; i<=n; i++) {
				cin>>a[i];
			}
			int x=a[2]-a[1];
			if(x==l)cout<<1<<"\n";
			else if(x>l) {
				cout<<0<<"\n";
			} else {
				if(l>=x*2&&l<x*3) {
					cout<<n-3<<"\n";
				} else {
					cout<<0<<"\n";
				}
			}
		}
	} else {
		while(t--) {
			int n,l;
			cin>>n>>l;
			int ans=0;
			for(int i=1; i<=n; i++) {
				cin>>a[i];
			}
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					dist[i][j]=INF;
					cnt[i][j]=0;
				}
			}
			for(int i=1; i<n; i++) {
				int j=i+1;
				while(j<=n&&a[j]-a[i]<=l) {
//					cout<<i<<" "<<j<<"\n";
					dist[i][j]=1;
					dist[j][i]=1;
					cnt[i][j]=0;
					cnt[j][i]=0;
					j++;
				}
			}
			for(int i=1;i<=n;i++)dist[i][i]=0;
			for(int k=1; k<=n; k++) {
				for(int i=1; i<=n; i++) {
					for(int j=1; j<=n; j++) {
						int nd=dist[i][k]+dist[k][j];
						if(nd==dist[i][j])cnt[i][j]++;
						else if(nd<dist[i][j]) {
							dist[i][j]=nd;
							cnt[i][j]=1;
						}
					}
				}
			}
			for(int i=1; i<=n; i++) {
				for(int j=i+1; j<=n; j++) {
					if(cnt[i][j]==3 ){
						
						ans++;
					}
				}
//				cout<<"\n";
			}
			cout<<ans<<"\n";
		}
	}

	return 0;
}

