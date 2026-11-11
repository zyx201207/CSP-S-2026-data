#include<bits/stdc++.h>
#define int long long
#define N 50010
using namespace std;
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}return x*f;}
inline void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');}

void solve()
{
	int n=read(),d=read();
	int a[N];
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	int ans=0;
	for(int r=1;r<=n;r++)
	{
		int dp[N],len[N];
		for(int i=r+1;i<=n;i++)
		{
			len[i]=INT_MAX;
			for(int j=r;j<i;j++)
			{
				if(abs(a[i]-a[j])<=d)len[i]=min(len[i],len[j]+1);
			}
			if(len[i]==INT_MAX)len[i]=0;
		}
		dp[r]=1;
//		for(int i=r;i<=n;i++)cout<<len[i]<<' ';
//		cout<<endl;
		for(int i=r+1;i<=n;i++)
		{
			dp[i]=0;
			for(int j=r;j<i;j++)
			{
				if(abs(a[i]-a[j])<=d)
				{
					if(len[j]+1==len[i])dp[i]+=dp[j];
				}
			}
		}
		for(int i=r;i<=n;i++)ans+=dp[i]==2;
//		for(int i=r;i<=n;i++)cout<<dp[i]<<' ';
//		cout<<endl;
	}
	write(ans);
	cout<<endl;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--)solve();
	return 0;
}

