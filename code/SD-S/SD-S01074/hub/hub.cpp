#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<string> s1, s2;
	freopen("subway7.ans", "r", stdin);
	string s;
	while(cin >> s)
		s1.push_back(s);
	freopen("subway.out", "r", stdin);
	while(cin >> s)
		s2.push_back(s);
	if(s1.size() != s2.size())
	{
		cout << "?" << endl;
	}
	for(int i = 0; i < s1.size(); i++)
		if(s1[i] != s2[i])
			cout << "! at " << i + 1 << endl;
}
// zzz
