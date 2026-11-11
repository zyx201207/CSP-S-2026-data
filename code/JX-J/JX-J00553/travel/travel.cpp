#include<iostream>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
char t;
int c1,c2,a1,b1,a2,b2;
int dy1[128],dy2[128];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//don't have worry in leter
	t = getchar();
	a1 += (t - '0') * 10;
	t = getchar();
	a1 += (t - '0');
	t = getchar();
	t = getchar();
	b1 += (t - '0') * 10;
	t = getchar();
	b1 += (t - '0');
	t = getchar();
	c1 = t;
	t = getchar();
	t = getchar();
	a2 += (t - '0') * 10;
	t = getchar();
	a2 += (t - '0');
	t = getchar();
	t = getchar();
	b2 += (t - '0') * 10;
	t = getchar();
	b2 += (t - '0');
	t = getchar();
	c2 = t;
	dy1['A'] = 1;
	dy1['B'] = 1;
	dy1['C'] = 1;
	dy1['D'] = 2;
	dy1['E'] = 2;
	if(a1 == a2)
	{
		cout << 1;
		if(b1 == b2)
		{
			cout << 1;
			if(dy1[c1] == dy1[c2])
			{
				cout << 1;
				if(c1 + c2 != 'A' + 'C') cout << 1;
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
