#include<bits/stdc++.h>
#define u unsigned
#define ll long long
#define ull u ll
using namespace std;
u c,t,n,m;
u Log(u x)
{
	for(u i=20;i;i--)
	{
		if(x&(1<<(i-1))){return i-1;}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%u%u",&c,&t);
	while(t--)
	{
		scanf("%u%u",&n,&m);
		printf("%u\n",Log(m-1)+1);
		while(n--){scanf("%*u%*u");}
	}
	return 0;
}
