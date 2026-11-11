#include<bits/stdc++.h>
using namespace std;
long long int a,b,c,d,e,f,h,i;
char j,k;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	scanf("%lld%lld%c",&c,&d,&j);
	scanf("%lld%lld",&e,&f);
	scanf("%lld%lld%c",&h,&i,&k);
	if(a==e&&b==f&&a!=0&&b!=1||e!=1&&f!=6)
	printf("1");
	else
	printf("0");
	if(c==h&&d==i)
	printf("1");
	else
	printf("0");
	if(c==h&&j=='F'&&k=='D'||j!='F'&&k!='D')
	printf("1");
	else
	printf("0");
	if(j-'1'==k||j+'1'==k&&a==e&&b==f&&a!=0&&b!=1||e!=1&&f!=6&&c==h&&d==i&&c==h&&j=='F'&&k=='D'||j!='F'&&k!='D')
	printf("1");
	else
	printf("0");
	return 0;
}