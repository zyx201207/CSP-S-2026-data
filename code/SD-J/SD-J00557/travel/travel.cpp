#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2)
	{
		cout << '1';
		
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			cout << '1';
			
			bool t1;
			if(s1[2]=='D' || s1[2]=='F')
				t1 = 1;
			else
				t1 = 0;
			
			bool t2;
			if(s2[2]=='D' || s2[2]=='F')
				t2 = 1;
			else
				t2 = 0;
			 
			if(t1 == t2)
			{
				cout << '1';
				
				if(s1[2]+1==s2[2] || s2[2]+1==s1[2])
					cout << '1';
				else
					cout << '0';
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
