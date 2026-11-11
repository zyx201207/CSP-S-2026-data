#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[100001];
long long k=0;
int ans=0;
long long sum[100001];
long long q=0;
bool cmp(long long x,long long y)
{
	if(x<y) return true;
	else return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a[0]=0;
	sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i>=1;i--)
	{
		k=a[i]*i;
		q=sum[i]+m;
		if(q<k) continue;
		else if(q>=k)
		{
			ans=i;
			break;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
