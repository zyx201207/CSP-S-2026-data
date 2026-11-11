#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

struct Node
{
	string x , y;
};

Node a , b;

inline int check(string x , string y)
{
	string t_x = "";
	string t_y = "";
	
	t_x += x[0];
	t_y += y[0];
	
	t_x += x[1];
	t_y += y[1];
	
	if(t_x == t_y)
	{
		return 1;
	}
	
	return 0;
}

inline int check_2(string x , string y)
{
	char t_x = x[2];
	char t_y = y[2];
	
	if(t_x <= 'C')
	{
		return (t_y <= 'C');
	}
	
	return (t_y > 'C');
	
}

inline int check_3(string x , string y)
{
	char t_x = x[2];
	char t_y = y[2];
	
	if(t_x <= 'C')
	{
		return (abs( int(t_x) - int(t_y) ) == 1);
	}
	else
	{
		
		return (t_y > 'C');
	}
	
}

int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	
	cin >> a.x >> a.y >> b.x >> b.y;
	
	if(a.x == b.x)
	{
		cout << "1";
		if(check(a.y , b.y))
		{
			cout << "1";
			
			if(check_2(a.y , b.y))
			{
				cout << "1";
				if(check_3(a.y , b.y))
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
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
