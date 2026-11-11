//string
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//初始化 
	int n;
	long long a[200005],ans = 0;
	char c[200005];
	//输入 
	cin >>n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	long long shang = 1, xia = n;
	while (xia - shang > 1)//遍历 
	{
		if(c[shang] == c[xia])//两区间字母相同 
		{
			if (a[shang] > a[xia])//如果上面的区间比较大 
			{
				a[shang] -=a[xia];
				xia--;
			}
			else if(a[shang < a[xia]])//如果下面的区间比较大
			{
				a[xia] -= a[shang];
				shang++;
			} 
			else//两者相等
			{
				shang++;
				xia--;	
			} 
		}
		
		if(c[shang] != c[xia])//两区间字母不同
		{
		 
			 if (a[shang] > a[xia])//如果上面的区间比较大 
			{
				ans += a[xia]; 
				a[shang] -=a[xia];
				xia--;
			}
			else if(a[shang < a[xia]])//如果下面的区间比较大
			{
				ans += a[shang];
				a[xia] -= a[shang];
				shang++;
			} 
			else//两者相等
			{
				ans += a[xia];
				shang++;
				xia--;	
			} 
		} 
	}
	if (xia - shang == 1){
		if (c[shang] == c[xia]) xia++;
		else
		{
			ans += min(a[shang],a[xia]);
			xia++;
		}
	}
	if (shang - xia == 0){
		cout << ans;
	}
	cout << ans <<" ";
	return 0;
} 
