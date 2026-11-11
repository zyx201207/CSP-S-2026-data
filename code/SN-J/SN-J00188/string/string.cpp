#include<bits/stdc++.h>
using namespace std;

long long a[100005];
string s[100005];
string c[100005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int k = 1;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> s[i];
		for(int j = 1;j <= a[i];j++)
		{
			c[k] = s[i];
			k++;
		}
	}
	int j = 1;
	int cnt = 0;
	for(int i = n;i >= 1;i--)
	{
		if(c[i] != c[j]) cnt++;
		j++;
	}
	cout << cnt;
	return 0;
}
//2
//2 a
//3 a
