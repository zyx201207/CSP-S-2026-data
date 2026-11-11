#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long num=0;
	int z;
	int o=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num+=a[i];
		cin>>b[i];
	}
	if(num%2==1)
	{
		o=1;
	}
	num/=2;
	long long s1=0;
	int i=1;
	while(s1<=num)
	{
		s1+=a[i];
		if(s1>num)
		{
			z=i;
			for(int j=n;j>=i+1;j--)
			{
				a[j+1]=a[j];
				b[j+1]=b[j];
			}
			n++;
			a[z+1]=a[z]-(s1-num+o);
			b[z+1]=b[z];
			a[z]=s1-num+o;
		}
		i++;
	}
	int l=1,r=n;
	long long g=0;
	while(l<=r)
	{
		if(b[l]!=b[r])
		{
			g+=min(a[l],a[r]);
		}
		if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else
			{
				a[r]-=a[l];
				l++;
				if(a[r]<1)
				{
					r--;
				}
			}
	} 
	cout<<g;
	return 0;
}
