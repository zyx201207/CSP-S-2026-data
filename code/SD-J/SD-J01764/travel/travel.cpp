#include<bits/stdc++.h>

using namespace std;

int main ()
{
	//Trick||Treat!
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	string c1 , s1;
	string c2 , s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[1] == c2[1])
	{
		cout << 1;
		if(s1[1] == s2[1])
		{
			cout << 1;
			if((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'E' && s2[2] >= 'D' && s2[2] <= 'E'))
			{
				cout << 1;
				int a=s1[2] , b=s2[2];
				if((a+1==b)||(b+1==a))
 				{
 					cout <<1; 
				}
				else
				{
					cout << 0;
				}
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
		
	}
	
 	
	return 0;
}

