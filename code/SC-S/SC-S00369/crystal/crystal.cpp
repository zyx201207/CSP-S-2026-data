#include<iostream>
#include<algorithm>
#define N 500010
#define ll long long
using namespace std;
ll n,m;
ll arr[N],brr[N],crr[N];
bool case_a = true,case_b = true;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>arr[i];
		if(case_a && arr[i] != arr[i - 1] && i >= 2)
		{
			case_a = !case_a;
		}
		if(case_b && (arr[i] - arr[i - 1]) != (arr[i - 1] - arr[i - 2]) && i >= 3)
		{
			case_b = !case_b;
		}
	}
	if(case_a)
	{
		cout<<n;
		return 0;
	}
	if(case_b)
	{
		int x = arr[2] - arr[1];
		cout<<m / x + 1;
		return 0;
	}
	sort(arr + 1,arr + 1 + n);
	for(int i = 1;i <= n;i++)
	{
		brr[i] = arr[i] - arr[i - 1];
		crr[i] = crr[i - 1] + brr[i];
	}
	ll l = 1,r = 1;
	ll cnt = 1,num = 0;
	while(r <= n)
	{
		if(num <= m)
		{
			r++;
			num += (r - l) * brr[r];
		}
		else
		{
			cnt = max(cnt,r - l);
			num -= crr[r] - crr[l];
			l++;
		}
	}
	cnt = max(cnt,r - l);
	cout<<cnt;
	return 0;
}
/*
5 5
1 2 4 8 9

3
*/

/*
5 8
-3 -1 2 2 7

4
*/