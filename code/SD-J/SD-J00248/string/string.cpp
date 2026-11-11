#include <bits/stdc++.h>
using namespace std;
long long n,num,a[200001];
char c[200001];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		for(long long j = 1;j <= a[i];j++)
		{
			s += c[i];
		}
	}
	for(long long i = 0;i < s.size();i++)
	{
		if(s[i] != s[s.size()-1-i])
		{
			num++;
		}
	}
	cout << num / 2;
	return 0;
}
