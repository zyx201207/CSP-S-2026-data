#include<bits/stdc++.h>
using namespace std;
int a[1000001]={};
char z[1000001]={};
int dao[1000001]={};
char di[10000001]={};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long s=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>z[i];
	}
	for(int i=0;i<=n/2-1;i++)
	{
		dao[i]=a[i];
		di[i]=z[i];
	}
	int j=0;
	if(n%2)
	{
		for(int i=n-1;i>=n/2+1;i--)
		{
			if((a[i]!=dao[j])&&(z[i]!=di[j]))
			{
				if(a[i]>dao[j])
				{
					s+=a[i]-dao[j];
				}
				else
				{
					s+=dao[j]-a[i];
				}
			}
			if(z[i]!=di[j])
			{
				s+=a[i];
			}		 
			j++;
		}
	}
	else
	{
			for(int i=n-1;i>=n/2;i--)
		{
			if((a[i]!=dao[j])&&(z[i]!=di[j]))
			{
				if(a[i]>dao[j])
				{
					s+=a[i]-dao[j];
				}
				else
				{
					s+=dao[j]-a[i];
				}
			}
			else
			{
				if(z[i]!=di[j])
				{
					s+=a[i];
				}
			}
			j++;
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
