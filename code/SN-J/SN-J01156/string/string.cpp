#include<bits/stdc++.h>
using namespace std;
string s;
long long you;
long long leng;
long long n;
char k;
long long num;
long long ans;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	for(long long i = 0;i < n;i ++)
	{
		cin>>num>>k;
		leng += num;
		for(long long j = 0;j < num;you ++, j ++)
		{
			s[you] = k;
		}
	}
	leng --;
	leng /= 2;
	for(long long i = 0;i < leng;i ++)
	{
		if(s[leng - i] != s[i]) ans ++;
	}
	cout<<ans;
	return 0;
}
