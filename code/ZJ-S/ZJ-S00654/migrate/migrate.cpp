#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e6+5;

int c;
int T;
ll x[N], n=0, d=0, ans=0;
bool to[5000][5000];
		
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--)
	{
		n=0, d=0, ans=0;
		memset(to,0,sizeof(to));
		memset(x,0,sizeof(x));
		cin >> n >> d;
		for(int i=1;i<=n;i++)
		{
			cin >> x[i];
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i] <= d)
				{
					to[i][j] = 1;
					to[j][i] = 1;
				}
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=n;j>1;j--)
			{
				int num = 0;
				for(int k = i+1;k<j;k++)
				{
					if(to[i][k]&&to[j][k])
					{
						num++;
					}
					if(num == 2)
					{
						ans++;
					}
					if(num>2)
					{
						ans--;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
