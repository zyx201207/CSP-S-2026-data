#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	stable_sort(a+1,a+n+1);
	long long ans=a[n];
	for(int i=n-1;i>=n-m+1;i--)ans&=a[i];
	cout<<ans;
	return 0;
}
