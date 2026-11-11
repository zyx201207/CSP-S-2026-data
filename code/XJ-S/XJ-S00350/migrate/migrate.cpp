#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int I=0;I<=c;I++)
	{
		for(int z=0;z<t;z++)
		{
			int n,d;
			cin>>n>>d;
			int x[n],flag=1;
			for(int i=0;i<n;i++)
			{
				cin>>x[i];
				if(i>1)
				{
					if(x[i]-x[i-1]!=x[i-1]-x[i-2])
					{
						flag=0;
					}
				}
			}
			if(flag)
			{
				cout<<n-3;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
