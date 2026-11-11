#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int rd()
{
	int x=0;char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);x=(x<<3)+(x<<1)+(c^48),c=getchar());
	return x;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	return 0;
}
