#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int a,b;
bool check(string e,string f)
{
	for(int i = 0;i <= 1;i++)
	{
		if(a = b)return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,x,y;
	cin >> c >> s >> x >> y;
	if(check(c,x))
	{
		cout << 1;
		if(check(s,y))
		{
			cout << 1;
			if((s[2] <= 'C' && y[2] <= 'C'))
			{
				cout << 1;
				if((s[2] == 'A' && y[2] == 'B') || (s[2] == 'B' && y[2] == 'A') || (s[2] == 'C' && y[2] == 'B'))
				{
					cout << 1;
				}
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
