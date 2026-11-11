#include <bits/stdc++.h>
#include <string>
using namespace std;

bool f(char x, char y)
{
	if((x>='A' && x<='C') && (y>='A' && y<='C'))
	{
		return 1;
	}
	else if((x>='D' && x<='F') && (y>='D' && y<='F'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	string a, b;
	char c, d;
	cin >> c1 >> s1 >> c2 >> s2;
	a=s1[0]+s1[1];
	b=s2[0]+s2[1];
	c=s1[2]; d=s2[2];
	if(c1 == c2)
	{
		cout << 1;
		if(a==b)
		{
			cout << 1;
			if(f(c, d)==1)
			{
				cout << 1;
				if((c==d+1) || (c==d-1))
				cout << 1;
				else{
					cout << 0;
				}
			}
			else{
				cout << 0 << 0;
			}
		}
		else{
			cout << 0 << 0 << 0;
		}
	}
	else{
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}
