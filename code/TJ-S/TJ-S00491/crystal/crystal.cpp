#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
ll a[600010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%d %lld",&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1, a+n+1);
	int ctr=a[(int)ceil(1.0*n/2)];
	for(int i=1; i<=n; i++)
	{
		a[i]=abs(a[i]-ctr);
	}
	sort(a+1, a+n+1);
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		m-=a[i];
		if(m<0) break;
		ans++;
	}
	printf("%d",ans); 
	return 0;
} 
