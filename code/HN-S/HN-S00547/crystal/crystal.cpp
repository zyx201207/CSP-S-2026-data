#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,a[500005];
	long long m,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=n;i>=1;i--)
	{
		for(int j=i-1;j>=1;j--)
		{
			s+=a[i]-a[j];
			if(s>m)
			{
				break;
			}
		}
		if(s<=m)
		{
			cout<<i;
			return 0;
		}
		s=0;
	}
	return 0;
}
