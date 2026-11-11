#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
#include <queue>
typedef unsigned long long ull;
typedef long long ll;
const ull N=500010;
ull n,ans;
ll a[N],m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%llu%lld",&n,&m);
	for(ull i(1);i<=n;++i) scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	ll sm=0;
	ans=0;
	for(ull i(1),j(1);i<=n;++i)
	{
		sm+=(a[i]-a[i-1])*(i-j);
		while(sm>m) sm-=a[i]-a[j],++j;
		ans=std::max(ans,i-j+1);
	}
	printf("%llu",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
ans in {a_i}


*/
