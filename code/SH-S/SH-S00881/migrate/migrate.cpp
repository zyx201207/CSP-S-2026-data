#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int c,t,sum,last,cnt;
const int N = 2000005;
long long x[N];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	while(t--)
	{
		sum = 0;
		int n,d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		for(int i = 1;i <= n-d;i++)
		{
			last = 0;
			cnt = 0;
			for(int j = i + d + 1;j <= n;j++)
			{
				last = (x[j] - x[1]) % d;
				cnt = x[n] - x[1] - last;
				if(cnt % d == 0)
				{
					sum += 1;
				}
			}
		}
		cout << sum << endl;
	} 
	
	
	return 0;
}
