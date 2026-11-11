#include<bits/stdc++.h>
using namespace std;
#define sp " "
typedef long long ll;
const int N = 5e5 + 5;
int n, ans;
ll m, a[N], sum[N];
bool check(int mid, int i)
{
	ll res = sum[mid] + (a[i] - a[mid]) * mid;
	return (sum[i] - res) <= m;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		sum[i] = sum[i-1] + (a[i] - a[i-1]) * (i - 1);
		int l = 0, r = i, pos = i;
		while(l <= r)
		{
			int mid = (l+r) >> 1;
//			printf("DEBUG! 第%d颗  l=%d,r=%d,mid=%d\n",i,l,r,mid);
			if(check(mid, i)) //相减是否<=m 
			{
				r = mid - 1;
				pos = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		ans = max(ans, i - pos);
	}
	cout << ans << endl;
	return 0;
}

//先排序， 遍历n，并维护一个差值数组（前面的值与当前值的差的和） 

