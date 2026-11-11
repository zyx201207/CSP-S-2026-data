#include<bits/stdc++.h>
#define LOCAL
#define LL long long
using namespace std;
const int N=5e5+10;
LL n,m;
LL a[N];
LL b[N];
LL rd()
{
	LL s=0,g=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')g=-1;c=getchar();}
	while(isdigit(c)){s=(s<<3)+(s<<1)+(c-'0');c=getchar();}
	return s*g;
}
void wt(LL x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>9){wt(x/10);}
	putchar(x%10+'0');
	return ;
}
LL sum(LL l,LL r)
{
	return b[r]-b[l]-(l-1)*(a[r]-a[l]);
}
bool chck(LL x)
{
	for(int i=1,j=i+x-1;j<=n;i++,j++)
	{
		if(sum(i,j)<=m)return true;
	}
	return false;
}
int main()
{
	#ifdef LOCAL
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
	#endif
	n=rd();m=rd();
	for(int i=1;i<=n;i++)
	{
		a[i]=rd();
	}
	sort(a+1,a+n+1);
	b[1]=0;
	for(int i=2;i<=n;i++)
	{
		b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	LL l=1,r=n;
	while(l<r)
	{
		LL mid=(l+r+1)>>1;
		if(chck(mid))l=mid;
		else r=mid-1;
	}
	wt(l),puts("");
	#ifdef LOCAL
		fclose(stdin);
		fclose(stdout);
	#endif
	return 0;
}
