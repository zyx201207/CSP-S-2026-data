#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long L=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	long long l=0,la=0,r=0,ra=n+1,h=L/2,ans=0;
	while(l<h||r<h)
	{
		if(l>r)
		{
			ra--;
			int lo=r;
			if(r+a[ra]<=h)
			{
				r+=a[ra];
			}
			else
			{
				r=h;
			}
			if(c[ra]!=c[la]&&la>=1)
			{
				ans+=min(r-lo,l-lo);
			}
		}
		else
		{
			la++;
			int lo=l;
			if(l+a[la]<=h)
			{ 
				l+=a[la];
			}
			else
			{
				l=h;
			}
			if(c[la]!=c[ra]&&ra<=n)
			{
				ans+=min(l-lo,r-lo);
			}
		}
	}
	cout<<ans;
	return 0;
}
