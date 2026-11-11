#include<bits/stdc++.h> 
using namespace std;
#define LL long long
const int N=2e5+10;
struct node{
	int sm;
	char zm;
}a[N],qhc,hhc;
int n,s,qzz,hzz;
char z;
LL ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>s>>z;
	a[i]={s,z};
	}
	qzz=1;hzz=n;
	while(qzz<=hzz&&qzz<=n&&hzz>=1)
	{
		if(qhc.sm==0)
		{
			if(hhc.sm==0)
			{
				if(a[qzz].sm>a[hzz].sm)
				{
					qhc={a[qzz].sm-a[hzz].sm,a[qzz].zm};
					if(a[qzz].zm!=a[hzz].zm)
					{
						ans+=(LL)a[hzz].sm;
					}
				}
				else
				{
					hhc={a[hzz].sm-a[qzz].sm,a[hzz].zm};
					if(a[qzz].zm!=a[hzz].zm)
					{
						ans+=(LL)a[qzz].sm;
					}
				}
			}
			else
			{
				if(a[qzz].sm>=hhc.sm)
				{
					qhc={a[qzz].sm-hhc.sm,a[qzz].zm};
					if(a[qzz].zm!=hhc.zm)
					{
						ans+=(LL)hhc.sm;
					}
					hhc.sm=0;
				}
				else
				{
					hhc={hhc.sm-a[qzz].sm,hhc.zm};
					if(a[qzz].zm!=hhc.zm)
					{
						ans+=(LL)a[qzz].sm;
					}
					qhc.sm=0;
				}
			}
		}
		else
		{
			if(qhc.sm>=a[hzz].sm)
			{
				qhc={qhc.sm-a[hzz].sm,qhc.zm};
				if(qhc.zm!=a[hzz].zm)
				{
	    			ans+=(LL)a[hzz].sm;
				}
				hhc.sm=0;
			}
			else
			{
				hhc={a[hzz].sm-qhc.sm,a[hzz].zm};
				if(qhc.zm!=a[hzz].zm)
				{
					ans+=(LL)qhc.sm;
				}
				qhc.sm=0;
			}
		}
		if(qhc.sm==0)qzz++;
		if(hhc.sm==0)hzz--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
