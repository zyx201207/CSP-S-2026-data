#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 3;
int a[N],b[N];
char s[N];
int read()
{
	int x = 0,fs = 1;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-')
		{
			fs = -1;
		}
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x * fs;
}

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	n = read();
	for(int i = 1;i <= n;i++)
	{
		a[i] = read() ;
		b[i] = b[i - 1] + a[i];
		s[i] = getchar();
	}
	//cout << b[n] << "\n\n";
	long long ans = 0;
	for(int i = 1;i <= n;i++)
	{
		
		if((b[i]) <= (b[n] / 2))
		{
			int dq1 = b[i] - a[i];
			int dq2 = b[i];
			dq1 = b[n] - dq1;
			dq2 = b[n] - dq2 + 1;
			
			int x = lower_bound(b + 1,b + n + 1,dq1) - b;
			int y = lower_bound(b + 1,b + n + 1,dq2) - b;
			//cout << dq1 << " " << dq2 << " " << x << " " << y << "\n";
			int l = dq1 - dq2 + 1;
			for(int j = x;j >= y;j--)
			{
				if(l <= 0)
				{
					break;
				}
				if(s[i] != s[j])
				{
					//cout << "aaa" << "\n";
					if(l <= a[j])
					{
						//cout << "bbb" << "\n"; 
						ans += l;
						a[j] -= l;
						l = 0;
					}
					else
					{
						//cout << "ccc" << "\n"; 
						ans += a[j];
						l -= a[j];
						a[j] = 0;
					}
				}
				else
				{
					//cout << "ddd" << "\n"; 
					int p = a[j];
					a[j] = a[j] - l;
					l -= p;
				}
				
			}
		}
		/*else if((b[i - 1] + 1) <= (b[n] / 2))
		{
			int p = (b[n] / 2) - b[i - 1];
			int o = 1;
			for(int k = 1;k <= p;k++)
			{
				int h = p + k;
				int x = lower_bound(b + 1,b + n + 1,h) - b;
				if(s[i] != s[i + o])
				{
					if(a[i + o] > 0)
					{
						a[i + 1]--;
						ans++;
					}
					else
					{
						o++;
						if(s[i] != s[i + o])
						{
							ans++;
							a[i + o]--;
						}
						else
						{
							a[i + o]--;
						}
					}
				}
				else
				{
					a[i + o]--;
				}
			}
		}*/
	}
	cout << ans;
	return 0;
} 

