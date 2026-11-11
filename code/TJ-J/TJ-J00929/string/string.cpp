#include <bits/stdc++.h>
using namespace std;

bool ish(string s)
{
	string ns;
	for(int i = s.size()-1;i>=0;i--)
	{
		ns += s[i];
	}
	if(ns == s) return 1;
	else return 0;
}
int n;
string s;
map <char,int> mp;;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w"stdout);
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		int num;
		string zs;
		cin >> num >> zs;
		for(int j = 1;j<=num;j++)
		{
			s += zs;
		}
	}
	if(ish(s)) cout << 0;
	
	
	return 0;
}
