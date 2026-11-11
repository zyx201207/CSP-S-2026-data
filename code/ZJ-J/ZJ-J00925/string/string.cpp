#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
int n,top1,top2;LL S[N],ans;
struct XYM
{
	LL x;
	char c;
}a[N],b[N],c[N],s1[51],s2[11];
int read()
{
	int ret=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
	while(isdigit(c))ret=(ret<<3)+(ret<<1)+(c&15),c=getchar();
	return ret*f;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i].x=read(),cin>>a[i].c,S[i]=S[i-1]+a[i].x;
	LL mid=S[n]+1>>1;int mi=0;
	for(int i=1;i<=n;i++)if(S[i]>=mid){mi=i;break;}
	LL Lr=mid,Rr=S[n]-mid;
	if(Lr>Rr)Lr--;else if(Lr<Rr)Rr--;
	LL cnta=0,cntb=1;
	for(int i=1;i<mi;i++)b[i]=a[i],cnta++;b[++cnta]=(XYM){(Lr-S[mi-1]),a[mi].c};
	c[1]=(XYM){(Rr-S[n]+S[mi]),a[mi].c};for(int i=mi+1;i<=n;i++)c[++cntb]=a[i];
	reverse(c+1,c+1+cntb);
//	for(int i=1;i<=cnta;i++)cerr<<b[i].x<<' '<<b[i].c<<'\n';
//	for(int i=1;i<=cntb;i++)cerr<<c[i].x<<' '<<c[i].c<<'\n';
	for(int i=1,j=1;i<=cnta||j<=cntb;)
	{
		if(!top1)s1[++top1]=b[i],i++;
		if(!top2)s2[++top2]=c[j],j++;
		if(s1[top1].x>s2[top2].x)
			s1[top1].x-=s2[top2].x,ans+=(s1[top1].c!=s2[top2].c)*s2[top2].x,top2--,top1-=!s1[top1].x;
		else 
			s2[top2].x-=s1[top1].x,ans+=(s1[top1].c!=s2[top2].c)*s1[top1].x,top1--,top2-=!s2[top2].x;
	}
	printf("%lld\n",ans);
}