#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=0,sum,o;
int a[20000005];
int b[20000005];
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sum=a[1];
	for(int j=1; j<=n-1; j++) {
		for(int o=j+1; o<=n; o++) {
			for(int p=1; p<=n; p++) {
				for(int i=1; i<m; i++) {
					sum=sum&a[o];
					o+=p;
				}
				ans=max(ans,sum);
				sum=a[j];
			}
		}
	}
	cout<<ans;
	return 0;
}