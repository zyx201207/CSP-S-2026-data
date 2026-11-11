#include<bits/stdc++.h>
using namespace std;

long long ans=0;
long long n,m,maxn=-1e13,minn=1e13;
long long a[500010];

bool check(int mid)
{
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<mid)
		{
			cnt+=mid-a[i];
		}
	}
	return cnt>=m;
}

int main() 
{
	freopen("crystal.in","r",stdin);
	freopem("crystal.out","w",sdtout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a+1,a+n+1);
	int l=minn,r=maxn,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<l<<endl;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=l) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
