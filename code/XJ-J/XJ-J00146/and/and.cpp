#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n , a[200005];
    for(int i=1;i<=n;i++)
    {
    	cin >> a[i];
    	if(a[1]==a[n])
    	{
    		cout << a[n];
		}
		if(a[i]>a[1] $$ a[i]<a[n])
		{
			cout << a[i];
		}
	}
	return 0;
}
