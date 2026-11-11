#include<bits/stdc++.h>
using namespace std;
int a, b, e, f;
string c, d;
int main()
{
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> a >> b >> c >> e >> f >> d;
	if (a == e)
		cout << 1;
	else
	{
		cout << "0000";
		return 0;
	}
	if (b == f)
		cout << 1;
	else
		cout << 0;
	if (b == f && (c <= "C" && d <= "C" || c >= "D" && d >= "D"))
		cout << 1;
	else
		cout << 0;
	if (c == "A" && d == "B" || c == "B" && d == "C" || c == "D" && d == "F")
		cout << 1;
	else
		cout << 0;
	return 0;
}
