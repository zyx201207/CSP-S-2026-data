#include <bits/stdc++.h>
using namespace std;
int main()
{
	string c1;
	string s1;
	string c2;
	string s2;
	cin >>c1;
	cin >>s1;
	cin >>c2;
	cin >>s2;
	if(c1==c2)
		cout << "1";
	else
		cout << "0";
	if(s1[1]==s2[1]&&s1[2]==s2[2])
		cout << "1";
	else 
		cout << "0";
	if((s1[3]==('A'||'B'||'C')&&s2[3]==('A'||'B'||'C'))||(s1[3]==('D'||'F')&&s2[3]==('D'||'F')))
		cout << "1";
	else
		cout << "0";
	if((s1[3]=='A'&&s2[3]=='B')||(s2[3]=='A'&&s1[3]=='B')||(s2[3]=='B'&&s1[3]=='C')||(s2[3]=='C'&&s1[3]=='B')||(s2[3]=='D'&&s1[3]=='F')||(s2[3]=='F'&&s1[3]=='D'))
		cout <<"1";
	else
		cout <<"0";
	return 0;
}
