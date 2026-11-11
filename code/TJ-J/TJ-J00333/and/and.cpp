#include <bits/stdc++.h>
using namespace std;
long long n,m,s,maxa;
long long a[200005];
bool sp1 = true;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m >> a[0];
    s = a[0];
    for(int i = 1;i < n;i++)
    {
    	cin >> a[i];
    	s &= a[i];
    	maxa = max(maxa,a[i]);
    	if(a[i] >= 4) sp1 = false;
	}
	if(m == 1)
	{
		cout << maxa;
		return 0;
	}
	if(m == n)
	{
		cout << s;
		return 0;
	}
	if(sp1)
	{
		sort(a,a + n);
		reverse(a,a + n);
		for(int i = 3;i > 0;i--)
		{
			int st = 0,p = 0;
			while(st < m)
			{
				if(a[p] == i) st++;
				else if(i == 1 && a[p] == 3)st++;
				p++;
			}
			if(st >= m)
			{
				cout << i;
				return 0;
			}
		}
		cout << 0;
	}
    return 0;
}
