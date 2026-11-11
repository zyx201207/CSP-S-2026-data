#include<bits/stdc++.h>
using namespace std;
#define int long long 

inline int read()
{
	int x(0),f(1);
	char ch(getchar());
	while(!isdigit(ch))f=(ch=='-')?-1:1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}

const int N=5e5+5;
int n,m,a[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	int num=0,ans=1,now=0;
	for(int i=1;i<=n;i++)
	{
		now+=num*(a[i]-a[i-1]),num++;
		while(now>m)
			now-=(a[i]-a[i-num]),num--;
		ans=max(ans,num);
	}
	cout<<ans<<"\n";
	return 0;
}