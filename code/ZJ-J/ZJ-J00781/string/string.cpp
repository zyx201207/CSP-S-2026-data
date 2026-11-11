#include<bits/stdc++.h>
using namespace std;
long long sum;
int n,a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		char ch=getchar();
		c[i]=getchar();
	}
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r])
			{
				l++;
				r--;
			} 
			else 
			{
				a[l]-=a[r];
				r--;
			}
		}
		else
		{
			if(a[l]<a[r])
			{
				a[r]-=a[l];
				sum+=a[l];
				l++;
			}
			else if(a[l]==a[r])
			{
				sum+=a[l];
				l++;
				r--;
			} 
			else 
			{
				a[l]-=a[r];
				sum+=a[r]; 
				r--;
			}
		}
	}
	printf("%lld\n",sum);
	return 0;
}
