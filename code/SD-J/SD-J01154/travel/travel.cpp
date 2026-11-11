#include <bits/stdc++.h>
#define ll long long
#define TIE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	TIE
	bool t1 = true,t2 = true,t3 = true,t4 = true;
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) t1 = false;
	if (s1[0] != s2[0] || s1[1] != s2[1] || !t1) t2 = false;
	if (t2)
	{
		int a,b;
		if (s1[2] >= 'A' && s1[2] <= 'C') a = 1;
		else a = 2;
		if (s2[2] >= 'A' && s2[2] <= 'C') b = 1;
		else b = 2;
		if (a != b)
		{
			t3 = false;
		}
	}
	else t3 = false;
	if (t3)
	{
		if (abs(s1[2] - s2[2]) != 1)
		{
			t4 = false;
		}
	}
	else t4 = false;
	if (t1) cout << 1;
	else cout << 0;
	if (t2) cout << 1;
	else cout << 0;
	if (t3) cout << 1;
	else cout << 0;
	if (t4) cout << 1;
	else cout << 0;
	return 0;
} 
