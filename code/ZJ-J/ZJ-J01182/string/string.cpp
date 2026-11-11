#include<bits/stdc++.h>
using namespace std;
int a[200007];
char b[200007];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	long long ans=0;
	while(l<=r)
	{
		if(b[l]!=b[r])
		{
			ans+=(long long)min(a[l],a[r]);
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else
			{
				a[r]-=a[l];
				l++;
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else
			{
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}