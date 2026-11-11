//王浩杨 西安铁一中滨河高级中学 SN-S00355
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,mn;
	int ans=0;
	cin >> n >> m;
	long long a[n+5];
	for (int q=1;q<=n;q++)
	{
		cin >> a[q];
	}
	for (int j=1;j<=m;j++)
	{
		for (int i=1;i<=n;i++)
	    {
	    	mn=a[1];
	    	if (a[i]<mn)
	    	{
	    		mn=a[i];			
	    	}		
    	}
    	for (int w=1;w<=n;w++)
    	{
    		if (a[w]==mn)
    		{
    			a[w]+=1;
			}
			break;
		}
	} 
	mn+=1;
	for (int c=1;c<=n;c++)
	{
		if (a[c]==mn)
		{
			ans+=1;
		}
	}
	cout << ans;
	return 0;
}
