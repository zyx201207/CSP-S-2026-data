#include<bits/stdc++.h>
using namespace std;
long long n,a[500010],ans=1,m,c[500010];
long long f(int x,int y) {
	return c[y]-(a[y]-a[x])*(x-1)-c[x];
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)
		c[i]=c[i-1]+(a[i]-a[i-1])*(i-1);
	for(int i=1; i<=n; i++) {
		if(ans==n)
			break;
		long long l=i,r=n;
		while(l<=r) {
			long long mid=(l+r)>>1;
			if(f(i,mid)<=m)
				l=mid+1;
			else
				r=mid-1;
		}
		ans=max(ans,l-i);
	}
	cout<<ans<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}