#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n; cin >> n;
	string s;
	
	for(int i = 1; i <= n; i++)
	{
		int a; char c;
		cin >> a >> c;
		while(a--) s += c;
	}
	
	ll len = s.size(), cnt = 0;
	for(int i = 0; i <= len / 2 - 1; i++)
	{
		if(s[i] != s[len - i - 1]) cnt++;
	}
	
	cout << cnt << "\n";
	
	return(0);
}
