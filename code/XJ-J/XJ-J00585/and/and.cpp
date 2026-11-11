#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],b[200010];
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1) {
		long long maxn=-100010;
		for(int i=1;i<=n;i++) {
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	else {
		long long ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
		cout<<ans;
	}
	return 0;
} 
