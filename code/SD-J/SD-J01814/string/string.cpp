#include<bits/stdc++.h>
using namespace std;
int n, a[200002];
char c[200002];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	//string s = "";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> c[i];
	}
	//比较每个区段的字母是否回文 不回文则修改一段 
	//修改字母 使得当前字符串为回文字符串 
	long long ct = 0, r = n - 1, l = 0;
	while(l < r)
	{
		if (c[l] != c[r])
		{
			ct += min(a[l], a[r]);
			//cout << ct << endl;
		}
		if (a[l] > a[r]) //左端大于右端 右端新段 
		{
			a[l] -= a[r];
			r--;
		}
		else if (a[l] == a[r])
		{
			l++;
			r--;
		}
		else
		{
			a[r] -= a[l];
			l++;
		}
	}
	cout << ct;
	return 0;
} 
