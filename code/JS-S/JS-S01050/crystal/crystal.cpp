#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005]={0};
long long b[500005]={0};
long long cnt,ans;

void check(long long p)
{
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		b[i]=abs(a[i]-p);
	}
	sort(b+1,b+n+1);
	long long mm=m;
	for(int i=1;i<=n;i++)
	{
		if(mm-b[i]>=0)
		{
			cnt++;
			mm-=b[i];
		}
		else
		{
			break;
		}
	}
	return;
}		

void d(long long l,long long r)
{
	long long mid;
	if(l<r)
	{
		mid=(l+r)/2;
		check(mid);
		if(cnt>=ans)
		{
			ans=cnt;
		}
		d(mid+1,r);
		d(l,mid-1);
	}
	return;
}
	
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	long long maxn=-1000000000000;
	long long minn=1000000000000;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxn)
		{
			maxn=a[i];
		}
		if(a[i]<minn)
		{
			minn=a[i];
		}
	}
	sort(a+1,a+n+1);
	d(minn,maxn+m);
	cout<<ans;
	return 0;
}
