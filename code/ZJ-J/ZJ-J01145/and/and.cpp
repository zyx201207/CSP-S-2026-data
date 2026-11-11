#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
ll i,n,m,a[N],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ans=a[n];
	for(i=n-1;i>=n-m+1;i--)ans&=a[i];
	cout<<ans;
	return 0;
}
