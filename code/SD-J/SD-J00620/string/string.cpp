
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,i,j,a,L = 0;
	cin >> n;
	char c;
	string s = "";
	while(n--)
	{
		cin >> a >> c;
		for(i = 1;i <= a;i++)
		{
			s = s + c;
		}
		L += a;
	}
	long long cnt = 0;
	for(i = 0;i < L;i++)
	{
		if(s[i] != s[L - i - 1])
		{
			cnt++;
//			cout << s[i] << " " << s[L - i - 1] << " " << i << endl;
			s[i] = s[L - i - 1];
		}
	}
	cout << cnt;
	return 0;
} 
