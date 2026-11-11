#include<bits/stdc++.h>
using namespace std;
int n,d,x[2000007],ans,an;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T,c;
	scanf("%d%d",&c,&T);
	while(T--)
	{
		ans=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++) scanf("%d",&x[i]);
		int f=0;
		for(int i=n;i>=1;i--) x[i]-=x[i-1];
		if(c==11||c==12)
		{
			an=x[2]/d;
			an=an*2-1;
			while(an>1&&an<=n)
			{
				ans+=n-an+1;
				an+=x[2]/d;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}