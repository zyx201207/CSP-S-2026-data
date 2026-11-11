#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int ans,maxn,ans1;
inline bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		maxn=max(maxn,a[i]); 
		if(i==1)ans1=a[1];
		else ans1&=a[i];
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		cout<<ans1;
		return 0;
	}
	if(m==2)
	{
		maxn=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(j!=i)
					maxn=max(maxn,a[i]&a[j]);
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++)
		ans=ans&a[i];
	printf("%lld",ans);
	return 0;
} 
