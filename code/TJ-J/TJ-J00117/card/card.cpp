#include <bits/stdc++.h>
using namespace std;
int a[500005],out[300005],lie[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	
	for (int i = 1;i <= n;i++)
	{
		for (int y = 0;y <= 300003;y++)
		{
			lie[i] = 0;
		}
		
		int nowon = 0;
		
		for (int j = i;j <= n;j++)
    	{
    		bool isin = 0;
	    	for(int q = 1;q <= nowon;q++)
	       	{
	        	if (lie[q] == a[j])
	        	{
	            	lie[q] = a[j];
	            	nowon = q;
	            	isin = 1;
	            	break;
	            }
			}
			if (isin == 0)
			{
				nowon++;
	            lie[nowon] = a[j];
			}
			
			/*
			for (int k = 1;k <= nowon;k++)
           	{
	            cout << lie[k] << " ";
	        }
	        cout << endl << endl;
	        */
    	}
    	/*
    	for (int k = 1;k <= nowon;k++)
        {
	        cout << lie[k] << " ";
	    }
	    cout << endl;
	    cout << endl;
    	*/
    	for (int y = 1;y <= nowon;y++)
		{
			out[lie[y]] ++;
		}
		/*
		for (int k = 1;k <= m;k++)
    	{
	    	cout << out[k] << " ";
    	}
    	cout << endl;
    	*/
	}
	
	for (int i = 1;i <= m;i++)
	{
		cout << out[i] << " ";
	}
	
	return 0;
}
