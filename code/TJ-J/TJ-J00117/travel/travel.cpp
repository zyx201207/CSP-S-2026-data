#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool first = 0,second = 0,third = 0,fourth = 0;
	if (c1 == c2)
    {
        first = 1;
        if (s1[0] == s2[0] && s1[1] == s2[1])
        {
        	second = 1;
        	if (s1[2] == 'D' && s2[2] == 'F')
        	{
        		third = 1;
        		fourth = 1;
			}
			else if(s1[2] == 'F' && s2[2] == 'D')
			{
				third = 1;
				fourth = 1;
			}
			else if(s1[2] == 'A' && s2[2] == 'B')
			{
				third = 1;
				fourth = 1;
			}
			else if(s1[2] == 'B' && s2[2] == 'A')
			{
				third = 1; 
				fourth = 1;
			}
			else if(s1[2] == 'A' && s2[2] == 'C')
			{
				third = 1;
				fourth = 0;
			}
			else if(s1[2] == 'C' && s2[2] == 'A')
			{
				third = 1; 
				fourth = 0;
			}
			else if(s1[2] == 'B' && s2[2] == 'C')
			{
				third = 1; 
				fourth = 1;
			}
			else if(s1[2] == 'C' && s2[2] == 'B')
			{
				third = 1; 
				fourth = 1;
			}
			else
			{
				third = 0;
				fourth = 0;
			}
		}
		else
		{
			second = 0;
			third = 0;
			fourth= 0;
		}
	} 
	else
    {
    	first = 0;
    	second = 0;
    	third = 0;
    	fourth = 0;
	}
	
	cout << first << second << third << fourth;
	return 0;
}
