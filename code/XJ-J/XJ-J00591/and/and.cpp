#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,s,maxs;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	maxs=0;
	for(int i=1;i<=n-m+1;i++)
	{
		if(m==1)
		{
			maxs=max(maxs,a[i]);
			continue;
		}
		for(int j=i;j<i+m-1;j++)
		{
			s=a[j]&a[j+1];
		}
		maxs=max(maxs,s);
	}
	cout<<maxs;
	return 0;
}