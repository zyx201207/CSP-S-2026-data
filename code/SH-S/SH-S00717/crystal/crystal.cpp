#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lli%lli",&n,&m);
	for(int i=0; i<n; i++)cin>>a[i];
	for(int i=1; i<n-1; i++)
		if(a[i]-a[i-1]!=a[i+1]-a[i])break;
	sort(a,a+n);
	for(int i=n-1; i>=0; i--) {
		long long z=m,cnt=0;
		for(int j=0; z>=0&&i-j>=0; j++)
			cnt++,z-=a[i-j]-a[i-j-1];
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
