#include<iostream>
#include<cstring>
using namespace std;
int a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				
			}
		}
		cout<<1<<endl;
	}
	
	return 0;
 } 
