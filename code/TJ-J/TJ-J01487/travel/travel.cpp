#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
bool sameche(string c1,string c2)
{
	bool flag = true;
	for(int i=0;i<2;i++)
		if(c1[i]!=c2[i])
			flag = false;
	return flag;
}
bool samepai(string s1,string s2)
{
	bool flag = true;
	for(int i=0;i<2;i++)
		if(s1[i]!=s2[i])
			flag = false;
	return flag;
}
bool samebian(string c1,string c2)
{
	bool flag = true;
	if(s1[2]<='C'&&s2[2]>='D') flag =false;
	if(s2[2]<='C'&&s1[2]>='D') flag =false;
	return flag;
}
bool neighber(string s1, string s2)
{
	bool flag = true;
	if(abs(s1[2]-s2[2]) != 1)	flag = false;
	if(s1[2] == 'D' && s2[2] == 'C' || s2[2] == 'D' && s1[2] == 'C') flag = false;
	return flag;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(sameche(c1,c2) == false) cout << "0000";
	else 
	{
		cout << '1';
		if(samepai(s1,s2) == false) cout << "000";
		else 
		{
			cout << '1';
			if(samebian(s1,s2) == false) cout << "00";
			else
			{
				cout << '1';
				if(neighber(s1,s2)==true) cout << '1'; 
				else cout << '0';
			}
		}
	}
	return 0;
}
