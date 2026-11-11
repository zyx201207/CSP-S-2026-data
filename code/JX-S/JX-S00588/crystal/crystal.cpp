#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 5;
ll n,m,a[N],sum[N],ans,cnt;

bool check(int x,int st)
{
	if(a[x + st - 1] * x - (sum[x + st - 1] - sum[st - 1]) <= m) return 1;
	else return 0;
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
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
	for(int i = 1;i <= n;i++)
	{
		ll l = 1,r = n - i;
		cnt = 0;
		while(l < r && cnt <= 100)
		{
			ll mid = (l + r + 1) / 2;
			if(check(mid,i)) l = mid;
			else r = mid - 1;
			cnt++;
		}
		if(cnt == 100) cout << 'w';
		ans = max(ans,l);
	}
	cout << ans;
	return 0;
}
