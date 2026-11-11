#include <bits/stdc++.h>
using namespace std;
int c_1, c_2;
string s_1, s_2;
bool is3(char a, char b)
{
	if(a > b) swap(a, b);
	//cout << (a <= 'C' && b >= 'D') << endl;
	return !(a <= 'C' && b >= 'D');
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c_1 >> s_1;
	cin >> c_2 >> s_2;
	string zwx, zwr;
	zwx += s_1[0] + s_1[1]; 
	zwr += s_2[0] + s_2[1]; 
	//cout << zwx << ""
	cout << (c_1 == c_2) << ((c_1 == c_2) && (zwx == zwr)) << ((c_1 == c_2) && (zwx == zwr) && is3(s_1[2], s_2[2])) 
	<< ((c_1 == c_2) && (zwx == zwr) && is3(s_1[2], s_2[2]) && abs((int)(s_1[2] - s_2[2])) == 1);
	return 0;
}
