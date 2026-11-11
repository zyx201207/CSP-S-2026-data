#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	long long a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int t=0;
	sort(a+1,a+n+1);
	t=a[n];
	for(int i=1;i<=m;i++)
	{
		t=a[n-i] and a[n];
	}
	cout<<t;
}
