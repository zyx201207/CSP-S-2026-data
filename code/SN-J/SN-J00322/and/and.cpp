#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],v[200005],ans=pow(2,31)-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		long long mx=0,mxi=0;
		for(int j=1;j<=n;j++)
		{
			if(v[j]==0)
			{
				if((ans&a[j])>=(ans&mx))
				{
					mx=a[j];
					mxi=j;
				}
			}
		}
		v[mxi]=1;
		ans=ans&mx;
	}
	cout<<ans;
	return 0;
} 

