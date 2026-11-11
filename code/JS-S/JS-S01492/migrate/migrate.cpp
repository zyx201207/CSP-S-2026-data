#include <bits/stdc++.h>
using namespace std;
long long read()
{
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
void write(long long x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
		return;
	}
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+48);
	return;
}
long long C,T,n,d,x[1000005];
// bool pd1()
// {
// 	for(int i = 2;i < n;i++)
// 	{
// 		if(x[i]!=x[i-1])return 0;
// 	}
// 	return 1;
// }
// void solve1()
// {
// 	if(d<x[1])
// 	{
// 		putchar('0');
// 		putchar('\n');
// 		return;
// 	}
// 	write(max(0LL,n-2*(d/x[1])+1));
// 	putchar('\n');
// }
vector<int> a[2000005];
int t;
int main()
{
	// freopen("1.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read();T=read();
	while(T--)
	{
		n=read();d=read();
		for(int i = 1;i <= n;i++)a[i].clear();
		t=1;
		for(int i = 1;i <= n;i++)
		{
			x[i]=read();
			if(i>1)
			{
				if(x[i]-x[i-1]>d)
				{
					t++;
				}
			}
			a[t].push_back(i);
		}
		// if(pd1())
		// {
		// 	solve1();
		// 	continue;
		// }
		if(n<=300)
		{
			long long ans=0;
			for(int i = 1;i <= t;i++)
			{
				for(int j = 0;j < a[i].size();j++)
				{
					for(int k = j+1;k < a[i].size();k++)
					{
						// cout<<"+++"<<j<<' '<<k<<a[i][j]<<' '<<a[i][k]<<' '<<endl;
						if(x[a[i][k]]-x[a[i][j]]<=d)continue;
						int c=(x[a[i][k]]-x[a[i][j]])/d;
						// cout<<"+++"<<c<<endl;
						if(c==1)
						{
							int cnt=0;
							for(int l = j+1;l < k;l++)
							{
								if(x[a[i][l]]-x[a[i][j]]<=d&&x[a[i][k]]-x[a[i][l]]<=d)
								{
									cnt++;
								}
							}
							// cout<<a[i][j]<<' '<<a[i][k]<<' '<<cnt<<endl;
							if(cnt==2)ans++;
						}
					}
				}
			}
			write(ans);
			putchar('\n');
		}
		else
		{
			putchar('0');
			putchar('\n');
		}
	}
	return 0;
}