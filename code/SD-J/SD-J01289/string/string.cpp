#include<bits/stdc++.h>
using namespace std;

long long a[200005];
char s[200005];
	
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	long long l=1,r=n;
	long long ans=0;
	long long x=a[1],y=a[n];
	while(l<=r)
	{
		if(x>y)
		{
			if(s[l]!=s[r])
			{
				ans=ans+y;                                
			}
			x-=y;
			r--;
			y=a[r];
		}
		else if(x<y)
		{
			if(s[l]!=s[r])
			{
				ans=ans+x;
			}
			y-=x;
			l++;
			x=a[l];
		}
		else
		{
			if(s[l]!=s[r])
			{
				ans=ans+x;
			}
			l++;
			r--;
			x=a[l],y=a[r];
		}
	}
	cout<<ans;
	return 0;
}
