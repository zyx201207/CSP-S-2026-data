#include <iostream>
#include <cmath>
char c1[2] , c2[2] , s1[3] , s2[3];
char ccin[10];
using namespace std;

int pos(char c)
{
	if(c < 'D')
	{
		return int(c);
	}
	if(c == 'D')
	{
		return 10000;
	}
	return 10001;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	for(int i=0;i<10;i++)
	{
		cin >> ccin[i];
	}
	c1[0] = ccin[0];
	c1[1] = ccin[1];
	s1[0] = ccin[2];
	s1[1] = ccin[3];
	s1[2] = ccin[4];
	c2[0] = ccin[5];
	c2[1] = ccin[6];
	s2[0] = ccin[7];
	s2[1] = ccin[8]; 
	s2[2] = ccin[9];
	
	if(c1[0] != c2[0] || c1[1] != c2[1])
	{
		cout << "0000" << endl;
		return 0;
	}
	if (s1[0] != s2[0] || s2[1] != s1[1])
	{
		cout << "1000" << endl;
		return 0;
	}
	int p1 = pos(s1[2]) , p2 = pos(s2[2]);
	//cout << s1[2] << ' ' << s2[2] << endl;
	if(abs(p1 - p2) > 10) 
	{
		cout << "1100" << endl;
		return 0;
	}
	if(abs(p1 - p2) <= 1)
	{
		cout << "1111" << endl;
		return 0;
	}
	cout << "1110" << endl;
	return 0;
}
