#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define REP(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
typedef long long ll;
inline ll read()
{
	ll x=0; char ch;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-'0', ch=getchar();
	return x;
}

ll cas,t,n,k;

signed main()
{
	cas=read(),t=read();
	while(t--)
	{
		n=read(),k=read();
		FOR(i,1,n-1)
		{
			ll u=read(),v=read();
		}
		if(k==2) printf("1\n");
		else if(k==1) printf("0\n");
		else printf("2\n");
	}
	return 0;
}

