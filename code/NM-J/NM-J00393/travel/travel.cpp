#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int ans[100];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << 1;
		string a,b;
		a += s1[0];
		a += s1[1];
		b += s2[0];
		b += s2[1];
		if(a == b)
		{
			cout << 1;
	
			int x = s1[2];
			int y = s2[2];
			ans[x] = 1;
			ans[y] = 1;
			int flag = 0;
			for(int i = 65;i <= 67;i++)
			{
				if(ans[i] == 1)
					flag++;
			}
			if(flag == 0 || flag == 2)
			{
				cout << 1;
				if(flag == 0)
				{
					cout << 1;
				}
				else
				{ 
					if(abs(x - y) == 1)
						cout << 1;
					else
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
