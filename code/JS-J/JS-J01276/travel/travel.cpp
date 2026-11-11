#include<bits/stdc++.h>
using namespace std;
using st = string;

char f(char s)
{
	if(s == 'F') return('E');
	else return(s);
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	st ra, rb, xa, xb;
	cin >> ra >> rb >> xa >> xb;
	
	if(ra == xa)
	{
		if(rb[0] == xb[0] && rb[1] == xb[1])
		{
			if((rb[2] <= 'C') == (xb[2] <= 'C'))
			{
				if(abs(f(rb[2]) - f(xb[2])) == 1) cout << "1111\n";
				else cout << "1110\n";
			}
			else cout << "1100\n";
		}
		else cout << "1000\n";
	}
	else cout << "0000\n";
	
	return(0);
}
