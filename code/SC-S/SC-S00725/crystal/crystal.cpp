#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long pol[500005];
long long read()
{
	long long f=1,num=0;
	char ch=getchar();
	while((ch>='0'&&ch<='9')||ch=='-')
	{
		if(ch=='-')f=-1;
		else{
			num*=10;
			num+=(ch-'0');
		}
		ch=getchar();
	}
	return num*f;
}
bool ty(long long lg)
{
	long long ans=0;
	for(int i=1;i<=lg;i++)ans+=pol[lg]-pol[i];
	if(ans<=m)return 1;
	for(int i=2;i<=n-lg+1;i++)
	{
		ans=ans-pol[i+lg-2]+pol[i-1]+(lg-1)*(pol[i+lg-1]-pol[i+lg-2]);
		if(ans<=m)return 1;
	}
	return 0;
 } 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	scanf("%lld%lld",&n,&m);
//	for(int i=1;i<=n;i++)scanf("%lld",&pol[i]);
	n=read(),m=read();
	for(int i=1;i<=n;i++)pol[i]=read();
	sort(pol+1,pol+n+1);
	long long l=1,r=n+1;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(ty(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%lld",l-1);
	return 0;
}
