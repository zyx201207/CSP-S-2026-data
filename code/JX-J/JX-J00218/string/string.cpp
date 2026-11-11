#include<bits/stdc++.h>
using namespace std;
long long n,np,a[200050],ans=0;
bool k=0;
char c[200050];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    np=n;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i]>>c[i];
		if(c[i]!=c[1])k=1;
	}
	if(k==0)
	{
		cout<<0;
		return 0;
	}
	int i=1;
	while(i<np)
	{
		if(c[i]!=c[np])
		{
			if(a[i]>a[np])
			{
				ans+=a[np];
				a[i]-=a[np];
				a[np]=0;
				np--;
			}
			else if(a[i]<a[np])
			{
				ans+=a[i];
				a[np]-=a[i];
				a[i]=0;
				i++;
			}
			else
			{
				ans+=a[i];
				a[np]=0;
				a[i]=0;
				i++;
				np--;
			}
		}
		else
		{
			if(a[i]>a[np])
			{
				a[i]-=a[np];
				a[np]=0;
				np--;
			}
			else if(a[i]<a[np])
			{
				a[np]-=a[i];
				a[i]=0;
				i++;
			}
			else
			{
				a[np]=0;
				a[i]=0;
				i++;
				np--;
			}
		}
	}
	cout<<ans;
    return 0;
}
