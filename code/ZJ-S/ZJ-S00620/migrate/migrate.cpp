#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n;
long long d,a[N];
int dp[N],st[N],h = 0,t = 1;
int st2[N],h2 = 0,t2 = 1;
long long cnt[N],cnt2[N];
void solve()
{
	cin >> n >> d;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		h = 0;
		h2 = 0;
		t = 1;
		t2 = 1;
		st[++ h] = i;
		st2[++ h2] = i; 
		dp[i] = 0;
		cnt[i] = 1;
		cnt2[i] = 1;
		for(int j = i + 1;j <= n;j ++)
		{
			while(h >= t && a[j] - a[st[t]] > d)
			{
				cnt2[st2[t2]] -= cnt[st[t]];
				t ++;
				if(cnt2[st2[t2]] == 0) t2 ++;
			}
			if(h2 < t2)
			{
				break;
			}
			dp[j] = dp[st2[t2]] + 1;
			cnt[j] = cnt2[st2[t2]];
			cnt2[j] = cnt[j];
			if(cnt[j] == 2) ans ++;
			while(h >= t && dp[j] < dp[st[h]])
			{
				h --;
			}
			while(h2 >= t2 && dp[j] < dp[st2[h2]])
			{
				h2 --;
			}
			st[++ h] = j;
			if(h2 >= t2 && dp[st2[h2]] == dp[j])
			{
				cnt2[st2[h2]] += cnt[j];
			}
			else
			{
				st2[++ h2] = j;
			}
		}
	}
	cout << ans << '\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin >> c >> T;
	while(T --)
	{
		solve();
	}
	return 0;
}
