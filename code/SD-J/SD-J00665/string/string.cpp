#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	string s="";
	int n;
	cin >>n;
	for (int i=1;i<=n;i++)
	{
		long long a;
		char c;
		cin >>a>>c;
		for (int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	long long l=0;
	long long r=s.size()-1;
	long long cnt=0;
	while (l<=r)
	{
		if (s[l]==s[r])
		{
			l++;
			r--;
		}
		else
		{
			cnt++;
			l++;
			r--;
		}
	 } 
	cout <<cnt;
	return 0;
}
