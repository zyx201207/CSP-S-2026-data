#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=2e5+10;
int a[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int ans=a[n-m+1];
	for(int i=n-m+2;i<=n;i++)
	{
		ans&=a[i];
	}
	cout << ans;
}
