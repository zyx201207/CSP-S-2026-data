#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int n;
long long m,ans,sum,cnt,a[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	
	for(int i = 2;i < n;i++)
	{
		sum = 0,cnt = 1;
		int h = i,t = i;
		while(sum <= m){
			if(h - 1 >= 1 && t + 1 <= n)
			{
				if(a[i] - a[h - 1] <= a[t + 1] - a[i])
				{
					sum += a[i] - a[h - 1];
					if(sum > m) break;
					cnt++;
					h--;
				}
				else
				{
					sum += a[t + 1] - a[i];
					if(sum > m) break;
					cnt++;
					t++;
				}
			}
			else if(h - 1 >= 1)
			{
				if(a[i] - a[h - 1] <= a[t + 1] - a[i])
				{
					sum += a[i] - a[h - 1];
					if(sum > m) break;
					cnt++;
					h--;
				}
			}
			else if(t + 1 <= n)
			{
				if(a[i] - a[h - 1] <= a[t + 1] - a[i])
				{
					sum += a[t + 1] - a[i];
					if(sum > m) break;
					cnt++;
					t++;
				}
			}
			if(h - 1 < 1 || t + 1 > n)
				break;
		
		}
		ans = max(ans,cnt);
	}
	
	cout << ans << "\n";
	
	return 0;
}
