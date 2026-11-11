#include<bits/stdc++.h>
using namespace std;
const int N = 5007;
typedef long long ll;
ll a[N],d[N][N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	ll c,t,n,e,cnt=0,ans=0;
	cin>>c>>t;
	while(t--) {
		cin>>n>>e;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				d[i][j] = 0x3fffff;
			}
		}
		ans=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=1; i<=n; i++) {
			d[i][i] = 0;
		}
		for(int i=1; i<n; i++) {
			for(int j=i+1; j<=(i+e) && j<=n; j++) {
				if((a[j]-a[i])<=e) {
					d[i][j] = 1;
				}
			}
		}
		for(int i=1; i<=n-1; i++) {
			for(int j=i+1; j<=n; j++) {
				for(int k=i+1; k<=j-1; k++) {
					if(i!=k && k!=j && i!=j) {
						if(d[i][j]>d[i][k]+d[k][j]) {
							cnt=0;
							d[i][j] = d[i][k]+d[k][j];
						}
						else if(d[i][j]==(d[i][k]+d[k][j])){
							cnt++;
							cout<<cnt<<"\n";
						}
					}
				}
				if(cnt==1) {
					ans++;
				}
				cnt=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
