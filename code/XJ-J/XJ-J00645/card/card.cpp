#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long l=1,r=n;
	for(int i=1;i<=m;i++)
	{
		while(l<r)
		{
			long long mid=(l+r+1)/2;
			if(mid>=l)
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		cout<<l<<" ";
	}
	return 0;
}