#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int& x)
{
	char c;x=0;
	int f=0;
	c=getchar();
	if(c=='-') f=1;
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9') x=x*10+c-'0',c=getchar();
	x*=(f==0?1:-1);
}
int t;
signed main()
{
	freopen("hug.in","r",stdin);
	freopen("hug.out","w",stdout);
	read(t);
	srand(time(0));
	while(t--)
		cout<<rand()%(int)(1e9+7)<<"\n";
	return 0;
}