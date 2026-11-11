#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010],ans=1,l,r,f;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=a[i]-a[i-1];
	l=1;r=2;f=0;
	while(r<=n)
	{
		f+=(r-l)*s[r];
		while(f>m && l<=r)
		{
			f-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
	}
	cout<<ans;
	return 0;
}//唐完了，看了半个多小时才看出来是双指针awa 
