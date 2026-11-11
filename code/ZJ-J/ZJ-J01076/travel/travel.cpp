#include<bits/stdc++.h>
using namespace std;
char a[10], b[10], c[10], d[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a + 1 >> b + 1 >> c + 1 >> d + 1;
	int A = (a[2] - '0') + (a[1] - '0') * 10;
	int C = (c[2] - '0') + (c[1] - '0') * 10;
	if(A == C)	cout << "1";
	else
	{
		cout << "0000";
		return 0;
	}
	int B = (b[2] - '0') + (b[1] - '0') * 10;
	int D = (d[2] - '0') + (d[1] - '0') * 10;
	if(B == D)	cout << "1";
	else
	{
		cout << "000" << endl;
		return 0;
	}
	if(b[3] <= 'C' && d[3] <= 'C')
	{
		if(b[3] == 'B' || d[3] == 'B')	cout << "11";
		else							cout << "10";
	}
	else if(b[3] >= 'D' && d[3] >= 'D')	cout << "11";
	else								cout << "00" << endl;
	return 0;
}