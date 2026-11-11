#include <bits/stdc++.h>
using namespace std;

string answer;
string a,b;
string r,x;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;;
	if(c1 == c2)
	{
		answer += "1";
		for(int i = 0;i < 2;i++)
		{
			r += s1[i];
		}
		for(int i = 0;i < 2;i++)
		{
			x += s2[i];
		}
		if(x == r)
		{
			answer += "1";
			a = s1[2];
			b = s2[2];
		 	if(a >= "D" && a <= "F" && b >= "D" && b <= "F")
			{
				answer += "1";
				int xn = s1[2];
				int rn = s2[2];
				if(abs(xn - rn) == 1)
				{
					answer += "1";
				}
				else
				{
					cout << "1110";
					return 0;
				}
			}
			else if(a >= "A" && a <= "C" && b >= "A" && b <= "C")
			{
				answer += "1";
				int xn = s1[2];
				int rn = s2[2];
				if(abs(xn - rn) == 1)
				{
					answer += "1";
				}
				else
				{
					cout << "1110";
					return 0;
				}
			}
			else
			{
				cout << "1100";
				return 0;
			}	
		}
		else
		{
			cout << "1000";
			return 0;
		}
	}
	else
	{
		cout << "0000";
		return 0;
	}
	cout << answer;
	return 0;
}
