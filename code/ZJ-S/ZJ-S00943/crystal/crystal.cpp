#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=500005;
int n;LL a[N],m;
LL read()
{
	LL ret=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
	while(isdigit(c))ret=(ret<<3)+(ret<<1)+(c&15),c=getchar();
	return ret*f;
}
bool P(LL H)
{
	LL sum=0;
	for(int i=1;i<=H;i++)sum+=a[H]-a[i];
	LL res=sum;
	for(int i=H+1;i<=n;i++)
	{
		sum=sum-(a[i-1]-a[i-H])+(a[i]-a[i-1])*(H-1),res=min(res,sum);
	}
	return res<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int L=1,R=n,mid;
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++)printf("%lld\n",a[i]);
	while(L<=R)
		if(P(mid=L+R>>1))L=mid+1;else R=mid-1;
	printf("%d\n",R);
}
