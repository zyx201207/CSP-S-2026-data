#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n, m, a[N], maxn, pre[N];
bool check(int mid, int i)
{
	int sum1 = a[i] * (i - mid + 1);
	int sum2 = pre[i] - pre[mid - 1];
	if(sum1 - sum2 > m) return false;
	return true;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++) pre[i] = pre[i - 1] + a[i];
	for(int i = 1; i <= n; i ++)
	{
		int l = 1, r = i;
		while(l < r)
		{
			int mid = l + (r - l) / 2;
			if(check(mid, i)) r = mid;
			else l = mid + 1;
		}
		int len = i - l + 1;
//		int k = i;
//		while(a[k] == a[k + 1]) k ++;
//		int sum = 0, id = i;
//		for(int j = i - 1; j > 0; j --)
//		{
//			id = j;
//			sum += a[i] - a[j];
//			if(sum > m)
//			{
//				id ++;
//				break;
//			}
//		}
//		i = k;
//		int len = i - id + 1;
		maxn = max(maxn, len);
	}
//	int l = 1, r = n;
//	while(l < r)
//	{
//		int mid = l + (r - l + 1) / 2;
//		if(check(mid)) l = mid;
//		else r = mid - 1;	
//	}
	
	// Debug
//	int sum = 0, id = 4396;
//	for(int i = 4396 - 1; i > 0; i --)
//	{
//		id = i;
//		sum += a[4396] - a[i];
//		if(sum > m)
//		{
//			id ++;
//			break;
//		}
//	}
//	cout << a[4396] << " " << a[id] << " " << m - (sum - (a[4396] - a[id])) << "\n";
//	cout << a[3835] << "\n";
//	for(int i = 1; i <= n; i ++) cout << a[i] << " ";
//	cout << "\n";
	
	cout << maxn << "\n";
	return 0;
} 
