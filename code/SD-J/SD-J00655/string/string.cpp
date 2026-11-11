#include<bits/stdc++.h>
using namespace std;
const int MX = 2e5;
long long x,b[MX + 10];
char c,d[MX + 10];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,i,j,f = 1;
	long long s = 0;
	cin >> n;
	for(i = 1;i <= n;i++)
	{
		cin >> x >> c;
		if(c == d[f])
		{
			b[f] += x;
		}
		else
		{
			f++;
			d[f] = c;
			b[f] = x;
		}
	}
	n = f;
	for(i = 1,j = n;i != j;i++,j--)
	{
		if(d[i] != d[j])
		{
			if(b[i] < b[j])
			{
				s += b[i];
				b[j] -= b[i];
				j++;
			}
			else if(b[i] > b[j])
			{
				s += b[j];
				b[i] -= b[j];
				i--;
			}
			else
			{
				s += b[i];
				b[i] = b[j] = 0;
			}
		}
		else
		{
			if(b[i] < b[j])
			{
				b[j] -= b[i];
				j++;
			}
			else if(b[i] > b[j])
			{
				b[i] -= b[j];
				i--;
			}
			else
			{
				b[i] = b[j] = 0;
			}
		}
	}
	cout << s << '\n';
	return 0;
}
