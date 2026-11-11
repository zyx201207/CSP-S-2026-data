#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
char c, str[N], str1[N];
int a;
bool flag = true;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int id = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> c;
		for(int j = 0; j < a; j++)
		{
			str[id + j] = c;
		}
		id += a;
	}
	for(int i = 0; i < strlen(str) + 1; i++)
	{
		str1[i] = str[strlen(str) - i];
	}
	int cnt = 0;
	for(int i = 0; i < strlen(str) + 1; i++)
	{
		if(str[i] != str1[i])
		{
			flag = false;
			cnt++;
		}
	}
	if(flag == true)
	{
		cout << 0;
	}
	else
	{
		cout << cnt / 2;
	}
	return 0;
}
