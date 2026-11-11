#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
long long a[500005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+1+n);
	long long s=0;
	for(int i=1,j=1; i<=n; i++) {
		s+=a[i];
		while((i-j+1)*a[i]-s>m) s-=a[j], j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}