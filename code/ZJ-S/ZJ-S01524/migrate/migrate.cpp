#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) {
		int n,d;
		cin>>n>>d;
		for(int i=0; i<n; ++i) {
			cin>>a[i];
		}
		int i=0,j=0,k=0;
		long long ans=0;
		while(i<n&&j<n&&k<n) {
			while(a[j]-a[i]<=d&&j<n) {
				++j;
			}
			k=j;
			while(a[k]-a[j]<=d&&k<n){
				++k;
			}
			ans+=max(0,k-j);
			++i;
		}
		cout<<ans<<endl;
	}

	return 0;
}
