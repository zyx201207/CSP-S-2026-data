#include <bits/stdc++.h>
using namespace std;
bool hw(string m,long long x)
{
	for(int i = 1;i <= x;i++)
	{
		if(m[i] != m[x+1-i])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	long long sum = 0;
	int a[20005];
	string c[20005],num = "";
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cin >> c[i];
		sum += a[i];
		for(int j = 1;j <= a[i];j++)
		{
			num+=c[i];
		}
	}
	if(n == 1)
	{
		cout << 0;
	}
	else if(n == 2)
	{
		if(hw(num,sum))
		{
			cout << "0"; 
		}
		else
		{
			cout << sum/2;
		}
	}
	return 0;
}
