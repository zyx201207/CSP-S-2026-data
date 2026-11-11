//wangyichitongchuanshidierzhongxueSN-J00668
#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s1, s2, s3, s4;
bool f1 = 1;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 == s3) cout << 1;
	else
	{
		cout << 0 << 0 << 0 << 0; 
		return 0;
	}
	for (int i = 0; i < 3 - 1; i++)
		if (s2[i] == s4[i]) continue;
		else f1 = 0;
	if (f1)
	{
		cout << 1;
		if (s2[2] <= 'C' && s4[2] <= 'C' || s2[2] > 'C' && s4[2] > 'C') 
		{	
			cout << 1;
			int r = (int)(s2[2]), j = (int)(s4[2]);
			if (abs(r - j) == 1) cout << 1;
			else cout << 0;  
		}
		else cout << 0 << 0;	
	}
	else cout << 0 << 0 << 0;
	return 0;
}
