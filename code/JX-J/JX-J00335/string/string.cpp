#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200005];
long long t[200005];
char c[200005];
long long cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		
	}
	
	int l = 1,r = n;
	
	while(l<=r)
	{
		if(c[l]!=c[r])
		{
			if(a[l] > a[r])
			{
				cnt += a[r];
				a[l] -= a[r];
				r--;
			}
			else if(a[l] < a[r])
			{
				cnt += a[l];
				a[r] -= a[l];
				l++;
			}
			else
			{
				cnt += a[l];
				l++;
				r--;
			}
		}
		else
		{
			if(a[l] > a[r])
			{
				a[l] -= a[r];
				r--;
			}
			else if(a[l] < a[r])
			{
				a[r] -= a[l];
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	cout << cnt;
	
	return 0;
}
