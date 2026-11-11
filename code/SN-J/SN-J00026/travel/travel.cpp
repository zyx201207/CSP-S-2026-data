#include <bits/stdc++.h> 
using namespace std;

string c1, s1, c2, s2;
string ans1, ans2;
char cnt1, cnt2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i=0;i<=1;i++)
	{
		ans1 += s1[i];
		ans2 += s2[i];
	}
	cnt1 = s1[2];
	cnt2 = s2[2];

	if(c1 == c2)
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	
	if(ans1 == ans2)
	{
		cout << 1;	
	}
	else
	{
		cout << 0;
	}
	
	if(ans1 == ans2 && ((cnt1 >= 'A' && cnt1 <= 'C') && (cnt2 >= 'A' && cnt2 <= 'C')) || ((cnt1 == 'D' || cnt1 == 'F') && (cnt2 == 'D' || cnt2 == 'F')))
	{
		cout << 1;	
	}
	else
	{
		cout << 0;
	}
		
	if(((char(cnt1 + 1) == cnt2) && cnt1 != 'C') || ((cnt1 == 'D' || cnt1 == 'F') && (cnt2 == 'D' || cnt2 == 'F')))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}

	return 0;
} 
