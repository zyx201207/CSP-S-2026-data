#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long m;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	if(n == 2)
	{
		if(c[2] == c[1]) cout << 0;
		else cout << min(a[1],a[2]);
		return 0;
	}
	int i = 1,j = n;
	while(i < j)
	{
		int x1 = a[i],x2 = a[j];//x1表示左边剩余的该字符数；x2表示右边剩余的该字符数。 
		if(x1 == x2)
		{
			if(c[i] != c[j]) m += x1;
			i++;
			j--;
		}
		if(x1 > x2)
		{
			if(c[i] != c[j]) m += x2;
			j--;
			a[i] -= x2;
		}
		if(x1 < x2)
		{
			if(c[i] != c[j]) m += x1;
			i++;
			a[j] -= x1;
		}
	}
	cout << m;
	return 0;
}
