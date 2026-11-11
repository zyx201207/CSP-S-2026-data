#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string str;
	for(int i = 1;i <= n;i++)
	{
		int y;
		char c;
		cin >> y;
		cin >> c;
		for(int j = 1;j <= y;j++)
		{
			str += c;
		}
	}
	string s1 = str;
	reverse(str.begin(),str.end());
	if(str == s1)
		cout << 0;
 } 
