#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FRE freopen("string.in","r",stdin),freopen("string.out","w",stdout);
//9:28
int read()
{
	int f=1;
	int k=0,c=getchar();
	for(;!isdigit(c);c=getchar())
		if(c=='-')
			f=-1;
	for(;isdigit(c);c=getchar())
		k=k*10+(c-'0');
	return k*f;
}
const int N=2e5+5;
LL n;
LL a[N];
char c[N];
LL ans=0;
LL ri,li,rs,ls;
int main()
{
	FRE
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read(),c[i]=getchar();
	li=1,ri=n;
	rs=0;ls=0;
	while(li<ri)
	{
		int le=a[li]-ls,re=a[ri]-rs;
		if(c[li]==c[ri])
		{
			if(le>re)
			{
				ls+=re;
				ri--;
				rs=0;
			}
			else
			if(le==re)
			{
				li++;
				ri--;
				ls=rs=0;
			}
			else
			if(le<re)
			{
				rs+=le;
				li++;
				ls=0;
			}
		}
		else
		{
			if(le>re)
			{
				ans+=re;
				ls+=re;
				ri--;
				rs=0;
			}
			else
			if(le==re)
			{
				ans+=re;
				li++;
				ri--;
				ls=rs=0;
			}
			else
			if(le<re)
			{
				ans+=le;
				rs+=le;
				li++;
				ls=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
