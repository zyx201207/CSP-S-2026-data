#include<bits/stdc++.h>
using namespace std;
long long n,m,num=0,c;
long long q=m;
long long a[100000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<n;j++)
		{
			if(a[i]-a[j]>0)
				c=a[i]-a[j];
			else if(a[i]-a[j]<0)
				c=a[j]-a[i];
			else
			{
				num++;
				continue;
			}
			if(m-c>0)
			{
				q=m-c;
				num--;
			}
			if(q>m-a[i]+a[j+1]||q>m+a[i]-a[j+1]&&a[j+1]!=0)
			{
				q=m-(a[i]-a[j+1]);
				if(a[i]<a[j+1])
				{
					a[i]=a[i]+q;
				}
				else if(a[i]>a[j+1])
				{
					a[j+1]=a[j+1]+q;
				}
				
			}
		}
		
		m=q;
		if(m==0)
		break;
	}
	num--;
	printf("%lld",num);
	fclose(stdin);
	fclose(stdout);
	return 0;

}
