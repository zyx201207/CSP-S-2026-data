#include<bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 5e5 + 10;
int a[maxn],b[maxn];

int n,m,cnt[maxn],pre[maxn];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i],b[i] = a[i];
	
	sort(b + 1,b + n + 1);
	int tot = unique(b + 1,b + n + 1) - b - 1;
	
	for(int i = 1;i <= n;i++)
	{
		int val = lower_bound(b + 1,b + tot + 1,a[i]) - b;
		cnt[val]++;
	}
	
	int l = 1,ans = 0; 
	int sum = 0,ct = 0;
	for(int i = 1;i <= tot;i++)
	{
		ct += cnt[i - 1];
		sum += ct * (b[i] - b[i - 1]);
		
		while(l < i && sum > m)
		{
			int val = b[i] - b[l];
			sum -= cnt[l] * val;
			ct -= cnt[l];
			l++;
		}
		
		int res = ct + cnt[i],sy = m - sum,d = b[i] - b[l - 1];
//		cout << i << " " << res << '\n';
		if(d) res += min(sy / d,cnt[l - 1]);
		ans = max(ans,res);
//		cout << i << " " << res << '\n';
	}
	cout << ans << '\n';
	return 0;
}
