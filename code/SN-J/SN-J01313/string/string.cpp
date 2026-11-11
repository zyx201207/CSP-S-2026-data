#include<bits/stdc++.h>
using namespace std;
long long n,b,z,cnt;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> b >> c;
		for(int j = 1;j <= b;j++)
		{
			s += c;
			z++;
		}
	}
	for(int i = 0;i < z / 2;i++)
	{
		if(s[i] != s[z - i - 1])
			cnt++;
	}
	cout << cnt;
	return 0;
}
