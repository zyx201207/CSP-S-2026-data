#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5e5+5;
int n;
ll m;
ll a[MAXN];
int ans;
ll pre[MAXN];
int px(int x, int y)
{
	return x < y;
}
bool check(int x)
{
	for(int i = 1; i <= n-x+1; i++)
	{
		int j = i+x-1;
		if(x * a[j] <= pre[j] - pre[i-1] + m) return 1;
	}
	return 0;
}
 
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+1+n, px);
	for(int i = 1; i <= n; i++)
	{
		pre[i] = pre[i-1] + a[i];
	}
	int l = 1, r = n;
	while(l <= r)
	{
		int mid = (l+r)/2;
		if(check(mid))
		{
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	//for(int i = 1; i <= n; i++)
	//{
		//int st = i-len+1;
		//while(siz * a[i] < pre[i] - pre[st-1] + m)
		//{
			//siz++;
		//}
		//ans = max(ans, len-1);
	//}
	cout << ans;

	return 0;
}//Oct31==Dec25?
