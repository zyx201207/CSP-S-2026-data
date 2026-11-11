# include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char ch1 = s1[2],ch2 = s2[2];
	s1 = s1.substr(0,2);
	s2 = s2.substr(0,2);
	bool f0 = (c1 == c2),f1 = f0 && (s1 == s2),f2 = f1 && ((ch2 <= 'C' && ch1 <= 'D') || (ch2 >= 'D' && ch1 >= 'D'));
	
	cout << f0;

	cout << f1;
	cout << f2;
	cout << (f2 && (abs((int)(ch2 - ch1)) == 1)) << endl;
	return 0;
}
