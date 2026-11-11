#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[200005];
long long sum = 0;
string s;
char c[200005];
map < char,bool > mp;
/*
8:30 TO 8:45
I did the first problem.
8:45 TO 9:30
I did the scend problem,but it is eazy to TLE.
9:30 TO 10:25
I did the third problem,maybe it well TLE.
10:25 TO 10:30
I did the second problem again.
10:30 TO 10:45
I did the forth problem,i think it well TLE,well that is my best.
rp++
*/
//CCF give me AC please!
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum += a[i];
		getchar();
		cin >> c[i];
		mp[c[i]] = true;
	}
	
	if (mp.size() == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1;i <= n;i++)
		for (long long j = 1;j <= a[i];j++)
			s += c[i];
	long long ans = 0;
	long long mid;
	if (sum % 2 == 1)
	{
		mid = (sum + 1) / 2;
		for (int i = 0;i < mid;i++)
		{
			if (s[i] != s[sum - i - 1])
				ans++;
		}
	}
	else
	{
		mid = sum / 2;
		for (int i = 0;i < mid;i++)
		{
			if (s[i] != s[sum - i - 1])
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
