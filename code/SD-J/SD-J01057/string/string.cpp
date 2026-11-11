#include<bits/stdc++.h>
using namespace std;

int n;
string s;
long long ans;
bool hw(string p)
{
	string k;
	for(int i = p.size() - 1; i >= 0; i--)
		k += p[i];
	if(k == p) return 1;
	else return 0;
}
string hhww(string p)
{
	string k;
	for(int i = p.size() - 1; i >= 0; i--)
		k += p[i];
	return k;
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		char y;
		cin >> x >> y;
		for(int i = 1; i <= x; i++)
			s += y;
	}
	if(hw(s))
	{
		cout << "0";
		return 0; 
	} 
	for(long long i = 0; i <= (s.size()-1) / 2; i++)
	{
		string ss = hhww(s);
		if(s[i] == ss[i]) continue;
		s[i] = ss[i];
		ans++;
		if(hw(s))
		{
			cout << ans;
			return 0; 
		} 
	}
	//cout << ans;
	
	return 0;
}//Trick||Treat!
