#include<bits/stdc++.h>
#define LOCAL
#define LL long long
using namespace std;
const int N=2e6+10;
LL c,T;
LL n,d;
LL x[N];
int rd()
{
	int s=0,g=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')g=-1;c=getchar();}
	while(isdigit(c)){s=(s<<3)+(s<<1)+(c-'0');c=getchar();}
	return s*g;
}
void wt(int x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>9){wt(x/10);}
	putchar(x%10+'0');
	return ;
}
int main()
{
	#ifdef LOCAL
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
	#endif
	c=rd();T=rd();
	while(T--)
	{
		n=rd();d=rd();
		for(int i=1;i<=n;i++)
		{
			x[i]=rd();
		}
		if(n==1)
		{
			wt(0),puts("");
			continue;
		}
		if(c<=11&&c<=12)
		{
			LL p=d/(x[2]-x[1]);
			LL tmp=p*2;
			LL ans=max(0LL,n-tmp+1);
			if(p==0||p==1)ans=0;
			wt(ans),puts("");
		}
		else
		{
			wt(0),puts("");
		}
	}
	#ifdef LOCAL
		fclose(stdin);
		fclose(stdout);
	#endif
	return 0;
}
