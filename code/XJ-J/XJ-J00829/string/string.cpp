#include <bits/stdc++.h>
using namespace std;
long long e , l , cnt;
string s;
long long n[1000000010];
string m[200010];
bool huiwen(int e)
{
	for(int i = 0 ; i <= e ; i++)
	{
		if(m[i] == m[e-i])
		{
			if(n[i] == n[e-i])
			{
				cnt++;
			}
		}
	}
	if(cnt == e)
	{
		return true;
	}
};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int sum = 0;
	cin >> e;
	for(int i = 0 ; i < e ; i++)
	{
		cin >> l;
		cin >> s;
		n[i] == l;
		m[i] == s;
	}
	for(int i = 0 ; i < e ; i++)
	{
		if(huiwen(i))
		{
			cout << sum;
		}
		else
		{
			if(m[i] == m[e-i])
			{
				int g = n[i] - n[e-i];
				sum += g;
			}
			else
			{
				int g = n[i];
				sum += g;
			}
		}
	}
	return 0;
}