#include<bits/stdc++.h>
using namespace std;
int n,ans,nowans;
long long m,a[500005],al[500005],eq,now;
bool flag=true;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	al[0]=a[0];
	int eq=a[1]-a[0];
	for(int i=1;i<n;i++)
	{
		al[i]=al[i-1]+a[i];
		if((a[i]-a[i-1])!=eq)flag=false;
	}
	if(flag)
	{
		now=0;
		for(int i=1;i<n;i++)
		{
			if((now+eq*i)>m)break;
			now+=eq*i;
			ans++;
		}
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
			{
				nowans++;
			}
			else
			{
				nowans=0;
				for(int j=i-1;j>=0;j--)
				{
					if((a[i]*(i-j)-al[i-1]+al[j-1])>m)break;
					nowans++;
				}
			}
			ans=max(ans,nowans);
		}
	}
	printf("%d",ans+1);
	return 0;
} 