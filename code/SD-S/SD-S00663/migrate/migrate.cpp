#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int,int> PII;

const int N = 2e6 + 5;

int c, t, n;
ll d, x[N], ans;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		ans = 0;
		for(int i = 1; i <= n; i++)
		{
			
			for(int j = i + 3; j <= n; j++)
			{
				if(x[j] - x[i] <= d) continue;
				ll cnt = 0;
				
				ll l = 1, w = i;
				for(int k = i + 1; k <= j; k++)
				{
					if(x[k] - x[w] <= d) continue;
					l++;
					w = k - 1;
				}
				ll minn = l;
				for(int p = i + 1; p <= j; p++)
				{
					w = i, l = 0;
					for(int k = i + 1; k <= j; k++)
					{
						if(x[k] - x[w] <= d) w = k, l++;
						if(l == minn - 1)
						{
							if(x[j] - x[w] <= d)
							{
								cnt++;
							}
							break;
						}
					}
					
				}
				
				if(--cnt == 2) ans++;
			}
			
		}
		cout << ans << '\n';
	}
	
	return 0;
}
