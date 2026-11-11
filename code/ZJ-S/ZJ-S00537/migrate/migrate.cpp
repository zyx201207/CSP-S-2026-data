#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>d;
		for(int j=0;j<n;j++)
		{
			cin>>x[j];
			int a=x[j]-x[0];
			if(d<a)
			{
				cout<<1<<endl;
				break;
			}
			if(d>=a)
			{
				cout<<0<<endl;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
