#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll a[N],m;
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
	int lst=n,ans=0;
	for(int i=n;i>0;i--)
	{
		lst=min(i,lst);
		if(i!=n) m+=(a[i+1]-a[i])*(i-lst+1);
		while(lst!=1&&a[i]-a[lst]<=m)
		{
			lst--;
			m-=a[i]-a[lst];
		}
		ans=max(ans,i-lst+1);
	}
	printf("%d",ans);
	return 0;
}
//gaoxiaoyizi meishuipingdequ
//wozhendebuxiangdangqu!!!!!
