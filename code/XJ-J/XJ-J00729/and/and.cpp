#include<bits/stdc++.h>
using namespace std;
long long int i,n,m,maxn=0,a[10005],maxi=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n-1;i++)
	{
		if(m==2)
		{
		maxn=a[i]&a[i+1];
		if(maxn>maxi)
		{
			maxi=maxn;
		}
			
		}
		
		if(m==3)
		{
		maxn=a[i]&a[i+1]&a[i+2];
		if(maxn>maxi)
			{
				maxi=maxn;
			}
		}
    }
    cout<<maxi;
	return 0;
}
