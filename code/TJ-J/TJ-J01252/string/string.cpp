#include<bits/stdc++.h>
using namespace std;
int n,cnt = 1;
long long k;
string c;
string a = "";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> k >> c;
		for (int j = 1;j <= k;j++)
		{
			a += c;
		}
	}
	for (int i = 0;i <= a.size()/2;i++)
	{
		if (a[i] != a[a.size()-i-1])
		{
			cnt++;
		}
	}
	cout << (cnt-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
