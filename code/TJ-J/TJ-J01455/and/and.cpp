#include<bits/stdc++.h>
using namespace std;
long long ans;
int a[200010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	ans=a[n-m]+1;
	cout<<ans;
	return 0;
}
