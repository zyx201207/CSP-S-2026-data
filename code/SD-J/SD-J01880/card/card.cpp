#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
void Freopen()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	return ;
}
int n,m;
int A[N],T[N];
int ans[N];
signed main()
{
	Freopen();
	scanf("%lld%lld",&n,&m);
	bool ok=true;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&A[i]);
		if(A[i]<A[i-1]) ok=false;
		T[A[i]]++;
	}
	if(n<=5&&m<=2)
	{
		int ans1=0,ans2=0;
		if(A[n]==1)
		{
			ans1=n;
			ans2=T[2];
		}else if(A[n]==2)
		{
			ans2=n;
			ans1=T[1];
		}
		printf("%lld %lld\n",ans1,ans2);
	}else if(ok)
	{
		for(int i=1;i<=n;i++) ans[A[i]]=i;
		for(int i=1;i<=m;i++)
		{
			printf("%lld ",ans[i]);
		}
	}
	return 0;
}

