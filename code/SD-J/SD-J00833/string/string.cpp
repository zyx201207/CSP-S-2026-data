#include <bits/stdc++.h>
using namespace std;
long long a[500010] , cnt;
char c[500010];
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);	
	long long n;
	cin >> n;
	string s = "";
	for(int i = 0; i < n; i++)
	{
		cin >> a[i] >> c[i];
		for(int j = 0; j < a[i]; j++)
		{
			s += c[i];
		}
	}
	string s2 = s;
	reverse(s.begin() , s.end());
	if(s2 == s)
	{
		cout << 0;
		return 0;
	}
	
	int mid = s2.size() / 2;
	if(s.size() % 2 == 0)
	{
		for(int i = 0 , j = 1; i < mid && j <= mid; i++ , j++)
		{
			if(s2[mid - i] != s2[mid + j])
			{
				cnt++;
			}
		}
	}
	else 
		for(int i = 0; i < mid; i++)
		{
			if(s2[mid - i - 1] != s2[mid + i])
			{
				cnt++;
			}
		}
	cout << cnt;
	return 0;
}
