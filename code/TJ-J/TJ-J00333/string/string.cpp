#include <bits/stdc++.h>
using namespace std;
struct paragraph
{
	long long le;
	char c;
};
paragraph ps[200005];
int n,l,r;
long long res;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    l = 0,r = n - 1;
    for(int i = 0;i < n;i++)
    {
    	cin >> ps[i].le >> ps[i].c;
	}
	while(l < r)
	{
		if(ps[l].c != ps[r].c)
		{
			res += min(ps[l].le,ps[r].le);
		}
		if(ps[l].le < ps[r].le)
		{
			ps[r].le -= ps[l].le;
			l++;
		}
		else if(ps[l].le > ps[r].le)
		{
			ps[l].le -= ps[r].le;
			r--;
		}
		else
		{
			l++;
			r--;
		}
	}
	cout << res;
    return 0;
}
