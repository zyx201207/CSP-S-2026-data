#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],ans;
bool vis[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(long long i=30;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if((!vis[j])&&(((1<<i)&a[j])!=0))
			{
				cnt++;
			}
		}
		if(cnt>=m)
		{
			ans+=(1<<i);
			for(int j=1;j<=n;j++)
			{
				if(((1<<i)&a[j])==0)
					vis[j]=1;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}


