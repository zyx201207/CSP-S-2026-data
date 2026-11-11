#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int a[500010],n,m,sum[500010];
bool check(int need)
{
	for(int i = need;i <= n;i++) if(need * a[i] <= m + sum[i] - sum[i - need]) return true;
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	sum[0] = 0;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1); 
	for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
	int l = 1,r = n;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << r << endl;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
