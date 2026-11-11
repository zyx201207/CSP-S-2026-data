#include <bits/stdc++.h>
using namespace std;
int a[1000][1000],n,z[1000],m,sum=0	; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	
	    cin>>z[i];
    }
    for(int i=1;i<=m;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		a[i][j]=z[i];
    		if(j>1)
    		{
    			sum=max(a[i][j],a[i][j-1]+z[i]);
			}
		}
		cout<<sum;
	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}
