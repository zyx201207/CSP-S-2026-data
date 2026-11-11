#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2e5+10;
long long n,m,a[maxn],ans;
void dfs(int x,int y,long long z)
{
	if(y==m)
	{
		ans=max(ans,z);
		return;
	}
	if(n-x>=m-y)dfs(x+1,y,z);
	dfs(x+1,y+1,z&a[x]);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	dfs(1,0,0xffffffffll);
	printf("%lld",ans);
	return 0;
}
