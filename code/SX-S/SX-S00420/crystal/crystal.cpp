#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,k=0,s=0,ma=LLONG_MIN,l=0,b=0,c=0,d=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(b==0 && i>=2)
		{
			if(a[i]>=0 && a[i-1]<0)
			{
		        b=a[i]-a[i-1];
			}
			else
			{
				b=abs(abs(a[i])-abs(a[i-1]));
			}
		}
		if(b==abs(abs(a[i])-abs(a[i-1])))
		{
			c=c+1;
		}
	}
	if(c>=n-2)
	{
		while(m>=0)
		{

			m=m-b*d;
			s++;
			d++;
		}
		cout<<s;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		k=m;
        l=1;
        s=0;
		for(int o=i;o<=n;o++)
		{
			if(a[l+o]>=0 && a[l+o-1]<0)
			{
				k=k-(a[l+o]-a[l+o-1])*(o-i+1);
			}
			else
			{
			    k=k-abs(abs(a[l+o])-abs(a[l+o-1]))*(o-i+1);
			}
			if(k<0)
			{
				s=o-i+1;
				break;
		    }
		}
		if(s==0)
		{
			s=n-i;
		}
		if(s>ma)
		{
			ma=s;
		}
	}
	cout<<ma;
	return 0;
}