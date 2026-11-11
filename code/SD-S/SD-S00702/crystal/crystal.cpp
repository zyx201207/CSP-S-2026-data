#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll hare=500005;
ll a[hare];
ll cha[hare];
ll n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
    {
    	scanf("%lld",&a[i]);
	}
	cha[0]=0;
	sort(a+1,a+1+n);
	for(ll i=2;i<=n;i++)
	{
		cha[i-1]=a[i]-a[i-1];
		cha[i-1]=cha[i-1]*(i-1)+cha[i-2];
		if(cha[i-1]>m)
		{
			printf("%lld",i-1);
			return 0;
		}
	}
	return 0;
}

