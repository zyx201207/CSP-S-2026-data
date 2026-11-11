#include<bits/stdc++.h>
#define ll unsigned long long

using namespace std;

const ll MAXM=5e4+3;
ll c,n,m,d,q,wtime[MAXM],k[505],a[505][MAXM],t[505][MAXM];
ll ans=0LL,goin[MAXM],line,flag[MAXM];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(ll i=1; i<=m; i++) {
		cin>>wtime[i];
	}
	for(ll i=1; i<=n; i++) {
		cin>>k[i];
		for(ll j=1; j<=k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
			++flag[a[i][j]];
		}
	}
	while(q--) {
		ll x,y;
		cin>>x>>y;
		for(ll i=1; i<=m; i++) {
			goin[i]=1e9+7;
		}
		for(ll i=1; i<=m; i++) {
			if(wtime[i]==x) {
				ans+=wtime[i];
			}
		}
		for(ll i=1; i<=n; i++) {
			for(ll j=1; j<=k[i]; j++) {
				if(a[i][j]==x) {
					if(t[i][j]<goin[x]) {
						goin[x]=t[i][j];
						line=i;
					}
				}
				if(a[i][j]==y) {
					if(t[i][j]<goin[y]) {
						goin[y]=t[i][j];
					}
				}
			}
		}
		for(int j=1; j<=k[line]; j++) {
			if(flag[a[line][j]]>=2&&a[line][j]<=y) {
				for(int i=1; i<=n; i++) {
					for(int jj=1; jj<=k[i]; jj++) {
						if(i!=line) {
							if(a[i][jj]==a[line][j]) {
								if(t[i][jj]+t[line][j]<goin[j]) {
									goin[j]=t[i][jj]+t[line][j];
									line=i;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=m; i++) {
			if(goin[i]<1e9+7) {
				ans+=goin[i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}