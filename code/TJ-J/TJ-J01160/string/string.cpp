#include <bits/stdc++.h>
using namespace std;
long long n,sum;
long long mid,ans;
string s;
long long a[200005],c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cin >> c[i];
	}
	if(n == 1)
	{
		for(int i = 1;i <= a[1];i++)
		{
			cout << c[1];
		}
	}
	return 0;
} 
