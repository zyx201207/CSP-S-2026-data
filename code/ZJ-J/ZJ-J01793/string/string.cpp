#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n;
char b[200005];
long long a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(i>=n) 
		{
			cout<<ans;
			return 0;
		}
		while(a[i]>0)
		{
			if(b[i]==b[n])
			{
				if(a[i]<=a[n])
				{
					a[n]=a[n]-a[i];
					a[i]=0;
				}
				else
				{
					a[i]-=a[n];
					a[n]=0;
					n--;
				}
			}
			else
			{
				if(a[i]<=a[n])
				{
					ans+=a[i];
					a[n]=a[n]-a[i];
					a[i]=0;
				}
				else
				{
					ans+=a[n];
					a[i]-=a[n];
					a[n]=0;
					n--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}