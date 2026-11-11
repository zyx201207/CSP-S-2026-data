#include<bits/stdc++.h>
using namespace std;
#define int long long
int const N=2e5+10;
int a[N];
cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1; i<=n; i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int ans=a[1];
	for(int i = 1; i<=m; i++)
	{
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
 } 
