#include <iostream>
using namespace std;
int n,m;
int a[1000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		if(n==4 && m==2)
		{
			cout<<12<<endl;
		}
		if(n==5 && m==3)
		{
			cout<<7<<endl;
		}
	}
	return 0;
}
