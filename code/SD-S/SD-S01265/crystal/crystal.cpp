#include<bits/stdc++.h>
using namespace std;
long long rd()
{
	bool bz=false;
	char ch=getchar();
	long long ans=0;
	while(ch!=EOF&&ch!='-'&&(ch<'0'||ch>'9'))
		ch=getchar();
	if(ch=='-')
	{
		bz=true;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		ans=(ans<<3)+(ans<<1)+(ch^48);
		ch=getchar();
	}
	if(bz)
		return -ans;
	return ans;
}
void wrt(long long x)
{
	int numn[40],cnt=0,i;
	long long y=x;
	if(y<0)
	{
		putchar('-');
		y=-y;
	}
	do
	{
		numn[++cnt]=y%10;
		y/=10;
	}while(y);
	for(i=cnt;i>=1;--i)
		putchar(numn[i]^48);
	return;
}
const int maxn=5e5;
int ans,lt=1,n;
long long a[maxn+10],f[maxn+10];
long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i;
	n=rd();
	m=rd();
	for(i=1;i<=n;++i)
		a[i]=rd();
	sort(a+1,a+n+1);
	for(i=1;i<=n;++i)
		f[i]=f[i-1]+a[i];
	for(i=1;i<=n;++i)
	{
		while(lt<=i-1&&a[i]*(i-lt+1)-f[i]+f[lt-1]>m)
			++lt;
		ans=max(ans,i-lt+1);
	}
	wrt(ans);
	putchar('\n');
	return 0;
}
