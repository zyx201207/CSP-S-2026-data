#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	bool check2 = true;
	if(s1 == s3) cout << 1;
	else 
	{
		check2 = false;
		cout << 0;	
	}
	
	bool check = true;
	for(int i = 0; i < s2.size() - 1; i ++)
		if(s2[i] != s4[i] || !check2)
		{
			check = false;
			cout << 0;
			break;
		}
	if(check && check2) cout << 1;
	
	char a = s2[2], b = s4[2];
	
	if(((a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C') || (a >= 'D' && a <= 'F' && b >= 'D' && b <= 'F')) && check && check2)
		cout << 1;
		
	else 
	{
		check = false;
		cout << 0;	
	}
	
	int c = a - 'A', d = b - 'A';
	if(abs(c - d) == 1 && check)
		cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
} 
