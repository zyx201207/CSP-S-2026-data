#include<bits/stdc++.h>
using namespace std;
long long pai[200005];
long long a[200005];
long long ans[200005];
long long n,m;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>pai[i];
	}
	for(int j=1; j<=n; j++) {
		for(int i=j; i<=n; i++) {
			if(a[pai[i]]!=0) {
				memset(a,0,sizeof(a));
			}
			a[pai[i]]++;
		}
		for(int i=1; i<=m; i++) {
			if(a[i]>0) {
				ans[i]++;
			}
		}
		memset(a,0,sizeof(a));
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
