#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
	int val=0,k=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') k=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		val=val*10+(ch-'0');
		ch=getchar();
	}
	return val*k;
}

inline void write(int val)
{
	if(val<0) putchar('-'),val=-val;
	if(val>9) write(val/10);
	putchar(val%10+'0');
}

const int maxN=5e5+5;
int n,m,a[maxN],pre[maxN],ans;

inline bool check(int mid,int r)
{
	return a[r]*(r-mid+1)-(pre[r]-pre[mid-1])<=m;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,res=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid,i)) res=i-mid+1,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,res);
	}
	write(ans);
	return 0;
}