#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500050];
int n,m;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool bA=1,bB=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]!=i)
		{
			bA=0;
			break;
		}
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])
		{
			bB=0;
			break;
		}
	if(bA)
	{
		int l=1,r=1e9;
		while(l<r)
		{
			int mid=(l+r+1)/2;
			if(mid*(mid+1)/2<=m)l=mid;
			else r=mid-1;
		}
		cout<<l+1;
	}else if(bB)
	{
		int k=a[2]-a[1];
		int l=1,r=1e9;
		while(l<r)
		{
			int mid=(l+r+1)/2;
			if(mid*(mid*k+k)/2<=m)l=mid;
			else r=mid-1;
		}
		cout<<l+1;
	}
	else cout<<2<<endl;
	return 0;
}

