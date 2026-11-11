#include<bits/stdc++.h>
#define int long long
using namespace std;
vector <int> x;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
		int n,d,p;
		scanf("%lld%lld",&n,&d);
		x.push_back(0);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&p);
			x.push_back(p);
		}
		if(c==11||c==12)
		{
			int de=x[2]-x[1];
			d=d-(d%de);
			if(d==de||d==0)printf("0\n");
			else
			{
				int u=d/de*2-1;
				printf("%lld\n",(n-u>0?n-u:0));
			}
			x.clear();
		}
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				int j;
				for(j=i+1;j<n;j++)
				{
					if(x[j]-x[i]<=d)continue;
					else {j--;break;}
				}
				int k=j;
				for(k=j+1;k<=n;k++)
				{
					if(x[k]-x[j]<=d)continue;
					else {k--;break;}
				}
				int o;
				for(k;k>=i+2;k--)
				{
					for(o=k;o>=i;o--)
					{
						if(x[k]-x[j-(k-o+1)]<=d&&x[k]-x[j-(k-o+2)]>d)continue;
						else break;
					}
				ans+=k-o;
				}
				
			}
			printf("%lld\n",ans);
			x.clear();
		}
    }
    return 0;
}
