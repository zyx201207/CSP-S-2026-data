#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int rd()
{
	int x=0;bool f=0;char c=getchar();
	for(;!isdigit(c);f=c=='-',c=getchar());
	for(;isdigit(c);x=(x<<3)+(x<<1)+(c^48),c=getchar());
	return f?-x:x;
}
int a[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=rd(),m=rd();
	for(int i=1;i<=n;i++)
		a[i]=rd();
	sort(a+1,a+n+1);
	int l=1,r=1,sum=0,ans=1;
	while(r<n)
	{
		r++,sum+=(a[r]-a[r-1])*(r-l);
		while(sum>m)sum-=(a[r]-a[l]),l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
