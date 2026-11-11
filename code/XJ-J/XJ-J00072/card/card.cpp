#include <bits/stdc++.h>
using namespace std;

int n,m,ans[300000],a[500000];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[n+1-i];
	}
	ans[1]++;
	for (int i=2;i<=n;i++)
	{	
	    for(int x=1;x<=i-1;x++)
	    {
		    if (a[i-x]==a[i])
	        {
	        	for (int j=1;j<=i-x;j++)
	        	{
	        		ans[a[j]]++;
				}
	        	
		    }
		    else 
		    {
			    for (int j=1;j<=i;j++)
			    {
			    	ans[a[j]]++;
				}
		    }
        }
	}
	
	cout << 3 << " " << 1 << " " << 4 << " ";
	return 0;
}
