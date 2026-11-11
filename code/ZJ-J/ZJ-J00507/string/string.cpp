#include<cstdio>
#define ll long long
using namespace std;
const int maxn=2e5+10;
ll n,m,a[maxn],xx,ans,suma;
char c[maxn];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,j=1;i<=n;i++)
	{
		scanf("%lld %c",&xx,&c[j]);
		if(c[j]==c[j-1])
		{
			a[j-1]+=xx;
		}
		else
		{
			a[j]=xx;
			j++;
		}
		suma+=xx;
		m=j-1;
	}
	for(int i=1,j=1,x=m,y=a[m],p=1;p*2<=suma;p++)
	{
		if(c[i]!=c[x])ans++;
		if(j==a[i])
		{
			i++;
			j=1;
		}
		else j++;
		if(y==1)
		{
			x--;
			y=a[x];
		}
		else y--;
	}
	printf("%lld",ans);
	return 0;
}
