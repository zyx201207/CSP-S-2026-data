#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string s,ss;
	cin >> n >> s >> m >> ss;
	if(n==m)
	{
		cout << 1;
		int x=(s[0]-'0')*10+(s[1]-'0'),y=(ss[0]-'0')*10+(ss[1]-'0');
		if(x==y)
		{
			cout << 1;
			if(((s[2]>='D')&&(ss[2]>='D'))||((s[2]<='C')&&(ss[2]<='C')))
			{
				cout << 1;
				if(int(s[2])+1==int(ss[2])||int(s[2])-1==int(s[2]))
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
	else
	{
		cout << "0000";
	}
	return 0;
}
