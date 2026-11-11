#include <bits/stdc++.h>
using namespace std;
int main()
{ 
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l,r;
	long long s,a,m = 0;
	string sum[1000000];
	string b;
	cin >> n;
	for(int i = 1;i <= n;i++) 
	{
		cin >> a >> b;
		s += a;
		for(long long j = 0;j < a;j++)
		{
			sum[j] = b;
		}
	}
	if(s % 2 == 0)
	{
		l = 0;
		r = s - 1;
		while(l != r && r - l != 1)
		{
			if(sum[l] == sum[r] )
			{
				m++;
			}
		}
	}
	cout << m;
	return 0;
}
