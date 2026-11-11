//SN-S00468 钟林希 西安翱翔中学 
#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[500050];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++)
	{
		long long cnt=0,s=k;
		for(long long j=1;j<=n;j++)
		{
			if(a[j]>a[i])continue;
			else if(a[j]==a[i])cnt++;
			else if(s>=a[i]-a[j])
			{
					s-=a[i]-a[j];
					cnt++;
			}
			else break;
		}
		ans=max(ans,cnt);
	}
	printf("%lld",ans);
	return 0;
}
