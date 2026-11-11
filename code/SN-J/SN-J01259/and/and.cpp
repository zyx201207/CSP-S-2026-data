#include <bits/stdc++.h>
using namespace std;
int k = 1e5,cnt = 0;
bool zhishu(int x){
	int w = x;
	while(w > 1)
	{
		if(w % 2 == 1)
		{
			return 1;
		}
		w /= 2;
	}
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[2 * k];
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	sort(a,a + n);
	long long ans = a[n - 1];
	if(!zhishu(ans))
	{
		cnt++;
		ans = a[n - 2];
	}
	for(int i = n - 2;i > n - 1 - m;i--)
	{
		if(!zhishu(a[i]))
		{
			cnt++;
		}
		ans &= a[i - cnt];
	}
	cout << ans;
	return 0;
}
