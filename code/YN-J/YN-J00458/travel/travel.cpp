#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	bool f1 = 0,f2=0,f3=0;
	if (s1 == s3)
		cout << 1,f1=1; //1
	else cout<<0;
	int a1 = 0, a2 = 0;
	a1 += s2[0] - '0' + s2[1] - '0';
	a2 += s4[0] - '0' + s4[1] - '0';

	if (a1 == a2&&f1)
		cout << 1,f2=1; //2
	else cout<<0;

	if (s2[2] >= 'D' && s2[2] <= 'F' && s4[2] >= 'D' && s4[2] <= 'F'&&f2)
		cout << 1 << endl, f3 = 1; //3

	if (s2[2] <= 'C' && s2[2] >= 'A' && s4[2] >= 'A' && s4[2] <= 'C'&&f2)
		cout << 1, f3 = 1; //3
	if(f3==0)cout<<0;
	if (f3 && abs(s2[2] - s4[2]) == 1)//4
		cout << 1;
	else cout<<0;

	return 0;
}
