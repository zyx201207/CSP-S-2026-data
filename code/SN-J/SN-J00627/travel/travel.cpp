// 吴鑫桐 西安市爱知中学 SN-J00627 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s[1]  >> s[2]  >> s[3]  >> s[4];
	if(s[1]!=s[3])
	{
		cout << "0000";
	}
	else
	{
		cout << 1;
		ll x=ll(s[2][0]-'0');
		x=x*10+(s[2][1]-'0');
		ll y=ll(s[4][0]-'0');
		y=y*10+(s[4][1]-'0');
		if(x==y)
		{
			cout << 1;
			char a=s[2][2];
			char b=s[4][2];
			if(((a=='F' or b=='F') and (a=='D' or b=='D')) or ((a!='F' and b!='F') and (a!='D' and b!='D')))
			{
				cout << 1;
				if((char(a+1) == b and char(a+1)!='D') or (char(b+1) == a and char(b+1)!='D'))
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
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	return 0;
}
