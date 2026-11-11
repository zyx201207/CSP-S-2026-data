#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int z[200005];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char c;
		cin>>a[i]>>c;
		z[i]=c;
	}
	int l=0,r=n-1;
	while(l<=r)
	{
		if(z[l]==z[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r])
			{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else
			{
				ans+=a[l];
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
