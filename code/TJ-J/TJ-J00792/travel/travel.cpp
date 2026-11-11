#include<bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;
bool ans1,ans2,ans3,ans4;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout << 1;
		for(int i = 0; i < 2; ++i) {
			if(s1[i] != s2[i]) {
				cout << "000";
				return 0;
			}
		}
		cout << 1;
		if(s1[2] <= 'C' && s2[2] > 'C' || s2[2] <= 'C' && s1[2] > 'C') {
			cout << "00";
			return 0;
		}
		cout << 1;
		if(abs(s1[2] - s2[2])!=1) {
			cout << 0;
			return 0;
		}
		cout << 1;
		return 0;
	}
	else cout<<"0000";
	return 0;
} 
