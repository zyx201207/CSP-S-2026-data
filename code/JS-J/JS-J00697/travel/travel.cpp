#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 0;
	string rt,xt,rs,xs;
	cin >> rt >> rs >> xt >> xs;
	if(rt == xt)
	{
		n += 1000;
		if((rs[0] == xs[0]) && (rs[1] == xs[1]))
		{
			n += 100;
			if((rs[2] <= 67) && (xs[2] <= 67))
			{
				n += 10;
				if((rs[2] == 66) && (xs[2] == 66))
				{
					n += 1;
				}
			}
			if((rs[2] > 67) && (xs[2] > 67))
			{
				n += 11;
			}
		}
	}
	if(n > 0)
	{
		cout << n;
		return 0;
	}
	cout << "0000";
	return 0;
}
