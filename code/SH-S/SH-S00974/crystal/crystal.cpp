#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[500010],cha[500010];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool flag = 0;
    int d = a[2] - a[1];
    for (int i = 2; i <= n; i++)
    {
    	if (a[i] - a[i - 1] != d)
    	{
    		flag = 1;
    		break;
		}
	}
    if (n <= 3000)
    {
    	int anss = 0;
	    for (int pos = 1; pos <= n; pos++)
	    {
	        int target = a[pos];
	        for (int i = 1; i <= n; i++)
	        {
	            cha[i] = target - a[i];
	        }
	        sort(cha + 1,cha + n + 1);
	        int cnt = 0,ans = 0;
	        for (int i = 1; i <= n; i++)
	        {
	        	if (cha[i] < 0) continue;
	            if (cha[i] + cnt <= m)
	            {
	                ans++;
	                cnt += cha[i];
	            }
	            else break;
	        }
	        anss = max(ans,anss);
	    }
	    cout << anss << endl;
	}
	else if (!flag)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i * (a[1] + a[i]) / 2 <= m) continue;
			cout << i << endl;
			break;
		}  
	}
    else
    {
    	sort(a + 1,a + n + 1);
    	int ans = 1,cnt = 0;
		for (int i = 2; i <= n; i++)
    	{
    		cnt += (a[i] - a[i - 1]) * (i - 1);
    		if (cnt <= m) ans++;
		}
		cout << ans << endl;
	}
    return 0;
}
