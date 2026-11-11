#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << 1;
		string r = s1.substr(0, 2);
		string x = s2.substr(0, 2);
		if (r == x){
			cout << 1;
			string st = "";
			st+=s1[2];st+=s2[2];
			sort (st.begin(), st.end());
			if (st == "AB" || st == "AC" || st == "BC" || st == "DF"){
				cout << 1;
				if (st == "AB" || st == "BC" || st == "DF"){
					cout << 1;
				}
				else{
					cout << "0";
					return 0;
				}
			}
			else{
				cout << "00";
				return 0;
			}
		}
		else{
			cout << "000";
			return 0;
		}
	}
	else{
		cout << "0000";
		return 0;
	}
	return 0;
}
