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
	const int N = 2e6+7;
	int n,a[N],l[N],r[N],f[N][3],g[N][3],d;
	vector<int> q[N];
	void Main()
	{
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		int c = read(),t = read();
		while(t--)
		{
			n = read();d = read();
			for(int i=1;i<=n;i++) a[i] = read(),g[i][1] = g[i][2] = f[i][1] = f[i][2] = 0;
			for(int i=1;i<=n;i++) q[i].clear();
			int L = 1,R = 0;
			for(int i=1;i<=n;i++)
			{
				while(a[i] - a[L] > d && L < i) L++;
				while(a[R+1] - a[i] <= d && R < n) R++;
				l[i] = L,r[i] = R;
				q[R].push_back(i);
			}
			for(int i=1;i<=n;i++)
			{
				if(q[i].size() > 0) g[i][1] += g[q[i][0]][1] + q[i].size();
				f[i][1] += i + 1 - l[i];
				if(l[i] == i) continue;
				else if(l[i] == i-1) f[i][1] += f[i-1][1]-1,f[i][2] += f[i-1][2];
				else if(l[i] == 1) continue;
				else if(r[l[i]-1] == l[i]) f[i][2] += f[l[i]][2],f[i][1] += f[l[i]][1]-1;
				else 
				{
					f[i][1] += g[l[i]][1];
					f[i][2] += g[l[i]+1][1];
				}
			}
			//for(int i=1;i<=n;i++) printf("%lld ",g[i]);putchar('\n');
			int ans = 0;
			for(int i=1;i<=n;i++) ans += f[i][2];
			out(ans);
		}
		return ;
	}
}
