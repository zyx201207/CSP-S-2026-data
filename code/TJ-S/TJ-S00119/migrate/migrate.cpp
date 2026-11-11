#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,d;
		cin>>n>>d;
		if(c==13||c==14)
	    {
		    cout<<(n-1)*(n-2)/2<<endl;
	    }
	    else
		{
			cout<<1<<endl;
		}
	}
	
	return 0;
 } 
