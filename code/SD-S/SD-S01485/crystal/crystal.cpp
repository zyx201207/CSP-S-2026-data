#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,A[N],S[N];
int check(int x)
{
	if(x==1) return 1;
	int sum=0;
	for(int i=x;i<=n;i++)
	{
		if(x*A[i]-(S[i]-S[i-x])<=m)
			return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&A[i]);
	sort(A+1,A+1+n);
	for(int i=1;i<=n;i++)
		S[i]=S[i-1]+A[i];
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
注意特殊情况。 
*/
