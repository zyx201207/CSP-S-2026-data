#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c,s,cc,ss;
	cin >> c >> s >> cc >> ss;
	
	if(c!=cc)
	{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	else
	{
		cout << 1;
		if(s[0]-'0'==ss[0]-'0' && s[1]-'0'==ss[1]-'0')
		{
			cout << 1;
			if(s[2]=='A')
			{
				if(ss[2]!='B' && ss[2]!='C')
				{
					cout << 0 << 0;
					return 0;
				}
			}
			if(s[2]=='B')
			{
				if(ss[2]!='A' && ss[2]!='C')
				{
					cout << 0 << 0;
					return 0;
				}
			}
			if(s[2]=='C')
			{
				if(ss[2]!='B' && ss[2]!='A')
				{
					cout << 0 << 0;
					return 0;
				}
			}
			if(s[2]=='D')
			{
				if(ss[2]!='F')
				{
					cout << 0 << 0;
					return 0;
				}
			}
			if(s[2]=='F')
			{
				if(ss[2]!='D')
				{
					cout << 0 << 0;
					return 0;
				}
			}
			cout << 1;
			if(s[2]=='A')
			{
				if(ss[2]!='B')
				{
					cout << 0;
					return 0;
				}
			}
			if(s[2]=='B')
			{
				if(ss[2]!='A' || 'C')
				{
					cout << 0;
					return 0;
				}
			}
			if(s[2]=='C')
			{
				if(ss[2]!='B')
				{
					cout << 0;
					return 0;
				}
			}
			if(s[2]=='D')
			{
				if(ss[2]!='F')
				{
					cout << 0;
					return 0;
				}
			}
			if(s[2]=='F')
			{
				if(ss[2]!='D')
				{
					cout << 0;
					return 0;
				}
			}
			cout << 1;
		}
		
		else
		{
			cout << 0 << 0 << 0;
			return 0;
		}
		
	}

	return 0;
}
