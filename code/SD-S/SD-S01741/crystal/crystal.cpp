#include<bits/stdc++.h>
using namespace std;
long long m,k,sum=0,ans=1,minn=200000,maxn=-200000;
int n;
bool sgn=1;
long long a[500010];
int b[200010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	cin>>a[1]>>a[2];
	k=a[2]-a[1];
	b[100000+a[1]]++;
	b[100000+a[2]]++;
	minn=min(minn,a[1]);
	maxn=max(maxn,a[2]);
	minn=min(minn,a[1]);
	maxn=max(maxn,a[2]);
	for(int i=3;i<=n;i++)
	{
		cin>>a[i];
		b[100000+a[i]]++;
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
		if(sgn&&k!=a[i]-a[i-1])
		{
			sgn=0;
		}
	}
	if(sgn)
	{
		k=abs(k);
		for(int i=1;i<n;i++)
		{
			if(m>=k*i)
			{
				sum++;
				m-=k*i;
			}
			else
			{
				break;
			}
		}
		cout<<(sum+1);
	}
	else
	{
		sort(a+1,a+n+1);
		for(int i=minn;i<maxn;i++)
		{
			long long mm=m;
			sum=0;
			for(int j=i-1;j>=minn;j--)
			{
				if(mm-(i-j)*b[100000+j]>=0)
				{
					mm-=(i-j)*b[100000+j];
					sum+=b[100000+j];				}
				else
				{
					sum+=mm/(i-j);
					break;
				}
			}
			sum+=b[100000+i];
			ans=max(ans,sum);
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
