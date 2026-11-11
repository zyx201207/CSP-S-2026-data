#include<iostream>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate2.in","r",stdin);
	int c,t,n;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,d;
		cin>>n>>d;
		int x;
		cin>>x;
		if(x==2&x==5)
		{
			n+=1;
		}
	}
	cout<<n;
	freopen("migrate.out","w",stdout);
	freopen("migrate2.out","w",stdout);
	return 0;
}
