#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n,a,cnt;
char c;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a >> c;
		while(a--) s += c;
	}
	for(int i = 0,j = s.size() - 1;i <= j;i++,j--)
	{
		if(s[i] != s[j]) cnt++;
	}
	cout << cnt;
	return 0;
}

