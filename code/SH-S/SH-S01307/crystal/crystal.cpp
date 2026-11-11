/*#include<bits/stdc++.h>
using namespace std;

struct crystal
{
	long long k,cnt,now;
};

long long a[500005];
crystal dp[500005];

int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		
	}
	/*long long l = 0,r = 1e12+1;
	while(l <= r)
	{
		long long mid = (l - r) / 2 + r;
		if(check(mid))
		{
			
		}
	}
	//dp[i] 表示到第i个数为止最多有多少能量水晶合成大水晶 
	sort(a + 1,a + n + 1);
	dp[1].k = m;
	for(int i = 1;i <= n;i++)
	{
		dp[i].now = a[i];
		dp[i].cnt = 1;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j < i;j++)
		{
			if(dp[i].now == dp[j].now)
			{
				dp[i].cnt = max(dp[i].cnt,dp[j].cnt) + 1;
				dp[i].k = max(dp[i].k, dp[j].k);
				
			}
			else if(dp[i].now > dp[j].now)
			{
				if(dp[j].k >= abs(dp[j].cnt * (dp[i].now - dp[j].now)))
				{
					if(dp[i].cnt <= dp[j].cnt)
					{
						dp[i].cnt = dp[j].cnt +1;
						dp[i].k = dp[j].k - abs(dp[j].cnt * (dp[i].now - dp[j].now));
					}
				}
			}
			cout << dp[i].cnt << " " << dp[i].k << " " << dp[i].now << endl;
		}
		cout << endl;
	}
	long long maxx = -1e18;
	for(int i = 1;i <= n;i++)
	{
		maxx = max(maxx,dp[i].cnt);
	}
	cout << maxx;
	return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;

long long a[500005];
long long n,m;
//crystal dp[500005];

bool cmp(long long A,long long B)
{
	return A > B;	
} 

long long cnt(int x)
{
	int tmp = m;
	int sum = 0;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] > a[x])continue;
		else if(a[i] == a[x]) sum++; 
		else
		{
			if(tmp >= (a[x]-a[i]))
			{
				tmp -= a[x] - a[i];
				sum++;
			}
			else
			{
				break;
			}
		}
	}
	//cout <<a[x]<<" "<< sum << endl;
	return sum;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		
	}
	/*long long l = 0,r = 1e12+1;
	while(l <= r)
	{
		long long mid = (l - r) / 2 + r;
		if(check(mid))
		{
			
		}
	}*/
	//dp[i] 表示到第i个数为止最多有多少能量水晶合成大水晶 
	sort(a + 1,a + n + 1,cmp);
	long long maxx = -1e18;
	for(int i = 1;i <= n;i++)
	{
		//a[i]++;
		//a[i]--;
		maxx = max(maxx,cnt(i));
		//cout << endl;
	}
	cout << maxx;
	return 0;
}
























