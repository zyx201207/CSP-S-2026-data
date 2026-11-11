#include<bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
bool f1 = 0, f2 = 0, f3 = 0;
int a[6];
int main() 
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a[s1[2]-'A']++;
	a[s2[2]-'A']++;
	a[4] = a[5];
	if(c1 == c2)
	{
		cout << 1;
		f1 = 1;
	}	
	else
	{
		cout << 0;
	}
	
	int cc = 0, ss = 0;
	for(int i = 0; i <= 1; i++)
	{
		cc = cc*10 + s1[i];
		ss = ss*10 + s2[i];
	}
	if(cc == ss && f1 == 1)
	{
		cout << 1;
		f2 = 1;
	}	
	else
	{
		cout << 0;
	}
	
	if(((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F')) && f1 == 1 && f2 == 1)       
	{
		cout << 1;
		f3 = 1;
	}
	else
	{
		cout << 0;
	}
	
	int t = 0;
	for(int i = 0; i <= 3; i++)
	{
		if(a[i] >= 1 && a[i+1] >= 1)
		{
			t = 1;
		}
	}
	if(t == 1 && f3 == 1)	cout << 1;
	else	cout << 0;
	return 0;
}
