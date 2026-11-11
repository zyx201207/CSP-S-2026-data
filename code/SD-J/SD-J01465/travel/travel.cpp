#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define FOR(w, a) for(i64 i = w; i <= a; i++)
#define I ios::sync_with_stdio(0);
#define AC cin.tie(0);
#define T1 cout.tie(0);
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	I AC T1;
	string s1, s2, t1, t2;
	cin >> s1 >> t1 >> s2 >> t2;
	if(s1 != s2) cout << "0000";
	else
	{
		if(!(t1[0] == t2[0] && t1[1] == t2[1])) cout << "1000";
		else
		{
			char ch1 = t1[2], ch2 = t2[2];
			if(ch1 == 'D')ch1 = 'E';
			if(ch2 == 'D')ch2 = 'E';
			if(ch1 == ch2 + 1 || ch2 == ch1 + 1)cout << "1111";
			else
			{
				if(ch1 <= 'C' && ch2 <= 'C') cout << "1110";
				else if(ch1 >= 'E' && ch2 >= 'E') cout << "1110";
				else cout << "1100";
			}
		}
	}
	return 0;
}
//ÎÒÊÇÐ¡ÌÆµ° 
