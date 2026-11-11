#include <bits/stdc++.h>
using namespace std;
int n;
long long cnt = 0;
long long ans;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n--)
	{
		char a; int b;
		cin >> b >> a;
		cnt+=b;
		while(b--)
		{
			s+=a;
		}
	}
	for(int i = 0; i <= cnt/2; i++)
	{
		if(s[i]!=s[cnt-i-1])
		{
			s[i] = s[cnt-i-1];
			ans++;
		}
	}
	cout << ans;
	return 0;
}
