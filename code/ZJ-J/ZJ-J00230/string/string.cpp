#include <bits/stdc++.h>
using namespace std;
int a[200100];
char c[200100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	while(i<j)
	{
		if(c[i]==c[j])
		{
			if(a[i]>a[j])
			{
				j--;
				a[i]-=a[j];
			}
			else if(a[i]<a[j])
			{
				i++;
				a[j]-=a[i];
			}
			else
			{
				i++;
				j--;
			}
		}
		else
		{
			if(a[i]>a[j])
			{
				sum+=a[j];
				a[i]-=a[j];
				j--;
			}
			else if(a[i]<a[j])
			{
				sum+=a[i];
				a[j]-=a[i];	
				i++;
			}
			else
			{
				sum+=a[i];
				i++;
				j--;
			}
		}
	}
	cout<<sum;
	return 0;
}
