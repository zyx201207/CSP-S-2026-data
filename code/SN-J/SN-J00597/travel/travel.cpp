#include<iostream>
using namespace std;
int main()
{
	freopen(travel.in,'r',stdin);
	freopen(travel.out,'w',stdout);
	string y;
	int c1;
	char s1[10000];
	int c2;
	char s2[10000];
		
	cin >> c1;
	for (int i= 0;i< 3;i++)
	{
		cin >> y;
		s1[i] = y;
	} 
	
	cin>> c2;
	for (int i = 0;i < 3;i++)
	{
		cin >> y;	
		s2[i] = y;
	}
	
	if (c1 == c2){
		cout << 1;
		if (s1[0] == s2[0] && s1[1] == s2[1])
		{
			cout << 1;
			if (((s1[2]== 'A' || s1[2]== 'B' || s1[2]== 'C') && (s2[2]== 'A' || s2[2]== 'B' || s2[2]== 'C')) || ((s1[2]== 'D' || s1[2]== 'F' ) && (s2[2]== 'D' || s2[2]== 'F')))
			{
				cout << 1;
				if(s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1)
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
			else 
			{
				cout << 0;
			}
		}
		else{
			cout << 0;
		}
	}
	
	return 0;
}
