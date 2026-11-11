#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[10005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
    int c=a[1];
    for(int i=1;i<=m;i++)
    {
    	c=min(c,a[i]);
	}
	cout<<c;
	return 0;
}