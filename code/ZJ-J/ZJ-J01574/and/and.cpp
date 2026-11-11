#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n;i>=n-m+1;i--)
	{
		cout<<a[i]<<" ";
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
