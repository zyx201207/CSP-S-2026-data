#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll a,b,c,d;
	char x,y;
	scanf("%2lld %2lld%c %2lld %2lld%c",&a,&b,&x,&c,&d,&y);
//	printf("%lld %lld %c %lld %lld %c\n",a,b,x,c,d,y);
	if (a == c) printf("1");
	else printf("0");
	if (a == c && b == d) printf("1");
	else printf("0");
	if (a == c && b == d && (x <= 'C' && y <= 'C' || x >= 'D' && y >= 'D')) printf("1");
	else printf("0");
	if (a == c && b == d && (x <= 'C' && y <= 'C' || x >= 'D' && y >= 'D') && (x + 1 == y || y + 1 == x)) printf("1\n");
	else printf("0\n");
	return 0;
}
