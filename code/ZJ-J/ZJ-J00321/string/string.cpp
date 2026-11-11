#include<cstdio>
int n,i,a[200005];
char c[200005];
int l,r,l_more,r_more;
long long ans=0;
//RP++
//Let me AK CSP-J pls CCF!!!
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d %c",a+i,c+i);
	l=0;r=n+1;
	while(l<r-(n%2==0))
	{// when l=r break
		if(l_more==0)l++,l_more=a[l];
		if(r_more==0)r--,r_more=a[r];
		if(c[l]==c[r])
		{// cl=cr,so neednt opt
			if(l_more>r_more)
			{
				l_more-=r_more;
				r_more=0;
			}
			else
			{
				r_more-=l_more;
				l_more=0;
			}
		}
		else
		{//need opt
			if(l_more>r_more)
			{
				ans+=r_more;
				l_more-=r_more;
				r_more=0;
			}
			else
			{
				ans+=l_more;
				r_more-=l_more;
				l_more=0;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
//freopen
//freopen
我要上人类迷惑行为大赏!
我们知道，在科学中，电阻通常表示为R
而且，滑动变阻器通常表示为p
所以，滑动变阻器电阻为Rp
而且，在进入考场前，我们为保证电路不会过大，
应当将Rp拉到最大，或者用RP=inf的理想电压表代替
综上所述，2026CSP-J RP++ 
*/ 
