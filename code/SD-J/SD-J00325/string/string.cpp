#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],b[200005],ans=0;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
        b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int z=b[n];
	if(z==1)
	{
		for(long long i=1;i<=n/2;i++)
		{
			if(c[i]!=c[n-i+1])
			{
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	long long left=1,right=n;
	while(left<right)
	{
		if(a[left]<a[right])
		{
			if(c[left]!=c[right])
			{
				ans+=min(a[left],a[right]);
			}
			a[right]-=a[left];
			left++;
		}
		else if(a[left]>a[right])
		{
			if(c[left]!=c[right])
			{
				ans+=min(a[left],a[right]);
			}
		    a[left]-=a[right];
		    right--;
		}
		else
		{
			if(c[left]!=c[right])
			{
				ans+=a[left];
			}
			left++;
			right--;
		}
	}
	cout<<ans;
	return 0;
} 
