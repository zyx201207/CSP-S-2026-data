#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string num = "0000";
	if(c1[0]==c2[0] && c1[1] == c2[1])
	{
		num[0] = '1';
		if(s1[1] == s2[1])
		{
			num[1] = '1';
			if((s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'F'))
			{
				num[2] = '1';
				num[3] = '1';
			}
			if((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A'))
			{
			    num[2] = '1';
				num[3] = '1';
		    }
			if((s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B'))
			{
		        num[2] = '1';
				num[3] = '1';
		    }
			if((s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A'))
			{
			    num[2] = '1';
				num[3] = '0';
			}
			else
			{
			    num[2] = '0';
			    num[3] = '0';
			}
	    }
		else
	    {
	    	num[1] = '0';
	    }
	}
	cout << num;
	return 0;
}

