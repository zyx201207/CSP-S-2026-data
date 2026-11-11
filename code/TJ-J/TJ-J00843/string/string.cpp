#include <bits/stdc++.h>
using namespace std;
long long cnt;
const int maxn = 2e5+5;
struct node
{
	char a;
	int num;
}a[maxn];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].num >> a[i].a;
	}
	int l = 1,r = n;
	while(l < r)
	{
		if(a[l].a != a[r].a)
		{
			if(a[l].num != a[r].num)
				cnt += min(a[l].num,a[r].num);
			else
				cnt += a[l].num;
		}
		if(a[l].num > a[r].num)
		{
			a[l].num -= a[r].num;
			r--;
		}
		else if(a[l].num == a[r].num)
		{
			l++;
			r--;
		}
		else
		{
			a[r].num -= a[l].num;
			l++;
		}
	}
	cout << cnt;
    return 0;
}
