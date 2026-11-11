#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 100;

int n, m;
int arr[N];
int sum[N];
int dis[N];

bool check(int x)
{
//	cout<<dis[x];
	if(dis[x] <= m) return 1;
	for(int i = x; i <= n ; i ++)
	{
		int r = i;
		int l = i - x + 1;
		int res = dis[r] - dis[l] - (sum[r] - sum[l]) * (i - x);
		if(res <= m) return 1;
	}
	return 0;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	for(int i = 1; i <= n ; i ++)
	{
		cin>>arr[i];
	}
	
	sort(arr + 1, arr + n + 1);
	
	for(int i = 2; i <= n ; i ++)
	{
		sum[i] = sum[i-1] + arr[i] - arr[i-1];
		dis[i] = dis[i-1] + (arr[i] - arr[i-1]) * (i - 1);
		
	}
	
//	cout<<"sum:";
//	for(int i = 1; i <= n ; i ++)
//	{
//		cout<<sum[i]<<' ';
//	}
//	cout<<endl<<"dis:";
//	for(int i = 1; i <= n ; i ++)
//	{
//		cout<<dis[i]<<" ";
//	}
//	cout<<endl;
	
	int l = 1, r = n;
	int ans;
	while(l <= r)
	{
		int mid = (l + r) / 2;
//		cout<<mid<<endl;
		if(check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout<<ans<<endl;
	return 0;
	
}
