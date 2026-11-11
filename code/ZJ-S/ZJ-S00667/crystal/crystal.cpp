#include<bits/stdc++.h>
using namespace std;
long long m,s[1000010],a[1000010];
int n,l,r,mid;
int check(int x)
{
	for(int i=x;i<=n;i++)
	if(a[i]*x-s[i]+s[i-x]<=m) return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]+=1e12;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	l=0;r=n;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",r);
	return 0;
}