#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout); 
	int n[10];
	string a , b , c , d;
	cin >> a >> c >> b >> d;
	if (a[0]==b[0] && a[1]==b[1])
	{
		n[0] = 1;
		if (c[0]==d[0] && c[1]==d[1])
	    {
		    n[1] = 1;
			if ((c[2]=='F'&&d[2]=='D')||(c[2]=='D'&&d[2]=='F'))
	    	{
				n[2] = 1;
				if (((c[2]=='A'&&d[2]=='B')||(c[2]=='B'&&d[2]=='C'))||(c[2]=='D'&&d[2]=='F'))
				{
					n[3]=1;
				}
				else if ((c[2]=='F'&&d[2]=='D')||((c[2]=='C'&&d[2]=='B')||(c[2]=='B'&&d[2]=='A')))
				{
					n[3]=1;
				}
				else
				{
					n[3]=0;
				}
			}
			else if ((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))
			{
				n[2] = 1;
				if (((c[2]=='A'&&d[2]=='B')||(c[2]=='B'&&d[2]=='C'))||(c[2]=='D'&&d[2]=='F'))
				{
					n[3]=1;
				}
				else if ((c[2]=='F'&&d[2]=='D')||((c[2]=='C'&&d[2]=='B')||(c[2]=='B'&&d[2]=='A')))
				{
					n[3]=1;
				}
				else
				{
					n[3]=0;
				}
			}
			else
			{
				n[2] = 0;
			}
		}
		else
		{
			n[1] = 0;
			n[2] = 0;
			n[3] = 0;
		}
	}
	else
	{
		n[0] = 0;
		n[1] = 0;
		n[2] = 0;
		n[3] = 0;
	}
	for (int i = 0;i <= 3;i++)
	{
		cout << n[i];
	}
}
