#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=5e5+10;
ll n,m,a[maxn],sum[maxn],ans;
bool check(int x)
{
	bool flag=false;
	for(int i=1,j=x;j<=n;i++,j++)
	{
		if(a[j]*x-(sum[j]-sum[i-1])<=m)
			flag=true;
	}
	return flag;
}
void binary_search()
{
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int left=1,right=n,middle;
	while(left<=right)
	{
		middle=left+(right-left)/2;
		if(check(middle))
		{
			ans=middle;
			left=middle+1;
		}
		else
		{
			right=middle-1;
		}
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	binary_search();
	printf("%lld",ans);
	return 0;
}
