#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int n = s1[2],m = s2[2];
	if(c1==c2)
	{
		a[0] = 1;
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			a[1] = 1;
			if(55 <= n && n<=57 && 55 <= m && m<= 57||58 <= n && n<= 60 && 58 <=m && m<= 60)
			{
				a[2] = 1;
				if(abs(s1[2]-s2[2]) == 1)
				{
					a[3] = 1;
					
				}
				
			}
		
		}

	}
	for(int i = 0; i <= 3; i++)
	{
		if(a[i] == 1)
		{
			cout << 1 << endl;
		}
		else if(a[i] != 1)
		{
			cout << 0 << endl;
		}
	}

	
	
	return 0;
}
