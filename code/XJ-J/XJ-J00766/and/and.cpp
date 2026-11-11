#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	ll maxn=LLONG_MIN;
	for(int i=1;i<=n-m+1;i++)
	{
		int t=a[i];
		for(int j=i+1;j<=m;j++)
		{
			t=t&a[j];
		}
		maxn=max(maxn,(ll)t);
	}
	cout<<maxn;
}