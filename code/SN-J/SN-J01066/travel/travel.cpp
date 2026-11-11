#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int a,b;
	string c,d;
	cin >> a >> c >> b >> d;
	int c1=(c[0]-'0')+(c[1]-'0'),d1=(d[0]-'0')+(d[1]-'0');
	int c2=(c[2]-'A'),d2=(d[2]-'A');
	
	if(a!=b) cout << '0000';
	else 
	{
		cout << '1';
		if(c1!=d1) cout << '000';
		else
		{
			cout << '1';
			if((c2<=2 && d2<=2) || (c2>2 && d2>2))
			{
				cout << '1';
				if(abs(c2-d2) == 1) cout << '1';
				else cout << '0';
			}
			else cout << '00';
		}
	}
	return 0;
}
