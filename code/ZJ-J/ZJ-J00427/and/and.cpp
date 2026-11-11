#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	sort(a+1,a+1+n);
	sum = a[n];
	n-=1;
	for(int i = 1;i<=m-1;i++)
    {
        sum = (sum&a[n]);
        n-=1;
    }
    cout<<sum;

	return 0;
}

