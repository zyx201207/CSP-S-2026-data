#include <bits/stdc++.h>
using namespace std;
long long n,m,mx;
long long arr[500010];
long long sm[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr,arr + n); 
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	if(arr[1] == arr[n])
	{
		cout << n;
		return 0;
	}
	sm[n] = 0;
	int flag = 0;
	for(long long i = n - 1; i >= 1; i--)
	{
		sm[i] = sm[i + 1] + arr[n] - arr[i];
		if(sm[i] != sm[i + 1]) flag = 1;
	}
	if(flag == 0)
	{
		int r = sm[n - 1],cnt = 0;
		while(m >= r)
		{
			m -= r;
			cnt++;
			r += sm[n - 1];
		}
		cout << cnt;
		return 0;
	}
	for(long long i = 0; i < n; i++)
	{
		long long mm = m,j = i - 1;
		while(mm - arr[i] + arr[j] >= 0 && j >= 0)
		{
			mm -= arr[i] - arr[j];
			mx = max(mx,i - j + 1);
			j--;
		}
	}
	cout << mx;
	return 0;
}
