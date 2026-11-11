#include<bits/stdc++.h>
using namespace std;
#define int long long
#define gc getchar_unlocked
#define pc putchar_unlocked
int x[2000006];
int f[505][505];
int dp[500005];
int cnt[505][505];
void read(int& x)
{
	x=0;
	bool flg=0;
	char ch=gc();
	while(ch<'0' ||  ch>'9') 
	{
		if(ch=='-') flg=1;
		ch=gc();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+ch-'0';
		ch=gc();
	}
	if(flg) x=-x;
}
void write(int x)
{
	if(x>=10) write(x/10);
	pc(x%10+'0');
}
bool vis[3006];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	read(c);read(t);
	dp[0]=1;
	for(int i=1;i<=1e3;i++)
	{
		for(int j=0;j<i;j++)
		{
			dp[i]+=dp[j];
		}
	}
	while(t--)
	{
		int n,d,ans=0;
		read(n);read(d);
		//cout<<"n="<<n<<" d="<<d<<"\n";
		bool c1=0,c2=0;
		for(int i=1;i<=n;i++) read(x[i]);
		//cout<<" a test finish.";OK
		if(n<=5000) c1=1;
		if(c1)
		{
			for(int i=1;i<=n;i++)
			{
				vis[i]=0;
				for(int j=1;j<i;j++)
				{
					f[i][j]=f[j][i]=(x[i]-x[j]+d-1)/d;
					cnt[i][j]=cnt[j][i]=1;
				}
				f[i][i]=cnt[i][i]=0;
			}
			for(int k=1;k<=n;k++)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=i+1;j<=n;j++)
					{
						if(i==j || i==k || j==k) continue;
						int nw=f[i][k]+f[k][j];
						if(nw<f[i][j]) f[i][j]=f[j][i]=nw,cnt[i][j]=cnt[j][i]=cnt[i][k]*cnt[k][j];
						else if(nw==f[i][j]) cnt[i][j]++,cnt[j][i]++;
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(cnt[i][j]-f[i][j]==1 && !vis[j]) ans++;
					cout<<cnt[i][j]<<"("<<f[i][j]<<") ";
				}
				cout<<"\n";
			}
			
			write(ans);pc('\n');
		}
	}
	return 0;
}
