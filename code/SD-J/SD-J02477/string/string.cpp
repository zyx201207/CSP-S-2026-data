#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long m = 0;
	string s;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		long long a;
		string b;
		cin >> a >> b;
		for(long long i = 1;i <= a;i++)
		{
			s += b;
		}
	}
	for(long long i = 0;i < s.length() / 2;i++)
	{
		if(s[i] != s[s.length() - i - 1])
		{
			m++;
		}
	}
	cout << m;
	fclose(stdin);
	fclose(stdout);
	return 0; 
 } 
 
 
 
 
 
 
 
 
 
