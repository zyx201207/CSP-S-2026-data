#include<bits/stdc++.h>
using namespace std;
//const int N = 1e7 + 7;
string s,t;
char c;
int z,a,ans,temp;
bool prime(string x)
{
	int len = x.size();
	for(int i = len - 1; i >= 0; i--)
	{
		t += x[i];
	}
	if(t == x) return true;
	else return false;
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> a;
	temp = 0;
	for(int i = 1; i <= a; i++)
	{
		cin >> z >> c;
		for(int j = 1; j <= z; j++)
		{
			temp++;
			s += c;
		}
	}
	int len = s.size();
	int i = 0, j = len - 1;
	while(i < len / 2 && j > len / 2)
	{
		if(prime(s)) cout << ans;
		if(s[i] != s[j])
		{
			s[j] = s[i];
			ans++;
		}
		i++;
		j--;
	}
	return 0;
}