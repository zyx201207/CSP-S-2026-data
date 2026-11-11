#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4,s = "0000";
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 == s3)
	{
		if (s2[0] == s4[0] && s2[1] == s4[1])
	    {
	    	if (s2[2] <= 'C' && s2[2] >= 'A' && s4[2] <= 'C' && s4[2] >= 'A')
	    	{
	    		if (s2[2] == 'A')
	    		{
	    			if (s4[2] == 'B')
	    			{
	    				s[0] = '1';
	    				s[1] = '1';
	    				s[2] = '1';
	    				s[3] = '1';
					}
				}
				else if (s2[2] == 'B')
	    		{
	    			if (s4[2] == 'A' || s4[2] == 'C')
	    			{
	    				s[0] = '1';
	    				s[1] = '1';
	    				s[2] = '1';
	    				s[3] = '1';
					}
				}
				else if (s2[2] == 'C')
	    		{
	    			if (s4[2] == 'B')
	    			{
	    				s[0] = '1';
	    				s[1] = '1';
	    				s[2] = '1';
	    				s[3] = '1';
					}
				}
				else
				{
					s[0] = '1';
	    			s[1] = '1';
	    			s[2] = '1';
	    			s[3] = '0';
				}
			}
			else if(s2[2] <= 'F' && s2[2] >= 'D' && s4[2] <= 'F' && s4[2] >= 'D')
			{
				s[0] = '1';
				s[1] = '1';
				s[2] = '1';
				s[3] = '1';
			}
			else
			{
				s[0] = '1';
				s[1] = '1';
				s[2] = '0';
				s[3] = '0';
			}
	    }
	    else
	    {
		    s[0] = '1';
		    s[1] = '0';
		    s[2] = '0';
		    s[3] = '0';
	    }
	}
	else
	{
		s[0] = '0';
		s[1] = '0';
		s[2] = '0';
		s[3] = '0';
	}
	cout << s;
	return 0;
 } 
