#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5+10;
int cy, ce;
int py, pe;
string wy, we;
string zy, ze;
string ans;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cy >> zy >> ce >> ze;
	py = (int)zy[0] * 10 + (int)zy[1];
	wy = zy[2];
	pe = (int)ze[0] * 10 + (int)ze[1];
	we = ze[2];
	if(cy != ce)
	{
		cout << "0000";
		return 0;
	}
	if(py != pe)
	{
		cout << "1000";
		return 0;
	}
	if(wy == "A" || wy == "B" || wy == "C")
	{
		if(we == "D" || we == "F")
		{
			cout << "1100";
			return 0;
		}
	}
	else if(wy == "D" || wy == "F")
	{
		if(we == "A" || we == "B" || we == "C")
		{
			cout << "1100";
			return 0;
		}
	}
	if(wy == "A" && we == "B") cout << "1111";
	else if(wy == "B" && we == "A") cout << "1111";
	else if(wy == "B" && we == "C") cout << "1111";
	else if(wy == "C" && we == "B") cout << "1111";
	else if(wy == "D" && we == "F") cout << "1111";
	else if(wy == "F" && we == "D") cout << "1111";
	else cout << "1110";
	return 0;
}
