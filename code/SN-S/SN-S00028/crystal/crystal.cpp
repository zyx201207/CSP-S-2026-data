#include<bits/stdc++.h>
using namespace std;
const int AR=2e6+710;
int n,m,ans=0;
long long a[AR],b[AR];
long long tmp;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long tmp=a[1];
	if(tmp<0)
	{
		tmp=-tmp;
		for(int i=1;i<=n;i++)
		{
			a[i]+=tmp;
		}
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]+b[i-1];
	}
//	----------------------------- 
//	×óÓÒÖ¸Õë
	for(int i=1;i<=n;i++)	//	a[j]*(j-i+1)==b[j]-b[i-1]+mÌîÆ½Ê± 
	{
		int l=i,r=n;
		int mid;
		
		while(l<r)
		{
			mid=((l+r)>>1);
			if(a[mid]*(mid-i)==b[mid-1]-b[i-1]+m)
			{
				while(a[mid]==a[mid+1])
				{
					mid++;
				}
				ans=max(mid-i+1,ans);
				break;
			}
			if(a[mid]*(mid-i)<m+b[mid-1]-b[i-1]) //
			{
				ans=max(ans,mid-i+1);
				l=mid+1;
			}
			else 
			{
				r=mid-1;
			}
		}
	}
	cout<<ans;
	return 0;
}
