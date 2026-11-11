#include<bits/stdc++.h>
using namespace std;
string a, b;
char x[5], y[5], m[5], n[5];
int p, q, e, d;
bool f1, f2, f3, f4;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> x >> y >> m >> n;
	d = 10 * (x[0] - '0') + (x[1] - '0'), e = 10 * (m[0] - '0') + (m[1] - '0');
	p = (y[1] - '0') + 10 * (y[0] - '0'), q = (n[1] - '0') + 10 * (n[0] - '0');
	if(y[2] == 'A')	a = "A";
	if(y[2] == 'B')	a = "B";
	if(y[2] == 'C')	a = "C";
	if(y[2] == 'D')	a = "D";
	if(y[2] == 'F')	a = "F";
	if(n[2] == 'A')	b = "A";
	if(n[2] == 'B')	b = "B";
	if(n[2] == 'C')	b = "C";
	if(n[2] == 'D')	b = "D";
	if(n[2] == 'F')	b = "F";
	
	if(d == e)	cout << 1, f1 = 1;
	if(d != e)	cout << 0;
	if(f1 && p == q)	cout << 1, f2 = 1;
	if(!f1 || p != q)	cout << 0;
	if(f1 && f2)
	{
		if(a >= "A" && a <= "C" && b >= "A" && b <= "C")	cout << 1;
		else if(a >= "D" && a <= "F" && b >= "D" && b <= "F")	cout << 1;
		else	cout << 0, f3 = 1;
	}
	if((!f1 || !f2) && !f3)	cout << 0;
	if(f1 && f2)
	{
		if((a == "A" || a == "B") && (b == "A" || b == "B")) cout << 1;
		else if((a == "B" || a == "C") && (b == "B" || b == "C")) cout << 1;
		else  if((a == "F" || a == "D") && (b == "F" || b == "D")) cout << 1;
		else	cout << 0, f4 = 1;
	}
	if((!f1 || !f2) && !f4)	cout << 0;
	//printf("\n%d %d %s %d %d %s", d, p, a, e, q, b);
	return 0;
}

//02B 01A
