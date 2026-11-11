#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)
	{
		cout << 1;
		bool flag = 1;
		for(int i = 0; i <= 1; i++)
		{
			if(s1[i]!=s2[i])    flag = 0;
		}
		if(flag)
		{
			cout << 1;
			bool side1 = 0,side2 = 0;
			if(s1[2]=='D' || s1[2]=='F')    side1 = 1;
			if(s2[2]=='D' || s2[2]=='F')    side2 = 1;
			if(side1==side2)
			{
				cout << 1;
				if(abs((s1[2]-'A')-(s2[2]-'A'))==1)    cout << 1;
				else    cout << 0;
			}
			else    cout << 0 << 0;
		}    
		else    cout << 0 << 0 << 0;
	}
	else    cout << 0 << 0 << 0 << 0;
	return 0;
}
