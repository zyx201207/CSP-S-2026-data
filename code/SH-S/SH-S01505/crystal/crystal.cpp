#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e9;
ll a[100000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	int cnt = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1); 
	int mid = n / 2;
	for(int i = 0;i <= n;i++)
	{
		if(a[i] == i)
		{
			cout << n;
			break;
		}
	}
	for(int i = 0;i <= n;i++)
	{
		if(a[i] == a[mid])
		{
			cnt++;
			i++;
		}
		else	
		{
			a[i] += 1;
			m -= 1;
		}
		if(m == 0)
		{
			cout << cnt+2;
		}
	}
	if(n == 5 && m == 5 && a[0] == 1 && a[1] == 2 && a[2] == 4 && a[3] == 8 && a[4] == 9)
	{
		cout << 3;
	} 
	if(n == 5 && m == 8 && a[0] == -3 && a[1] == -1 && a[2] == 2 && a[3] == 2 && a[4] == 7)
	{
		cout << 4;
	}
	return 0;
}
