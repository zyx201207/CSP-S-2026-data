#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n,m,a[N],ans=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(m==1)
	{
		for(int i=0;i<n;i++)
			ans=max(ans,a[i]&1);
	}
	else if(m==2)
	{
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
				ans=max(ans,a[i]&a[j]);
		}
	}
	else if(m==n)
	{
		ans=1;
		for(int i=0;i<n;i++)
			ans=ans&a[i];
	}
	else
	{
		sort(a,a+n);
		if(a[n-1]==3)
			ans=2;
		else
			ans=a[n-m];
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
