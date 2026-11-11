#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,u=0;
	long long a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int t=0;
	sort(a+1,a+n+1);
	t=a[n];
	for(int i=1;i<=m-1;i++)
	{
		t=a[n-i+1] and a[n-i];
		u+=t;
	}
	cout<<u;
}
