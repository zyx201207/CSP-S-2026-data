#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1 == x2)
	{
		cout << 1;int i,cnt = 0;
		string a,b;
		for(i = 0;i < y1.size() - 1;i++)
		{
			if(y1[i] == y2[i])
			{
				cnt++;
			}
		}
		a = y1[2];
		b = y2[2];
		if(cnt == 2)
		{
			cout << 1;		
		}
		else
		{
			cout << 0;
		}
		int f = 0;
		if(cnt == 2)
		{
			if((a == "A" || a == "B" || a == "C") && (b == "A" || b == "B" || b == "C"))
			{
				cout << 1;
				f = 1;
			}
			else if((a == "D" || a == "F") && (b == "D" || b == "F"))
			{
				cout << 1;
				f = 1;
			}
			else
			{
				cout << 0;
			}
		}
		else 
		{
			cout << 0;
		}
		int x,y;
		x = y1[2] - '0';
		y = y2[2] - '0';
		if((x + 1 == y || x - 1 == y) && f == 1)
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
		cout << "0000";
	}
	return 0;
}
