#include<bits/stdc++.h>
using namespace std;


int T;
long long sum,cnt;
long long z;
long long m;
long long n;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> T;
	while(T --)
	{
		int a;
		char a1;
		cin >> a >> a1;
		sum += a;
		for(int i = 1;i <= a;i ++)
		{
			s += a1;
		}
	}
	if(T == 1)
	{
		cout << 0;
		return 0;
	}
	if(sum % 2 == 1)
	{
		z = sum - 1;
		m = sum / 2 - 1;
		n = sum - m - 1;
	}
	else 
	{
		z = sum - 1;
		m = sum / 2 - 1;
		n = sum / 2 + 1;
	}
	for(int l = 0,r = z;l <= m,r >= n;l ++,r--)
		{
			if(s[l] == s[r]) continue;
			else cnt ++;
		}
	cout << cnt;
	return 0;
}
