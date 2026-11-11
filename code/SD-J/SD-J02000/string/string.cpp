//string
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 2e5+5;
ll a[MAX];
char c[MAX];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%lld %c",&a[i],&c[i]),getchar();
	ll ans = 0,r = n+1,l = 0;
	
	for(int i=1; i<=n; i++)
	{
		if(r <= i) break;
		ll sum = l;
		ans += (c[i]==c[r]?0:l);
		while(sum < a[i])
		{
			sum += a[--r];
			ans += (c[i]==c[r]?0:a[r]);
		}
		l = sum-a[i];
		ans -= (c[i]==c[r]?0:l);
	}
	printf("%lld\n",ans);
	return 0;
}
