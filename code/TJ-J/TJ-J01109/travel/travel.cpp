#include <bits/stdc++.h>
using namespace std;
int c1,a[3],c2,b[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> a[3] >> c2 >> b[3];
	if(c1=c2)
		cout << '1';
	else
		cout << '0000';
		return 0;
	if(a[1] == b[1]&&a[2] == b[2])
		cout << '1';
	else
		cout << '000';
		return 0;
	if(a[3]=='A'&&b[3]=='B'||a[3]=='A'&&a[3]=='C'||a[3]=='B'&&b[3]=='C'||a[3]=='D'&&b[3]=='F'||a[3]=='B'&&b[3]=='A'||a[3]=='C'&&b[3]=='B'||a[3]=='C'&&b[3]=='A'||a[3]=='F'&&b[3]=='D')
		cout << '1';
		else 
			cout << '00';
			return 0;
	if(a[3]=='A'&&b[3]=='B'||a[3]=='B'&&b[3]=='C'||a[3]=='D'&&b[3]=='F'||a[3]=='B'&&b[3]=='A'||a[3]=='C'&&b[3]=='B'||a[3]=='F'&&b[3]=='D')
		cout << '1';
	else
		cout << '0';
		return 0;
	}
}
