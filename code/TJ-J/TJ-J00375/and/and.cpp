#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int a[200010] , boxes[4];
int ans = -1;
bool is2powedminus1(int x)
{
	return !(x & (x + 1));
}
int f(int x)
{
	int res = x;
	int ret = 1;
	while(res > 0)
	{
		ret *= 2;
		res /= 2;
	}
	return ret;
}
void dfs(int step , int w , int cur)
{
	if(step == m)
	{
		ans = max(ans , w);
		return;
	}
	for(int i=cur+1;i<=n;i++)
	{
		dfs(step + 1 , w & a[i] , i);
	}
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	bool flag = true;
	bool flagA = true;
	bool flagB = true;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i] >= 4) {
			flag = false;
		} else {
			boxes[a[i]]++;
		}
		flagA = flagA && is2powedminus1(a[i]);
		flagB = flagB && !(a[i]-i+1);
	}
	if (n == m) {
		ans = 2147483647;
		for(int i=1;i<=n;i++)
		{
			ans = ans & a[i];
		}
	} else if(flag) {
		if(boxes[3] >= m) {
			ans = 3;
		} else {
			int works = m - boxes[3];
			if(boxes[2] >= works){
				ans = 2;
			} else if(boxes[1] >= works){
				ans = 1;
			} else {
				ans = 0;
			}
		}
	} else if(n == m + 1) {
		for(int i=1;i<=n;i++)
		{
			int ans0 = 2147483647;
			for(int j=1;j<=n;j++)
			{
				if(j != i)
				{
					ans0 = ans0 & a[j];
				}
			}
			ans = max(ans , ans0);
		}
	} else if(flagA) {
		sort(a + 1,a + n + 1);
		ans = a[n-m+1];
	} else if(flagB && is2powedminus1(n-1)) {
		ans = n - f(m-1);
	} else {
		dfs(0 , 2147483647 , 0);
	}
	cout << ans << endl;
	return 0;
}
