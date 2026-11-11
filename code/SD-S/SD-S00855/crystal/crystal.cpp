#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
long long m;
long long a[500005],cha[500005],he[500005];
long long sum=0;
int ans=0;
long long maxn=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%d",&n);
    scanf("%lld",&m);
    for(int i=1;i<=n;i++)
    {
    	scanf("%lld",&a[i]);
    	maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		maxn=max(maxn,a[i]);
		cha[i]=maxn-a[i];
		he[i]=he[i-1]+cha[i];
	}
	int i=1,j=1;
	while(i<=n && j<=n && j<=i)
	{
		
		if((he[i]-he[j-1]-maxn*(i-j+1)+a[i]*(i-j+1))<=m)
		{
			ans=max(i-j+1,ans);
			i++;
		}
		else
		{
			j++;
		}
		
	}
	printf("%d\n",ans); 
	return 0;
}
