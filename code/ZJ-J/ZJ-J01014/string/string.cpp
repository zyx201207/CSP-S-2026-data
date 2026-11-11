#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll s[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,mid,l;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>c[i];
		l+=s[i];
	}
	l=(l+1)/2;
	ll z=0;
	for(int i=1;i<=n;i++)
	{
		z+=s[i];
		if(z>=l)
		{
			mid=i;
			break;
		}
	}
	z=0;
	ll x=0,y=0,la=n,f=1,lla=0;
	for(int i=1;i<=mid;i++)
	{
		x+=s[i];
		for(int j=la;j>=mid;j--)
		{
			if(f)
			{
				y+=s[j];
			}
			f=1;
			if(x>y)
			{
				if(c[j]!=c[i])
				{
					z+=s[j];
					if(j==la)
					{
						z-=lla;
						lla=0;
					}
				}
			}
			else
			{
				if(c[j]!=c[i])
				{
					z+=x+s[j]-y;
					if(j==la)
					{
						z-=lla;
						lla=0;
					}
				}
				lla=x+s[j]-y;
				la=j;
				f=0;
				if(x==y)
				{
					la--;
					f=1;
					lla=0;
				}
				break;
			}
		}
	}
	cout<<z;
	return 0;
}
