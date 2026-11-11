#include<bits/stdc++.h>
using namespace std;

long long int n,m,a[200005],i,j,_and,maxn = INT_MIN,dig;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(i = 0;i < n;i++) cin >> a[i];
	for(i = 0;i < (1 << n);i++)
	{
		_and = -1;
		dig = 0;
		for(j = 0;j < n;j++)
		{
			if(i & (1 << j))
			{
				if(_and == -1) _and = a[j];
				else _and = (_and & a[j]);
				dig++;
			}
		}
		if(_and > maxn && dig == m) maxn = _and;
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
