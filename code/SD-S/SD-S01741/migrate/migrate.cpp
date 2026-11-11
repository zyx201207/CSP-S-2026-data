#include<iostream>
using namespace std;
long long d,sum;
int c,t,n;
long long a[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n>>d;
		sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]+d<a[i+3]&&a[i]+d>=a[i+2]&&a[i+1]+d>=a[i+3])
			{
				sum+=1;
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
