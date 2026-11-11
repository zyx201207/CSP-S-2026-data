#include<bits/stdc++.h>
#define int long long
#define N 500010
using namespace std;
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}return x*f;}
inline void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');}

int a[N],pre[N];
int n,m;
bool check(int l,int r)
{
	int len=(r-l+1);
	int cost=a[r]*len-(pre[r]-pre[l-1]);
	return cost<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid,i))
			{
				ans=max(ans,i-mid+1);
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	write(ans);
	return 0;
}

