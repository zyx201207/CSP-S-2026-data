#include<bits/stdc++.h>
using namespace std;
long long int n,a[200005],flag=1,ans=0,sum=0;
char b[200005],m;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i];
	}
	for(int i=1;i<n;i++)
	{
		if(b[i]!=b[i+1])
		{
			flag=0;
		}
	}
	if(flag==1)
	{
		cout << 0;
		return 0;
	}
	else
	{
		m = b[1];
		for(int i=1;i<=n;i++)
		{
			if(b[i]==m)
			{
				ans+=a[i];
			}
			else
			{
				break;
			}
		}
		for(int j=n;j>=1;j--)
		{
			if(b[j]!=m)
			{
				sum+=a[j];
			}
			else
			{
				break;
			}
		}
	}
	cout << sum-(sum-ans);
	return 0;
}