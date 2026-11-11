#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,d;
char e,f;
int get_side(char s)
{
	if(s>='A' && s<='C')return 1;
	return 2;
}
int get_dis()
{
	if(e=='D' && f=='F')return 1;
	if(e=='F' && f=='D')return 1;
	return abs(e-f);
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld %lld%c %lld %lld%c",&a,&b,&e,&c,&d,&f);
	bool w=(a==c);
	bool x=w && (b==d);
	bool y=x && (get_side(e)==get_side(f));
	bool z=y && get_dis()==1;
	printf("%lld%lld%lld%lld",w,x,y,z);
	return 0;
}
