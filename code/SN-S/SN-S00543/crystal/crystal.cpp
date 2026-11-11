#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Max = 5e5 + 5;
int n,m;
int a[Max];
int ma[Max],mb[Max];
int maxn,Max2,cnt,ans,ANS;
bool cmp(int x,int y)
{
	int xx = cnt - x;
	int yy = cnt - y;
	return xx < yy;
}
bool check(int x)
{
	int cnt = m;
	for(int i = 1; i <= x; i++)
	{
		if(cnt >= a[x] - a[i])
		{
			cnt -= a[x] - a[i];
		}
		else return 0;
	}
	return 1;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	bool flagA = 1,flagB = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != i) flagA = 0;
		maxn = max(maxn,abs(a[i]));
		if(a[i] > 0) ma[a[i]]++;
		else mb[abs(a[i])]++;
	}
	int cha = a[2] - a[1];
	for(int i = 1; i < n; i++)
	{
		if(a[i + 1] - a[i] != cha) flagB = 0;
	}
	if(flagA == 1 || flagB == 1)
	{
		int l = 1,r = n,ans;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(check(mid)) 
			{
				l = mid + 1;
				ans = mid;
			}
			else r = mid - 1;
		}
		cout << ans << "\n";
		return 0;
	}
	for(int i = 1; i <= maxn; i++)
	{
		if(ma[i] > Max2)
		{
			Max2 = ma[i];
			cnt = i;
		}
		if(mb[i] > Max2)
		{
			Max2 = mb[i];
			cnt = -i;
		}
	}
	//Max2:众数的数量
	//cnt:众数 
	if(Max2 < 2)
	{
		sort(a + 1, a + 1 + n);
		cnt = a[(n + 1) / 2];
	}
	sort(a + 1, a + 1 + n, cmp);
//	for(int i = 1; i <= n; i++) cout << a[i] << " ";
	ans = Max2;
	for(int i = 1; i <= n; i++)
	{
		for(int i = n; i >= 1; i--)
		{
			if(m >= cnt - a[i] && a[i] != cnt)
			{
	//			cout << "  " << i << "  ";
				m -= cnt - a[i];
				ans++;
			}
			else break;
		}
	}
//	for(int i = 1; i <= n; i++)
//	{
//		if(a[i] > 0)
//		{
//			cout << a[i] << " ";
//			cnt = a[i];
//			Max2 = ma[a[i]];
//			if(Max2 < 2)
//			{
//				sort(a + 1, a + 1 + n);
//				cnt = a[(n + 1) / 2];
//			}
//			sort(a + 1, a + 1 + n, cmp);
//		//	for(int i = 1; i <= n; i++) cout << a[i] << " ";
//			ans = Max2;
//			for(int i = 1; i <= n; i++)
//			{
//				for(int i = n; i >= 1; i--)
//				{
//					if(m >= cnt - a[i] && a[i] != cnt)
//					{
//			//			cout << "  " << i << "  ";
//						m -= cnt - a[i];
//						ans++;
//					}
//					else break;
//				}
//			}
//		}
//		else if(a[i] < 0)
//		{
//			cnt = -a[i];
//			Max2 = mb[-a[i]];
//			if(Max2 < 2)
//			{
//				sort(a + 1, a + 1 + n);
//				cnt = a[(n + 1) / 2];
//			}
//			sort(a + 1, a + 1 + n, cmp);
//		//	for(int i = 1; i <= n; i++) cout << a[i] << " ";
//			ans = Max2;
//			for(int i = 1; i <= n; i++)
//			{
//				for(int i = n; i >= 1; i--)
//				{
//					if(m >= cnt - a[i] && a[i] != cnt)
//					{
//			//			cout << "  " << i << "  ";
//						m -= cnt - a[i];
//						ans++;
//					}
//					else break;
//				}
//			}
//		}
//		cout << cnt << " " << Max2 << " " << ans << "\n";
//		ANS = max(ans,ANS);
//	}
	cout << ans << "\n";
	return 0;
}
