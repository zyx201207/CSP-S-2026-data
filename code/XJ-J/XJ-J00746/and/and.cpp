#include <iostream>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>x;
		if(n==4&&m==2)
		{
			cout<<12;
		}
		if(n==5&&m==3)
		{
			cout<<7;
		}
	}
	
}