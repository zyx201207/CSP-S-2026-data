// ¹Ø×¢482ß÷,¹Ø×¢482Ð»Ð»ß÷~! 
#include <bits/stdc++.h>
using namespace std;
int c1, c2, r1, r2;
char s1, s2;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
    scanf("%d %d%c %d %d%c", &c1, &r1, &s1, &c2, &r2, &s2);
    if (c1 == c2)
    {
    	cout << 1;
    	if (r1 == r2)
    	{
    		cout << 1;
    		if ((s1 <= 'C' && s2 <= 'C') || (s1 >= 'D' && s2 >= 'D'))
    		{
    			cout << 1;
    			if (abs(s2 - s1) == 1)
    			{
    				cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
			else
			{
				cout << 0 << 0;
			}
		}
		else
		{
			cout << 0 << 0 << 0;
		}
	}
	else
	{
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}
