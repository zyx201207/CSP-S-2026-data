#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],ans;
char ch[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> ch[i];
	}
	int l = 1,r = n;
	while(l < r)
	{
		if(a[l] == 0)l++;
		if(a[l] < a[r])
		{
			if(ch[l] != ch[r])
			{
				ans += a[l];
			}
			a[r] -= a[l];
			a[l] = 0;
			l++;
		}
		else
		{
			if(ch[l] != ch[r])
			{
				ans += a[r];
			}
			a[l] -= a[r];
			a[r] = 0;
			r--;
		}
	}
	cout << ans;
	return 0;
}
