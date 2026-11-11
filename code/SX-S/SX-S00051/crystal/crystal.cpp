#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,l,r,ans;
long long a[maxn],m,cnt;
void solve()
{
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%lld",a+i);
	sort(a,a+n);
	for(l=0,r=1,cnt=a[0],ans=0;r<=n;cnt+=a[r++])
	{
		while(a[r-1]*(r-l)>cnt+m)
			cnt-=a[l++];
		ans=max(ans,r-l);
	}
	printf("%d",ans);
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int TT = 1;
	//scanf("%d",&TT);
	while (TT--)
		solve();
	return 0;
}
