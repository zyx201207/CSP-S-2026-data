#include <bits/stdc++.h>
using namespace std;
//struct StrP
//{
//	int num;
//	char c;
//	int p;
//}a[200005];

string str;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

//	int n, np = 0;
//	long long allN = 0;
//	cin >> n;
//	for(int i = 0; i < n; i++)
//	{
//		cin >> a[i].num >> a[i].c;
//		a[i].p = np;
//		allN += a[i].num;
//		np += a[i].num;
//	}
	
	int n, num, cnt = 0;
	char c;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> num >> c;
		for(int j = 0; j < num; j++)
			str.push_back(c);
	}
	for(int i = 0; i < str.length() / 2; i++)
	{
		if(str[i] != str[str.length() - 1 - i])
			cnt++;
	}
	cout << cnt;
	return 0;
}