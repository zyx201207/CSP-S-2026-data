#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int maxx,pan,n;
long long m;
int main()
{
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	int pan2=a[2]-a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i+1]-a[i]!=pan2)
		{
			pan=1;	
			break;
		}
	}
	if(pan==0)
	{
		if(m<pan2)
		{
			cout<<"0";
		}
		for(int i=1;i<=n;i++)
		{
			if(m<(a[1]+a[i])*i/2)
			{
				cout<<i;
				break;
			}
			else if(m==(a[1]+a[i])*i/2)
			{
				cout<<i+1;
				break;
			}
		}
	}
    else
    {
    	
    	for(int j=m;j--;j>0)
		{
			for(int i=2;i<=n;i++)
			{
				if((i-1)*a[i]-b[i-1]==j)
				{
					maxx=max(maxx,i);
				}
			}
		}
		cout<<maxx;
	}
	return 0;
 }
