#include <bits/stdc++.h>
using namespace std;
int a[500005], cnt[300005];
string sss[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout); 
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int k = 1; k <= n; k++)
	{
		string s = "";
		//if (k != 7) continue;
		for (int i = k; i <= n; i++)
		{
			string t = to_string(a[i]);
			if (s.find(t) == string::npos)
			{
				//cout << "no\n";
				s += t;
				//cout << s << endl;
			}
			else if (s.find(t) != string::npos)
			{
				//cout << "find\n";
				string ss = "";
				for (int j = 0; j < s.find(t); j++) ss[j] = s[j];
				s = ss;
				s += t;
				//cout << s << endl;
			}
		}
		//cout << s << "\n";
		sss[k] = s;
	}
	//for (int i = 1; i <= n; i++) cout << sss[i] << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (sss[i].find(to_string(j)) != string::npos)
			{
				cnt[j]++;
				continue;
			}
		}
	}
	for (int i = 1; i <= m; i++) cout << cnt[i] << " ";
	return 0; 
 } 
