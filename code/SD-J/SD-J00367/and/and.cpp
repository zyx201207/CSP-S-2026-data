#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const lint M1=1e6+1000,M2=1e3+100;
lint n,m;
lint a[M1];
bool f[M1];
lint sum=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(lint i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(lint i=32;i>=0;i--)
	{
		lint opi=(1ll<<i),s=0;
		for(lint j=1;j<=n;j++)
		{
			if((a[j]&opi)&&!f[j]) s++;
		}
		if(s>=m)
		{
			for(lint j=1;j<=n;j++)
			{
				if(!(a[j]&opi)) f[j]=1;
			}
			sum+=opi;
		}
	}
	printf("%lld\n",sum);
	return 0;
}
