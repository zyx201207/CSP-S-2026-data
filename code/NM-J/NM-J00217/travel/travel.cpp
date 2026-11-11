#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag = 1,flags = 0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << 1;
		for(int i = 0;i < s1.size()-1;i++)
		{
			if(s1[i] != s2[i]) flag = 0;
		}
		if(flag)
		{
			cout << 1;
			char x = s1[2],y = s2[2];
			if((x == 'A'||x == 'B'||x == 'C')&&(y == 'A'||y == 'B'||y == 'C'))
			{
				flags = 1;
			}
			if((x == 'D'&&x == 'F')||(y == 'D'&&y == 'F'))
			{
				flags = 1;
			}
			if(flags) cout << 1;
			else cout << 0;
			if(x == 'C'&&y == 'D'||x == 'D'&&y == 'C')
			{
				cout << 0;
				return 0;
			}
			if((x-y == 1||y-x == 1))
			{
				cout << 1;
			}
			else if((x == 'D'&&y == 'F')||(x == 'F'&&y == 'D'))
			{
				cout << 1;
			}
			else cout << 0;
		}
		else cout << 0 << 0 << 0;
	}
	else cout << 0 << 0 << 0 << 0;
	
	
	
	
	return 0;
}
