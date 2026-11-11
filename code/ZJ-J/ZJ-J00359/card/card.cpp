#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], numa[500005], numb[500005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int k = 1; k <= n; k++)
	{
		memset(numa, 0, sizeof(numa));
		for(int i = k; i <= n; i++)
	    {
		    numa[a[i]]++;
    		numb[a[i]]++;
	     	if(numa[a[i]] > 1)
    		{   
	    		numa[a[i]]--;
		    	numb[a[i]]--;
    			for(int j = i - 1; j >= 1; j--)
	    		{
		 		    if(a[j] == a[i])
			  	    {
					   break;
				    }    
     				if(numa[a[j]] > 0)
     				{
     					numa[a[j]]--;
     					numb[a[j]]--;
					 }
		    	}
	     	}
    	}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << numb[i] << " ";
	}
	return 0;
}