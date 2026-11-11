#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int n1, n2;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin>>c1>>s1>>c2>>s2;
    switch(s1[2])
    {
		case 'A': n1=1; break;
		case 'B': n1=2; break;
		case 'C': n1=3; break;
		case 'D': n1=4; break;
		case 'E': n1=5; break;
	}
    switch(s2[2])
    {
		case 'A': n2=1; break;
		case 'B': n2=2; break;
		case 'C': n2=3; break;
		case 'D': n2=4; break;
		case 'E': n2=5; break;
	}
    if(c1==c2)
    {
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			if((n1<=3 && n2<=3)||(n1>=4 && n2>=4))
			{
				if(abs(n1-n2)==1)
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
			else
			{
				cout<<"1100";
			}
		}
		else
		{
			cout<<"1000";
		}
	}
	else
	{
		cout<<"0000";
	}
    return 0;
}
