#include<bits/stdc++.h>
using namespace std;

int n,p,ans=0;
long long m,r;
long long a[500000];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	long long temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(int i=n-1;i>0;i--)
	{
		p=1;
		r=0;
		for(int j=i-1;j>=0;j--)
		{
			p++;
			r+=a[i]-a[j];
			if(r>m)
			{
				if(p-1>ans) ans=p-1;
				break;
			}
			if(j==0)
				if(p>ans) ans=p;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
