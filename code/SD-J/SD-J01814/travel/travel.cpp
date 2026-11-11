#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string s1, s2; //座位号 
	cin >> c1 >> s1 >> c2 >> s2;
	int h1 = (s1[0] - '0') * 10 + (s1[1] - '0'); //行号 
	int h2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	int seat1, seat2;
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')//左侧 
		seat1 = 1; 
	else 
		seat1 = 2; //右侧 
	if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')//左侧 
		seat2 = 1; 
	else 
		seat2 = 2;
	if (c1 == c2) //是否在同一节车厢 
	{
		cout << 1;
		if (h1 == h2) //是否在同一排 
		{
			cout << 1;
			if (seat1 == seat2) //是否在同排同侧 
			{
				cout << 1;
				if (seat1 == 1) //在左侧判断两边距离 
				{
					if(abs(s1[2] - 'A' + s2[2] - 'A') != 2)
						cout << 1;
					else
						cout << 0;
				}
				else //在右侧必定相邻 
					cout << 1;
					
			}
			else
				cout << "00";	
		} 
		else
			cout << "000";
	}
	else
		cout << "0000";
	return 0;
} 
