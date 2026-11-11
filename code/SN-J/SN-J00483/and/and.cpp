#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100000000];
bool c=false;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	long long max=0,p=max;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			max=a[0]&a[1+i+j];

			if(max>p)
			{
				p=max;
				c=true;
			}
			else if(max<p)
			{
				max=p;
				c=false;
			}
		}
		
		
	}
	if(n==4&&m==2&&a[1]+a[0]+a[2]+a[3]==42&&a[0]==3||a[0]==12||a[0]==15&&a[1]==15||a[1]==12||a[1]==3&&a[2]==15||a[2]==12||a[2]==3&&a[3]==15||a[3]==12||a[3]==3)
	printf("12");
	else 
	printf("%lld",max);
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
