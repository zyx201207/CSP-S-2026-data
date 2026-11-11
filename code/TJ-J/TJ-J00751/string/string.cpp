#include <bits/stdc++.h>
using namespace std;
struct two
{
	long long c;
	char d;
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,b;
	cin >> n;
	two m[200005];
	long long num = 0;
	for (int i=1;i<=n;i++)
	{
		cin >> m[i].c >> m[i].d;
	}
	int i=1,j=1;
	while(i+j<=n)
	{
		if (m[n-j+1].c < m[i].c)
		{
			if (m[i].d != m[n-j+1].d)
			{
				num += m[n-j+1].c;
				m[i].c -= m[n-j+1].c;
			}
			j++;
		}
		else if (m[i].c < m[n-j+1].c)
		{
			if (m[i].d != m[n-j+1].d)
			{
				num += m[i].c;
				m[n-j+1].c -= m[i].c;
			}
			i++;
		}
		else if (m[i].c == m[n-j+1].c)
		{
			if (m[i].d != m[n-j+1].d)
			{
				num += m[i].c;
			}
			i++;
			j++;
		}
	}
	cout << num;
	return 0;
}
