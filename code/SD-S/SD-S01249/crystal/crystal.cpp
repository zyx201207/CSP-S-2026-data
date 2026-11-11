#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+10;
int n,res,ans;
ll m;
ll a[M];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		while((ll)res*(a[i]-a[i-1])>m)
		{
			m+=a[i-1]-a[i-res];
			res--;
		}
		m-=(a[i]-a[i-1])*(ll)res;
		res++;
		ans=max(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}
