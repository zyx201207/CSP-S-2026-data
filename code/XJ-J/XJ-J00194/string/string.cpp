#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,flag2 = 1,ans = 0;
	bool flag1 = 1;
	cin >> n;
	vector<int> a(n);
	vector<char> s(n);
	ll sum = 0;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
		cin >> s[i];
		sum += a[i];
		if(i > 1)
		{
			if (s[i] != s[i-1])
			{
				flag1 = 0;
				flag2++;
			}
		}
	}
	if(flag1)
	{
		cout << 0;
		return 0;
	}
	if(flag2 == 2)
	{
		cout << min(a[0],a[1]);
		return 0;
	}
	string s1;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < a[i];j++)
		{
			s1 += s[i];
		}
	}
	for(int i = 0;i < sum/2;i++)
	{
		if (s1[i] != s1[sum-i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
