#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,a[200005],ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	ans=a[n]&a[n-1];
	for(int i=n-2;i>=n-m+1;i--)
	ans=ans&a[i];
	cout<<ans;
	return 0;
}