#include <bits/stdc++.h>
using namespace std;
string c1 , s1 , c2 , s2;
int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	int cnt = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
		cout << 1;
	else
		cout << 0;

//di yi duan
	if(c1 == c2)
	{
		for(int i = 0 ; i < s1.length()-1 ; i++)
		{
			for(int j = 0 ; j < s2.length() - 1 ; j++)
			{
				if(s1[i] == s2[j] )
				{
					cnt ++;
				}
			}
		}	
		if(cnt == 2)
			cout << 1;
		else
			cout << 0;
		
//di er duan
		int k = 0;
		for(int i = 0 ; i < s1.length()-1 ; i++)
		{
			for(int j = 0 ; j < s2.length() - 1 ; j++)
			{
				if(s1[i] == s2[j] )
				{
					k ++;
				}
			}
		}
		if( k== 2)
		{
			if(s1[2] <= 'C' &&  s2[2] <= 'C' ||  s1[2] == 'D' &&  s2[2] == 'F' || s1[2] == 'F' &&  s2[2] == 'D')
				cout << 1;
			else
				cout << 0;
		
		}
		else
			cout << 0;
//di san duan
// yi xia wei di si duan
		int y = 0;
		for(int i = 0 ; i < s1.length()-1 ; i++)
		{
			for(int j = 0 ; j < s2.length() - 1 ; j++)
			{
				if(s1[i] == s2[j] )
				{
					y ++;
				}
			}
		}
		if( y == 2)
		{
			if(s1[2] <= 'C' &&  s2[2] < 'C')
			{
				if(s1[2] - s2[2] == -1 || s1[2] - s2[2] == 1)
				{
					cout << 1;
					return 0;
				}
				else
				{
					cout << 0;
					return 0;	
				}
			}
		}
		else
		{
			cout << 0;
			return 0;
		}
//
		int x = 0;
		for(int i = 0 ; i < s1.length()-1 ; i++)
		{
			for(int j = 0 ; j < s2.length() - 1 ; j++)
			{
				if(s1[i] == s2[j] )
				{
					x ++;
				}
			}
		}
		if( x == 2)
		{
			if( s1[2] == 'D' &&  s2[2] == 'F' )
			{
				if(s1[2] - s2[2] == -2 )
				{
					cout << 1;
					return 0;
				}
				else
				{
					cout << 0;
					return 0;
				}
			}
		}
		else
		{
			cout << 0;
			return 0;
		}

//	

		int z = 0;
		for(int i = 0 ; i < s1.length()-1 ; i++)
		{
			for(int j = 0 ; j < s2.length() - 1 ; j++)
			{
				if(s1[i] == s2[j] )
				{
					z ++;
				}
			}
		}
		if( z == 2)
		{
			if( s1[2] == 'F' &&  s2[2] == 'D')
			{
				if(s1[2] - s2[2] == 2)
				{
					cout << 1;
					return 0;
				}
				else
				{
					cout << 0;
					return 0;
				}
			}
		}
		else
		{
			cout << 0;
			return 0;
		}
//
		int t =0;
		for(int i = 0 ; i < s1.length()-1 ; i++)
		{
			for(int j = 0 ; j < s2.length() - 1 ; j++)
			{
				if(s1[i] == s2[j] )
				{
					t ++;
				}
			}
		}	
		if(t == 2)
		{
			if(s1[2] <= 'C' && s2[2] >= 'D')
				cout << 0;
		}
	}
	else
	cout << 0 << 0 << 0;

	return 0;
}
