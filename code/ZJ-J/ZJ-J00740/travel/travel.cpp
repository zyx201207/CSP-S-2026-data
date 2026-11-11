#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c,C;
	string s,S;
	cin >> c >> s >> C >> S;
	if (c==C) 
	{
		cout << "1";
		if (s[0]==S[0]&&s[1]==S[1]) 
		{
			cout << "1";
			if (s[2]=='D'||s[2]=='F') 
			{
				if (S[2]=='D'||S[2]=='F') 
				{
					cout << "11";
				}
				else
				{
					cout << "00";
				}
			}
			else
			{
				if (S[2]=='A'||S[2]=='B'||S[2]=='C') 
				{
					cout << "1";
					if(int(s[2])-int(S[2])==1||int(S[2])-int(s[2])==1)
					{
						cout << "1";
					}
					else
					{
						cout << "0";
					}
				}
				else
				{
					cout << "00";
				}
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	cout << endl;
	return 0;
 } 
