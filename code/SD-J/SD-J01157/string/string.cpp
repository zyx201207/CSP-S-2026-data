#include<bits/stdc++.h>
using namespace std;
long long ans,n;
string s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n--)
	{
		long long x;
		string s2;
		cin >> x >> s2;
		while(x--)s += s2;
	}
	long long l = s.size();
	for(int i = 0;i < l/2;i++)
	{
		if(s[i] != s[l-i-1])ans++;
	}
	cout << ans;
	return 0;
 } 
