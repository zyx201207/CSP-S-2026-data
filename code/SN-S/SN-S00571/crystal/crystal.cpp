#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n,m;
long long a[N];
bool check(int x)
{
	long long minn=1e12;
	for(int i=x;i <= n;i++)
	{
		if(a[i]==a[i+1])continue;
		long long ans=0,pos=0;
		for(int j = i;j >= 1;j--)
		{
			ans+=a[i]-a[j];pos++;
			if(pos>=x)break;
		}
		if(pos>=x)minn=min(ans,minn);
	}
	return minn<=m;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
	sort(a,a+n+1);
	int num=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		
		if(a[i]==a[i+1])
		{
			num++;continue;
		}
		sum+=num+1;
		num=0;
	}
    long long l=1,r=n,mid;
    while(l<=r)
    {
    	mid=(l+r)/2;
    	if(check(mid))
    	{
    		l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout <<r;
}
