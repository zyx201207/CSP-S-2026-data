#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500010;
ll n,m,a[N],diff[N],ht[N],ans=1,l,r,sum=0;
bool flag=0,get_ans=0;
inline ll read()
{
	ll flag=1,tmp=0;
	char ch=getchar();
	while(ch<48||ch>57)
	{
		if(ch=='-')flag=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57)
	{
		tmp=tmp*10+ch-'0';
		ch=getchar();
	}
	return flag*tmp;
}
int main()
{
	//freopen("mangoT1","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		ht[i]=a[n]-a[i];
		diff[i]=a[i]-a[i-1];
	}
	l=1,r=2;
	while(r<=n)
	{
		sum+=(r-l)*diff[r];
		while(sum>m)
		{
			sum-=(ht[l]-ht[r]);
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
	}
	printf("%lld\n",ans);
	return 0;
}