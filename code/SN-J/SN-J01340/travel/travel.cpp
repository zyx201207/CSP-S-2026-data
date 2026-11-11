#include<bits/stdc++.h>
using namespace std;
int main()
{
	//feopen(".in","r",stdin);
	//feopen(".out","w",stdout);
	string s1,s2;
	char c1[5],c2[5];
	int cc1,cc2;
	cin >> s1;
	for (int i = 1;i <= 3;i ++)
	{
		cin >> c1[i];
	}
	cin >> s2;
	for (int i = 1;i <= 3;i ++)
	{
		cin >> c2[i];
	}
	cc1 = c1[1] * 10 + c1[2];
	cc2 = c2[1] * 10 + c2[2];
	if (s1 == s2)
	{
		cout << "1";
		if (cc1 == cc2)
    	{
	    	cout << "1";
	    	if (c1[3] == 'A' || c1[3] == 'B' || c1[3] == 'C')
	    	{
	    		if (c2[3] == 'A' || c2[3] == 'B' || c2[3] == 'C')
	    		{
	    			cout << "1";
	    			if (c1[3] == 'A' && c2[3] == 'B')
	    			{
	    				cout << "1";
					}
					else if (c1[3] == 'B' && c2[3] == 'C')
					{
						cout << "1";
					}
					else if (c1[3] == 'B' && c2[3] == 'A')
					{
						cout << "1";
					}
					else if (c1[3] == 'C' && c2[3] == 'B')
					{
						cout << "1";
					}
					else
					{
						cout << "0";
					}
				}
				else
				{
					cout << "00";
				}
			}
			else if (c1[3] == 'D' || c1[3] == 'E')
			{
				if (c2[3] == 'D' || c2[3] == 'E')
				{
					cout << "1";
					if (c1[3] == 'D' && c2[3] == 'E')
					{
						cout << "1";
					}
					else if (c1[3] == 'E' && c2[3] == 'D')
					{
						cout << "1";
					}
					else
					{
						cout << "0";
					}
				}
				else
			    {
				   	cout << "00";
			    }
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
