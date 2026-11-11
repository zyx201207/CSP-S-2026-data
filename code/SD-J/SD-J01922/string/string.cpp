#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=400005;
int n,A[N],rA[N],tot;
int sA[N],srA[N],tmp[N];
char C[N],rC[N];
char get1(int x)
{
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(sA[mid]<x)
			l=mid+1,ans=mid;
		else r=mid-1;
	}
	return C[ans+1];
}
char get2(int x)
{
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(srA[mid]<x)
			l=mid+1,ans=mid;
		else r=mid-1;
	}
	return rC[ans+1];
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		int a;char ch[2];
		scanf("%lld%s",&a,ch);
		A[i]=a,C[i]=ch[0];
	}
	for(int i=1;i<=n;i++)
		rA[n-i+1]=A[i],
		rC[n-i+1]=C[i];
	for(int i=1;i<=n;i++)
	{
		sA[i]=sA[i-1]+A[i],
		srA[i]=srA[i-1]+rA[i];
		tmp[++tot]=sA[i],
		tmp[++tot]=srA[i];
	}
	sort(tmp+1,tmp+1+tot);
	int ans=0;
	for(int i=1;i<=tot;i++)
	{
		char c1=get1(tmp[i]),c2=get2(tmp[i]);
		//printf("%d %c %c\n",tmp[i],c1,c2);
		if(c1!=c2) ans+=tmp[i]-tmp[i-1];
	}
	printf("%lld\n",ans/2);
	return 0;
}
/*
6
100 a
100 a
100 a
100 b
100 b
100 b
*/
