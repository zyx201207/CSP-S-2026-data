#include <bits/stdc++.h>
using namespace std;
char c1,c2,s1,s2,s3,c3,c4,s4,s5,s6;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1>>c2>>s1>>s2>>s3>>c3>>c4>>s4>>s5>>s6;
	if(c1 == c3 && c2 == c4)
	{
		cout << 1 << " ";
		if(s1 == s4 && s2 == s5)
		{
			cout << 1 << " ";
			if(s3 == 'D' || s6 == 'F')
			{
				if(s3 == 'D' || s6 == 'F')
				{
					cout << 1 << " " << 1;
				}
				else
				{
					cout << 0 << " "<< 0;
					return 0;
				}
			}
			else
			{
				if(s6 != 'D' && s3 != 'E')
				{
					if(s6 != 'D' && s3 != 'F')
					{
						cout << 1 << " ";
						if(s6 - s3 == 1 || s6 - s3 == -1)
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
						cout << 0 << " "<< 0;
					}
				}
				else
					{
						cout << 0 << " "<< 0;
					}
			}
		}
		else
		{
			cout << 0 << " "<< 0 << " "<< 0;
			
		}
	}
	else
	{
		cout << 0 << " "<< 0 << " "<< 0 << " "<< 0;
	}
}
