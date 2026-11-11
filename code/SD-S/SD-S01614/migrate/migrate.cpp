#include<bits/stdc++.h>
using namespace std;
long long n,t,c,m,a[1000010],b[1000010],ans;
int main() {
	freopen("magrate.in","r",stdin);
	freopen("magrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>m;
		ans=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		b[n]=0;
		for(int i=n; i>=2; i--) {
			if(a[i]-a[i-1]>m) b[i-1]=0;
			else b[i-1]=b[i]+1;
		}
		for(int i=1; i<=n; i++) {

			for(int j=i+1; j<=i+b[i]; j++) {
				long long ge=0;
				if(a[j]-a[i]<=m) continue;
				for(int x=i+1; x<=j; x++) {
					if(a[i]+a[j]-a[x]<=m) {
						ge++;
					}
				}
				if(ge==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Oct31==Dec25?
