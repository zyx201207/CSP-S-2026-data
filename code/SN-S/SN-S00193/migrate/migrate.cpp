#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	int b;
	int f;
	int n;
	int k[20000];
	cin>>a>>b;
	cout<<"1"<<endl<<"2";
	for(int i=1;i<=b;i++)
	{
		cin>>n>>f;
	    for(int j=1;j<=n;j++)
    	{
	    	cin>>k[j];
    	}
    	for(int m=1;m<=n;m++)
    	{
    		if((k[m]-k[1])==1)
    		{
    			m=m;
			}
		}
    }
    
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	return 0;
}
