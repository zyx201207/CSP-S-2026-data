#include <bits/stdc++.h>
using namespace std;
vector<char> s;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int num;
		char c;
		cin >> num;
		cin >> c;
		for (int i = 0;i < num;i++)
			s.push_back(c);
	}
	for (long long i = 0;i < s.size()/2;i++)
	{
		if (s[i]!=s[s.size()-1-i])
		   ans++;
	}
	cout << ans << endl;
	return 0;
}