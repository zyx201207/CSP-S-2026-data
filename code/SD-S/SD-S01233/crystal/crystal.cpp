#include<bits/stdc++.h>
using namespace std;
const int mx=5e5;
long long a[mx+10],s[mx+10];
inline long long qry(int lt,int rg)
	{return (rg-lt+1)*a[rg]-(s[rg]-s[lt-1]);}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i,n,lt,rg,md,ans=0;
	long long m;
	scanf("%d%lld",&n,&m);
	for(i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	for(i=1;i<=n;++i)
	{
		lt=1;rg=i;
		while(lt<=rg)
		{
			md=(lt+rg)>>1;
			if(qry(md,i)<=m) rg=md-1;
			else lt=md+1;
		}
		ans=max(ans,i-lt+1);
	}
	printf("%d\n",ans);
	return 0;
}
