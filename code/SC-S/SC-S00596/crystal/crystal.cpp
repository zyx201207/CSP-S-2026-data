#include <iostream>
#include <algorithm>
#define ll long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
int n,ans,l=1;
ll m,a[N],sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int r=1;r<=n;r++)
	{
		while(r<=n&&a[r]*(r-l+1)-(sum[r]-sum[l-1])>m)
			l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}