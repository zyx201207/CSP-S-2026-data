#include <bits/stdc++.h>
using namespace std;
int a[2005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
        cin >> a[i];
    if (n <= 2000 && m == n)
    {
    	int ans = a[0]&a[1];
    	for (int i = 2;i < n;i++)
    	{
    		ans&=a[i];
		}
		cout << ans;
	}
	else if(n <= 2000 && m == 1)
	{
		int ans=-1;
		for (int i = 0;i < n;i++)
    	{
    		ans = max(ans,a[i]);
		}
		cout << ans;
	}
	else if(n <= 2000 && m == 2)
	{
		int ans=-1;
		for (int i = 0;i < n;i++)
    	{
    		for (int j = i+1;i < n;i++)
    	    {
    	    	ans = max(ans,a[i]&a[j]);
		    }
		}
		cout << ans;
	}
	
	return 0;
}