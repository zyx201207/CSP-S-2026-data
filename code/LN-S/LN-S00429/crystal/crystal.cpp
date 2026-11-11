#include <bits/stdc++.h>
using namespace std;
namespace WFH{void Main();}
signed main(){return WFH::Main(),0;}
namespace WFH
{
	#define int long long 
	inline void write(int x)
	{
		if(x < 0) putchar('-');
		if(x > 9) write(x/10);
		putchar(x%10+'0');
		return;
	}
	inline int read()
	{
		int x = 0,f = 1;
		char ch = getchar();
		while(ch > '9' || ch < '0') {if(ch=='-')f=-f;ch=getchar();}
		while(ch >='0' && ch <='9') x=x*10+ch-'0',ch=getchar();
		return x * f;
	}
	inline void out(int x){write(x);putchar('\n');return ;}
	const int N = 5e5+7;
	int n,m,a[N],sum[N],ans = 0;
	void Main()
	{
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		n = read();m = read();
		for(int i=1;i<=n;i++) a[i] = read();
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];
		int l = 1;
		a[n + 1] = (int)1e18;
		for(int i=1;i<=n;i++)
		{
			int now = (i+1-l)*a[i]-sum[i]+sum[l-1];
			while(now > m && l < i) l++,now -= a[i] - a[l];
			if(now <= m) ans = max(ans,i+1-l);
		}
		out(ans);
		return ;
	}
}
