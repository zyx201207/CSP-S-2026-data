#include <bits/stdc++.h>
using namespace std;
struct node
{
	int car;
	int line;
	char seat;
}a[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a[1].car >> a[1].line >> a[1].seat;
	cin >> a[2].car >> a[2].line >> a[2].seat;
	/*car*/
	if(a[1].car==a[2].car)
	{
		cout << "1";
		/*line*/
		if(a[1].line==a[2].line)
		{
			cout << "1";
			/*side*/
			if('A'<=a[1].seat&&'C'>=a[1].seat&&'A'<=a[2].seat&&'C'>=a[2].seat)
			{
				/*abc*/
				cout << "1";
				if(a[1].seat-a[2].seat==1||a[2].seat-a[1].seat==1)
				{
					cout << "1";
				}
				else
				{
					cout << "0";
				}
			}
			else if('D'<=a[1].seat&&'F'>=a[1].seat&&'D'<=a[2].seat&&'F'>=a[2].seat)
			{
				/*df*/
				cout << "11";
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
