#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],flag = 1,ans,k[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 3;i <= n;i++) if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]) flag = 0;
	if(flag) cout << (long long)(sqrt(1 + 8.0 * m / (a[n] - a[n - 1])) - 1) / 2 + 1 << endl;
	else
	{
		int ans = 1;
		for(int i = a[1];i <= a[n];i++)
		{
			memset(k,0x3f,sizeof(k));int l = 0,cnt = 0,sum = m;
			while(l <= n && a[l] <= i) k[++l] = i - a[l];l--;
			for(int j = l;j >= 1;j--)
			{
				sum -= k[j],cnt++;
				if(sum < 0)
				{
					cnt--;
					break;
				}
			}
			ans = max(ans,cnt);
		}
		cout << ans << endl;
	}
	return 0;
}
