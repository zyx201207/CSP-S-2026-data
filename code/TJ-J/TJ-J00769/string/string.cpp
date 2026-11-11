#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
unsigned long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d %c",&a[i], &c[i]);
	}
	
	int i=1, j=n;
	while(i<=j)
	{
		if(c[i]!=c[j])
		{
			ans+=min(a[i],a[j]);
		}
		if(a[i]<a[j])
		{
			a[j]-=a[i];
			i++;
		}
		else if(a[i]>a[j])
		{
			a[i]-=a[j];
			j--;
		}
		else
		{
			i++;
			j--; 
		}		
	}
	printf("%llu",ans);
	return 0;	
} 
