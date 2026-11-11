#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
long long n,a[N];
string s1;
string c;
long long l,ans;
bool h(string s)
{
	string m;
	for(int i = s1.size() - 1;i >= 0;i--)
	{
		m += s[i];
	}
	if(m == s) return true;
	else return false;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c;
		l += a[i];
		for(int j = 1;j <= a[i];j++)
		{
			s1 += c;
		}
	}
	if(h(s1))
	{
		cout << 0;
		return 0;
	}
	for(int i = 0;i < s1.size();i++)
	{
		if(s1[i] != s1[l - 1 - i])
		{
			s1[l - 1 - i] = s1[0];
			ans++;
		} 	 
	}
	cout << ans;
	return 0;
}




