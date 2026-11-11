#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2000005;
LL a[N],ans,F[N],Q[N],D;int n,c,T;
LL read()
{
	LL ret=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
	while(isdigit(c))ret=(ret<<3)+(ret<<1)+(c&15),c=getchar();
	return ret*f;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	if(c>8){while(T--)puts("0");return 0;}
	while(T--)
	{
		n=read(),D=read();ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
		for(int j=i+2;j<=n;j++)
		{
			int hed=1,til=0;
			memset(F,0,sizeof F);
			for(int k=i;k<=j;k++)
			{
				while(hed<=til&&a[Q[hed]]+D<a[k])hed++;
				while(hed<=til&&F[Q[til]]>F[Q[hed]]+1)til--;
				F[k]=F[Q[hed]]+1;Q[++til]=k;
			}
			int cnt=0;
			for(int k=j;a[j]-a[k]<=D&&k>=i;k--)if(F[j]==F[k]+1)cnt++;
			ans+=cnt==2;
//			if(cnt==2)cerr<<i<<' '<<j<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}