#include<bits/stdc++.h>
#define ll long long
using namespace std;

string c1, s1, c2, s2;
bool q1, q2, q3, q4;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	//cout << s1[0] << ' ' << s1[1] << ' ' << s1[0] + s1[1];
	q1 = q2 = q3 = q4 = false;
	if(c1 == c2)
	{
		cout << 1;
		q1 = true;
		//cout << "yes" << endl;
	}
	if(q1 == true)
		if((s1[0] + s1[1] == s2[0] + s2[1]))
		{
			cout << 1;
			//cout << s1[0] + s1[1] << ' ' << s2[0] + s2[1] << endl;
			q2 = true;
			//cout << "yes" << endl;
		}
	if(q2 == true)
		if(q2 == true && (s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'C' && s2[2] == 'A') || (s1[2] == 'F' && s2[2] == 'D'))
		{
			cout << 1;
			q3 = true;
			//cout << "yes" << endl;
		}
	if(q3 == true)
	{
		if((s1[2] + 1 == s2[2] || s1[2] == s2[2] + 1))
		{
			cout << 1;
			q4 = true;
			//cout << "yes" << endl;
		}
	}
	if(q1 == false)cout << "0000";
	else if(q2 == false)cout << "000";
	else if(q3 == false)cout << "00";
	else if(q4 == false)cout <<"0";
	return 0;
}
