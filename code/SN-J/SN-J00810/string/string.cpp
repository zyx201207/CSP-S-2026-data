// Íõ¿¬ä¿ SN-J00810 
#include <bits/stdc++.h>
using namespace std;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s = "";
	int n,a;
	char x;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a >> x;
		for(int i = 1;i <= a;i++)
			s += x;
	}
	string k = s;
	s = ' ' + s;
	if (k.size() % 2 == 0)
	{
		for(int i = 1;i <= k.size() / 2;i++)
		{
			if (s[i] != s[k.size() - i + 1])
				ans++;
		}
	}
	cout << ans;
	return 0;
}
