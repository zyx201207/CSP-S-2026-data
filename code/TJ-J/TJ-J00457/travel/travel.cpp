#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout << "1";
		string a, b;
		for(int i = 0; i < s1.size(); i++)
			if(isdigit(s1[i])) a += s1[i];
		for(int i = 0; i < s2.size(); i++)
			if(isdigit(s2[i])) b += s2[i];
		if(a == b) {
			cout << "1";
			if((s1[s1.size() - 1] == 'A' || s1[s1.size() - 1] == 'B' || s1[s1.size() - 1] == 'C') && (s2[s2.size() - 1] == 'A' || s2[s2.size() - 1] == 'B' || s2[s2.size() - 1] == 'C')) {
				cout << "1";
				int x = s1.size() - 1, y = s2.size() - 1;
				if(abs(int(s1[x]) - int(s2[y])) == 1) cout << "1";
				else cout << "0";
			} else if((s1[s1.size() - 1] == 'D' || s1[s1.size() - 1] == 'F') && (s2[s2.size() - 1] == 'D' || s2[s2.size() - 1] == 'F')) {
				cout << "1";
				int x = s1.size() - 1, y = s2.size() - 1;
				if(abs(int(s1[x]) - int(s2[y])) == 1) cout << "1";
				else cout << "0";
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
