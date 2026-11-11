#include <cstdio>
#include <algorithm>
using namespace std;
const int N=500100;
long long a[N],pre[N];
int max(int a,int b)
{
	return (a > b) ? a : b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	for(int j=1,i=1;j<=n;j++)
	{
		while(m<a[j]*(j-i+1)-(pre[j]-pre[i-1])) i++;
		ans=max(ans,j-i+1);
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
