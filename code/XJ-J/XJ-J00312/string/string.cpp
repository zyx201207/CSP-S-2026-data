#include<bits/stdc++.h>
using namespace std;
long long a[200000+100];
char s[200000+100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int n1=n;
	for(int i=1;i<=n1;i++)
	{
		cin>>a[i]>>s[i];
		if(s[i]==s[i-1])
		{
			a[i-1]+=a[i];
			i--;
			n1--;
		}

	}
	long long ans=0;
	int l=1,r=n1;
	while(l<r)
	{
		if(s[l]!=s[r])
		{
			if(a[l]<=a[r])
			{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;			
			}		
		}
		else
		{
			if(a[l]<=a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else
			{
				a[l]-=a[r];
				r--;			
			}
		}
	}
	cout<<ans;
	return 0;
}
