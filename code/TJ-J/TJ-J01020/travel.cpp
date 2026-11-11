#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2, s2;
int main()
{
	freopen("travel.in","r",std);
	freopen("travel.out","w",std);
	cin >> c1 >> s1 >> c2 >> s2;
	int t=0;
	if(c1==c2)
	{
		t+=1000;
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			t+=100;
		}
		else
		{
			cout << t;
			return 0;
		}
		if(s1[2]<='C' && s2[2]<='C')
		{
			t+=10;
			if(s1[2]-s2[2]==1 || s1[2]-s1[2]==1)
			{
				t+=1;
			}
		}
		else if(s1[2]>='D' && s2[2]>='D')
		{
			t+=10;
			t+=1;
		}
		else
		{
			cout << t;
			return 0;
		}
	}
	else
	{
		cout << '0000';
		return 0;
	}
	fclose("travel.in");
	fclose("travel.out");
}
