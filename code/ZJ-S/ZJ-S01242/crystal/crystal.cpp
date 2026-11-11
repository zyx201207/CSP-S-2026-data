#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)) {sum=(sum<<1)+(sum<<3)+c-48;c=getchar();}
	return sum*f;
}
int a[N],p[N],n,m,ans;
int binary(int x)
{
	int l=1,r=x-1,mid=1,s=0,ret=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		s=(x-mid)*a[x]-(p[mid]-p[x]);
		if(s<=m) ret=mid,r=mid-1;
		else l=mid+1;
	}
	return ret;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		p[i]=p[i+1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,i-binary(i)+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 5
1 4 6 7 7

5 8
-3 -1 2 2 7
*/