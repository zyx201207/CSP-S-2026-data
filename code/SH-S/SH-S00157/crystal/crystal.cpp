#include <bits/stdc++.h>
using namespace std;
long long a[500005], pre[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n, m, ans = 0, t = 0, value = 0;
	cin >> n >> m; 
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	if (n > 5000)
	{
		long long k = a[2]-a[1];
		while(value<=m)
		{
			t++;
			value += (t*k);
		}
		cout << t - 1;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		pre[i] = a[i] - a[i-1];
	}
	//输入a[i]并计算前缀差，注意a[0]不要在后续计算中出现 
	for (int i = n; i >= 2; i--)
	{
		while (value<=m && i >= t)//用value和m进行比较，当value<m时可以继续加值，反之就停止 
		{
			t++;
			for (int j = i; j >= i - t + 1; j--)
			{
				value += pre[j];
			}
			//从pre[i]到pre[i+t-1]的一个累加，pre[i+t-1]应该最终要累加t次，可以验证一下  
		}
		//此时不满足value<=m,即value>m,应减去最后一次的累加并还原临时变量t、value
		ans = max(ans, t);
		value = 0;
		t = 0; 
	}
	cout << ans;
	return 0;
	
}
