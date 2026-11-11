#include <bits/stdc++.h>
using namespace std;
int x[1005];
int main()
{
	preopen("and.in","r",stdin)
    preopen("and.out","w",stdout)
	int n,m,a[1005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			x[i]=a[j]&a[j+1];
		}
    }
    for(int i=1;i<=n;i++)
    {
    	if(x[i]<x[i+1])
    	{
    		int c=x[i];
    		x[i]=x[i+1];
    		x[i+1]=c;
		}
	}
	cout<<x[1];
}
