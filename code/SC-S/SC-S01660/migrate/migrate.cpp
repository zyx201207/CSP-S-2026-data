#include<bits/stdc++.h>
using namespace std;
long long n,d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t; cin>>c>>t;
    long long ggg;
		for(int ppp=1;ppp<=t;ppp++)
		{
			scanf("%lld%lld",&n,&d);
			long long a,b;
			scanf("%lld%lld",&a,&b);
			long long cha=a-b;
			if(cha<0) cha*=-1;
			for(int i=3;i<=n;i++)
			{
				scanf("%lld",&ggg);
			}
			long long kua=d/cha;
			if(kua<2) printf("0\n");
			else
			{
				long long www=n-d/cha-d/cha+1;
			    if(www>0)cout<<www<<'\n';
			    else printf("0\n");
			}
		}
	return 0;
 } 