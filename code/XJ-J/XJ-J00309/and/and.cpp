#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],s,k;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	cout<<a[m];
	return 0;
}