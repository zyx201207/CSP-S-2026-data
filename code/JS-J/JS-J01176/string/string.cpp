#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n, count = 0;
	cin >> n;
	long long a[n];
	string b[n];
	for (long long i = 0; i < n; ++i)cin >> a[i] >> b[i];
	string s = "";
	for (long long i = 0; i < n; ++i)
	{
		for (long long j = 0; j < a[i]; ++j)
		{
			s += b[i];
		}
	}
	cout << s << endl;
	long long lt = 0, rt = s.length()-1;

	for (long long i = 0; lt <= rt; ++i)
	{
		if (s[lt] != s[rt])
		{
			count ++ ;
		}
		lt++;
		rt--;
		cout << lt << rt << endl;
	}
	cout << count;
	return 0;
}