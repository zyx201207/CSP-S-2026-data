#include<bits/stdc++.h>
using namespace std;

int o[200005], f[200005];

bool get(int x, int pos)
{
	int kkksc03 = 1 << pos;
	return((x & kkksc03) >> pos);
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	memset(f, 1, sizeof(f));
	
	int n, m, ans = 0;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) cin >> o[i];
	
	for(int i = 29; i >= 0; i--)
	{
		int cnt = 0;
		
		for(int j = 1; j <= n; j++)
		{
			if(get(o[j], i) && f[j]) cnt++;
		}
		
		if(cnt >= m)
		{
			for(int j = 1; j <= n; j++)
			{
				if(!get(o[j], i)) f[j] = 0;
			}
			ans += 1 << i;
		}
	}
	
	cout << ans << "\n";
	
	return(0);
}
