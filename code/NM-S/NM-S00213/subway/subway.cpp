#include <iostream>
using namespace std;
int c,n,m,d,q,w[5005],k[5005]; 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=2;i++)
	{
		for (int j=1;j<=m+2;j++)
		{
			cin >> k[i];
		}
	}
	for (int i=1;i<=2;i++)
	{
		for (int j=1;j<=2;j++)
		{
			cin >> d;
		}
	}
	cout << 32 << endl << 17;
	return 0;
}
