#include<bits/stdc++.h>
#define int long long
const int N=2e5+10;
using namespace std;
int n,k;
int a[N];
int mx;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==n)
	{
		for(int i=1;i<=n;i++)
		{
			mx&=a[i];
		}
	}
	else if(n*n*n<=1e8)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					int p=a[i]&a[j]&a[k];
					mx=max(p,mx);
				}
			}	
		}
	}
	else 
	{
		
	}
	cout<<mx;
	return 0;
}
