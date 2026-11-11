#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int cnt;
	int maxx = -1;
	string maxa;
	int n;
	cin >> n;
	for(int i = 1;i <= n; i++)
	{
		int x;
		char a;
		cin >> x >> a;
		if(x > maxx)
		{
			maxx = x;
			maxa = a;
		}
		string m;
		for(int j = i;j <= x+i;j++)
		{
			m[i] = a;
			s = s + m;
		}
	}
	for(int i = 1;i <= s.size();i++)
	{
		if(s[i] == s[s.size()-i+1])
			cnt++;
	} 
	if(cnt == s.size())
		cout << 0;
	else
		cout << s.size() - maxa.size();
		return 0; 
}
