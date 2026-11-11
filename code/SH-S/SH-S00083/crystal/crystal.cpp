#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,ans=1;
int C=1; //ÌØÊâ²âÊÔµã (1:ÆôÓÃ) 
long long m,A[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>A[i];
	}
	sort(A+1,A+n+1);
	for(int i=3;i<=n;++i)
	{
		if(A[i]-A[i-1]!=A[2]-A[1])  C=0;
	}
	
	if(C==1)
	{
		int l,r,mid;
		long long delta=A[2]-A[1],Cost;
		for(int i=2;i<=n;++i)
		{
			l=1;r=i-1;
			while(l<=r)
			{
				mid=(l+r)/2;
				Cost=1ll*(i-mid)*(i-mid+1)/2*delta;
				if(Cost<=m)
				{
					ans=max(ans,i-mid+1);
					r=mid-1;
				}
				else  l=mid+1;
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	
	
	long long sum=0;
	for(int i=2;i<=n;++i)
	{
		sum=0;
		for(int j=i-1;j>=1;j--)
		{
			if(sum+A[i]-A[j]<=m)
			{
				sum+=(A[i]-A[j]);
				ans=max(ans,i-j+1);
			}
			else
			{
				break;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}

