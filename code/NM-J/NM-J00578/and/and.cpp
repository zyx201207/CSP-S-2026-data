#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[100000005],maxn=0,cnt[2005]={},cnt1=0,minn;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=maxn)
			{
				maxn=a[i];
			}
		}
		cout<<maxn;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i]==a[j])
				{
					cnt1++;
					cnt[cnt1]=a[i];
				}
			}
		}
		sort(cnt+1,cnt+cnt1,cmp);
		cout<<cnt[1];
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=minn)
			{
				minn=a[i];
			}
		}
		cout<<minn;
	}
    return 0;
}

