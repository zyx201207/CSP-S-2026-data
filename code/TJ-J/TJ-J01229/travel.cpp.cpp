#include<bits/stdc++.h>
using namespace std;
int main(){


	int c1,s1,c2,s2;
	int a[1],a[2],a[3],a[4];
	cin >> c >> s;
	if(c <= 1 || c >= 16) return 0;
	for (int c1 = n,c2 = m)
	{
		if (n = m)
		{
			a[1] = 1;
		}
		else
		{
			a[1] = 0;
		}
		for (int s1 = a1a2a3,s2 = b1b2b3)
		{
			if (a1a2 = b1b2)
			{
				a[2] = 1;
			}
			else
			{
				a[2] = 0;
			}
			if (a1a2 = b1b2 && (a3 = 'A' || a3 = 'B' ||a3 = 'C' ||a3 = 'D' || a3 = 'F')&&(b3 = 'A' || b3 = 'B' || b3 = 'C' || b3 = 'D' || b3 = 'F'))
			{
				a[3] = 1;
			}
			else
			{
				a[3] = 0;
			}
			if (a1a2 = b1b2 && (a3 = 'A' && b3 = 'B')||(a3 = 'B' &&b3 = 'C')||(a3 = 'D' && b3 = 'F'))
			{
				a[4] = 1;
			}
			else
			{
				a[4] = 0;
			}
		}
	}
	cout << a[1] << a[2] << a[3] << a[4];
	return 0; 

}

